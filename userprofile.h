#ifndef USERPROFILE_H
#define USERPROFILE_H
#include <QDateTime>
#include <QString>
#include <QVector>
#include "checkerboard.h"
#include "block.h"

struct Record
{
    int record_id;
    QDateTime record_time;
    CheckerBoard record_checkerboard;
    Block* record_present_block;
    Block* record_next_block;
    int record_score;
    bool record_isGameOver;
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
    void addRecord(int id, QDateTime time, CheckerBoard checkerboard, Block* present_block, Block* next_block, int score, bool isGameOver);
    QVector<Record> getRecordList() const;
    void clearRecordList();
    void deleteRecord(int index);
private:
    int user_id;
    QString user_name;
    QVector<Record> recordList;
};

#endif // USERPROFILE_H
