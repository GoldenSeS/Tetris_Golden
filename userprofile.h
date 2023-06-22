#ifndef USERPROFILE_H
#define USERPROFILE_H
#include <QDateTime>
#include <QString>
#include <QVector>
#include "checkerboard.h"
#include "block.h"

struct Record
{
    //记录编号与时间
    int id;
    QDateTime time;

    //游戏棋盘
    CheckerBoard checkerboard;
    int gameSpeed;

    //当前和下一个方块
    int present_block;
    int next_block;

    //游戏分数与是否结束
    int score;
    bool isGameOver;
};

class UserProfile
{
public:
    UserProfile(int id=0, QString name="Unknown");
    ~UserProfile();
    void setUserId(int id);
    void setUserName(QString name);
    void setRecordList(QVector<Record> recordList);
    int getUserId() const;
    QString getUserName() const;
    void addRecord(Record record);
    void addRecord(int id, QDateTime time, CheckerBoard checkerboard, int gameSpeed, int present_block, int next_block, int score, bool isGameOver);
    QVector<Record> getRecordList() const;
    void clearRecordList();
    void deleteRecord(int index);
    int getProfilePTT() const;
private:
    int user_id;
    QString user_name;
    QVector<Record> recordList;
};

#endif // USERPROFILE_H
