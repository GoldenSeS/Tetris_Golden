#include "userprofile.h"

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

void UserProfile::addRecord(int id, QDateTime time, CheckerBoard checkerboard, Block* present_block, Block* next_block, int score, bool isGameOver)
{
    Record record;
    record.record_id = id;
    record.record_time = time;
    record.record_checkerboard = checkerboard;
    record.record_present_block = present_block;
    record.record_next_block = next_block;
    record.record_score = score;
    record.record_isGameOver = isGameOver;
    recordList.push_back(record);
}

void UserProfile::setRecordList(QVector<Record> recordList)
{
    this->recordList = recordList;
}
