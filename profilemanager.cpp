#include "profilemanager.h"
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

ProfileManager fm;

ProfileManager::ProfileManager() {
}

ProfileManager::~ProfileManager() {
    clearProfiles();
}

void ProfileManager::clearProfiles(){
    // 释放所有用户数据
    for (UserProfile* profile : userProfiles.values()) {
        delete profile;
    }
    userProfiles.clear();
}

void ProfileManager::addRecordFromUserProfileIndex(int index,Record record){
    userProfiles.value(index)->addRecord(record);
}

void ProfileManager::addUserProfile(UserProfile* userProfile) {
    // 检查是否已存在该用户
    if (userProfiles.contains(userProfile->getUserId())) {
        qDebug() << "用户已存在，无法添加";
        return;
    }
    // 添加用户
    userProfiles.insert(userProfile->getUserId(), userProfile);
}

void ProfileManager::removeUserProfile(int userId) {
    // 查找并移除用户
    UserProfile* userProfile = userProfiles.value(userId);
    if (userProfile) {
        userProfiles.remove(userId);
        delete userProfile;
    } else {
        qDebug() << "用户不存在，无法移除";
    }
}

bool ProfileManager::hasUserProfile(int userId) {
    return userProfiles.contains(userId);
}

UserProfile* ProfileManager::getUserProfile(int userId) {
    return userProfiles.value(userId);
}

QList<UserProfile*> ProfileManager::getAllUserProfiles() {
    return userProfiles.values();
}

int ProfileManager::getProfilesNum()const{
    return userProfiles.size();
}

void ProfileManager::debugProfilesOutput(){
    for(auto i:userProfiles){
        qDebug()<<"用户ID:"<<i->getUserId();
        qDebug()<<"用户昵称:"<<i->getUserName();
        for(auto j:i->getRecordList()){
            qDebug()<<"    记录ID"<<j.id;
            qDebug()<<"      *时间"<<j.time.toString();
            qDebug()<<"      *是否结束"<<j.isGameOver<<"      *分数"<<j.score;
            j.checkerboard.debugCheckerBoard();
        }
        qDebug()<<"";
    }
}

void ProfileManager::saveProfilesToFile(const QString& fileName) const {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "无法打开Json文件" << fileName;
        return;
    }
    //用Json格式保存数据
    QJsonArray jsonArray;
    for (UserProfile* profile : userProfiles.values()) {
        QJsonObject jsonObject;
        jsonObject.insert("id", profile->getUserId());
        jsonObject.insert("name", profile->getUserName());
        //记录Record
        QJsonArray recordArray;
        for (Record record : profile->getRecordList()) {
            QJsonObject recordObject;
            recordObject.insert("id", record.id);
            recordObject.insert("time", record.time.toString("yyyy-MM-dd hh:mm:ss"));
            //棋盘数据
            QJsonArray checkerboardArray;
            QVector<QVector<int>> checkerboard = record.checkerboard.getCheckerBoardArray();
            for (int i = 0; i < GAME_HEIGHT; i++) {
                QJsonArray lineArray;
                for (int j = 0; j < GAME_WIDTH; j++) {
                    lineArray.append(checkerboard.at(i).at(j));
                }
                checkerboardArray.append(lineArray);
            }
            recordObject.insert("checkerboard", checkerboardArray);
            //当前方块
            recordObject.insert("presentblock",record.present_block);
            //下一个方块
            recordObject.insert("nextblock",record.next_block);
            //游戏速度
            recordObject.insert("gamespeed",record.gameSpeed);
            //分数
            recordObject.insert("score", record.score);
            //游戏是否结束
            recordObject.insert("isGameOver", record.isGameOver);
            recordArray.append(recordObject);
        }
        jsonObject.insert("record", recordArray);
        jsonArray.append(jsonObject);
    }
    QJsonDocument jsonDoc(jsonArray);
    file.write(jsonDoc.toJson());
    file.close();
}

void ProfileManager::loadProfilesFromFile(const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "无法打开文件" << fileName;
        return;
    }
    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (jsonDoc.isNull()) {
        qDebug() << "Json文件解析失败" << fileName;
        return;
    }
    if (!jsonDoc.isArray()) {
        qDebug() << "Json文件格式错误" << fileName;
        return;
    }
    QJsonArray jsonArray = jsonDoc.array();
    clearProfiles(); // 清空现有的用户配置数据

    for (const QJsonValue& jsonValue : jsonArray) {
        if (!jsonValue.isObject()) {
            qDebug() << "Json文件格式错误" << fileName;
            return;
        }

        QJsonObject jsonObject = jsonValue.toObject();
        int userId = jsonObject.value("id").toInt();
        QString userName = jsonObject.value("name").toString();

        UserProfile* profile = new UserProfile(userId, userName);
        userProfiles.insert(userId, profile);

        QJsonArray recordArray = jsonObject.value("record").toArray();
        for (const QJsonValue& recordValue : recordArray) {
            if (!recordValue.isObject()) {
                qDebug() << "Json文件格式错误" << fileName;
                return;
            }
            QJsonObject recordObject = recordValue.toObject();
            Record record;
            record.id = recordObject.value("id").toInt();
            record.time = QDateTime::fromString(recordObject.value("time").toString(), "yyyy-MM-dd hh:mm:ss");
            // 棋盘数据
            QJsonArray checkerboardArray = recordObject.value("checkerboard").toArray();
            QVector<QVector<int>> checkerboard;
            for (const QJsonValue& lineValue : checkerboardArray) {
                if (!lineValue.isArray()) {
                    qDebug() << "Json文件格式错误" << fileName;
                    return;
                }

                QJsonArray lineArray = lineValue.toArray();
                QVector<int> line;
                for (const QJsonValue& value : lineArray) {
                    if (!value.isDouble()) {
                        qDebug() << "Json文件格式错误" << fileName;
                        return;
                    }
                    line.append(value.toInt());
                }
                checkerboard.append(line);
            }
            record.checkerboard.setCheckerBoardArray(checkerboard);
            // 当前方块
            record.present_block = recordObject.value("presentblock").toInt();
            // 下一个方块
            record.next_block = recordObject.value("nextblock").toInt();
            // 游戏速度
            record.gameSpeed = recordObject.value("gamespeed").toDouble();
            // 分数
            record.score = recordObject.value("score").toInt();
            // 游戏是否结束
            record.isGameOver = recordObject.value("isGameOver").toBool();

            profile->addRecord(record);
        }
    }

    qDebug() << "读取文件成功";

}
