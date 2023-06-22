#include "userprofile.h"
#include <algorithm>
#include <QDebug>
UserProfile::UserProfile(int id, QString name)
{
    user_id = id;
    user_name = name;
}

UserProfile::~UserProfile()
{
    recordList.clear();
}

void UserProfile::setUserId(int id)
{
    user_id = id;
}

void UserProfile::setUserName(QString name)
{
    user_name = name;
}

int UserProfile::getUserId() const
{
    return user_id;
}

QString UserProfile::getUserName() const
{
    return user_name;
}

void UserProfile::addRecord(Record record)
{
    recordList.push_back(record);
}

QVector<Record> UserProfile::getRecordList() const
{
    return recordList;
}

void UserProfile::clearRecordList()
{
    recordList.clear();
}

void UserProfile::deleteRecord(int index)
{
    recordList.remove(index);
}

void UserProfile::addRecord(int id, QDateTime time, CheckerBoard checkerboard,int gameSpeed, int present_block, int next_block, int score, bool isGameOver)
{
    Record record;
    record.id = id;
    record.time = time;
    record.gameSpeed=gameSpeed;
    record.checkerboard = checkerboard;
    record.present_block = present_block;
    record.next_block = next_block;
    record.score = score;
    record.isGameOver = isGameOver;
    recordList.push_back(record);
}

int UserProfile::getProfilePTT() const{
    int count = 0;
    int PTT=0;
    for (auto it = recordList.rbegin(); it != recordList.rend() && count < 30; ++it, ++count) {
        auto ckarr = it->checkerboard.getCheckerBoardArray();
        int height = ckarr.size();
        int width = ckarr[0].size();
        PTT+=(it->score+100)*(170-it->gameSpeed)*width*width/height;
    }
    return PTT;
}

void UserProfile::setRecordList(QVector<Record> recordList)
{
    this->recordList = recordList;
}
