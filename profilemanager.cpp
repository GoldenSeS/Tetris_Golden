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
            qDebug()<<" 记录"<<j.id<<j.time;
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
            QVector<QVector<int>> checkerboard = profile->getRecordList().at(0).checkerboard.getCheckerBoardArray();
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
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
    QJsonArray jsonArray = jsonDoc.array();
    for (int i = 0; i < jsonArray.size(); i++) {
        QJsonObject jsonObject = jsonArray.at(i).toObject();
        int id = jsonObject.value("id").toInt();
        QString name = jsonObject.value("name").toString();
        //将Json格式的棋盘数据转换为棋盘对象
        QJsonArray checkerboardArray = jsonObject.value("checkerboard").toArray();
        QVector<QVector<int>> checkerboard;
        for (int i = 0; i < checkerboardArray.size(); i++) {
            QJsonArray lineArray = checkerboardArray.at(i).toArray();
            QVector<int> line;
            for (int j = 0; j < lineArray.size(); j++) {
                line.append(lineArray.at(j).toInt());
            }
            checkerboard.append(line);
        }
        UserProfile* profile = new UserProfile(id, name);
        Record record;
        record.checkerboard.setCheckerBoardArray(checkerboard);
        profile->addRecord(record);
        userProfiles.insert(id, profile);
    }
}
