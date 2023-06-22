#include "rankingsscene.h"
#include "ui_rankingsscene.h"

RankingsScene::RankingsScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankingsScene)
{
    ui->setupUi(this);
    this->setWindowTitle("排行榜");

    ui->nameLabel->setWordWrap(true);
    ui->nameLabel_2->setWordWrap(true);
    ui->nameLabel_3->setWordWrap(true);
    ui->nameLabel_4->setWordWrap(true);

    connect(ui->backBtn,&QPushButton::clicked,[=](){
        emit rankingSceneBack();
    });
}

void RankingsScene::updateRankings(){

    ui->rankwidget_2->setVisible(false);
    ui->rankwidget_3->setVisible(false);
    ui->rankwidget_4->setVisible(false);

    QVector<rankData> rankDataList = getRankDataList();
    int num = rankDataList.size();
    rankData data = rankDataList.at(0);
    ui->nameLabel->setText(data.name);
    ui->scoreLabel->setNum(data.score);
    ui->timeLabel->setText(data.time);
    if(num>=2){
        ui->rankwidget_2->setVisible(true);
        data = rankDataList.at(1);
        ui->nameLabel_2->setText(data.name);
        ui->scoreLabel_2->setNum(data.score);
        ui->timeLabel_2->setText(data.time);
    }
    if(num>=3){
        ui->rankwidget_3->setVisible(true);
        data = rankDataList.at(2);
        ui->nameLabel_3->setText(data.name);
        ui->scoreLabel_3->setNum(data.score);
        ui->timeLabel_3->setText(data.time);
    }
    if(num>=4){
        ui->rankwidget_4->setVisible(true);
        data = rankDataList.at(3);
        ui->nameLabel_4->setText(data.name);
        ui->scoreLabel_4->setNum(data.score);
        ui->timeLabel_4->setText(data.time);
    }
}

QVector<rankData> RankingsScene::getRankDataList(){
    QList<UserProfile*> profiles = fm.getAllUserProfiles();

    std::sort(profiles.begin(),profiles.end(),[=](const UserProfile* p1, const UserProfile* p2){
        return p1->getProfilePTT()>p2->getProfilePTT();
    });
    QVector<rankData> tem;
    for(auto profile:profiles){
        if(profile->getRecordList().empty()){
            continue;
        }

        rankData temrank;
        temrank.score=profile->getProfilePTT();
        temrank.name=profile->getUserName();
        temrank.time=profile->getRecordList().rbegin()->time.toString("yyyy-mm-dd");
        tem.append(temrank);
    }
    return tem;
}

RankingsScene::~RankingsScene()
{
    delete ui;
}
