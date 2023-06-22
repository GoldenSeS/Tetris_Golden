#ifndef RANKINGSSCENE_H
#define RANKINGSSCENE_H

#include <QWidget>
#include <QVector>
#include <QString>
#include "profilemanager.h"

struct rankData{
    QString name="";
    int score=0;
    QString time="";
};

namespace Ui {
class RankingsScene;
}

class RankingsScene : public QWidget
{
    Q_OBJECT

public:
    explicit RankingsScene(QWidget *parent = nullptr);
    ~RankingsScene();
    void updateRankings();
private:
    QVector<rankData> getRankDataList();
    Ui::RankingsScene *ui;
signals:
    void rankingSceneBack();
};

#endif // RANKINGSSCENE_H
