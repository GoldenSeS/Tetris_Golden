#include "mainscene.h"
#include "ui_mainscene.h"

#include <QDebug>
#include <QPushButton>
#include <QDesktopWidget>
#include <QMessageBox>
mainscene::mainscene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainscene)
{
    ui->setupUi(this);

    fm.loadProfilesFromFile(FILEPATH);
    fm.debugProfilesOutput();

    this->setWindowTitle(QString("TetrisMainScene"));
    this->setFixedSize(800,1000);

    //窗口放置在屏幕正中央
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);

    //游戏场景指针
    gameScenePtr = new GameScene;

    //设置场景指针
    settingScenePtr = new SettingScene;

    //读档场景指针
    loadScenePtr = new LoadGameScene;

    connect(ui->startGameBtn,&QPushButton::clicked,this,[=](){
        qDebug()<<"主场景点击开始游戏";
        gameScenePtr->move(this->pos());
        gameScenePtr->show();
        this->hide();
    });

    connect(ui->settingBtn,&QPushButton::clicked,this,[=](){
        qDebug()<<"主场景点击开始新游戏";
        settingScenePtr->move(this->pos());
        settingScenePtr->show();
        this->hide();
    });

    connect(ui->loadGameBtn,&QPushButton::clicked,this,[=](){
        qDebug()<<"主场景点击加载游戏";
        if(fm.getUserProfile(USER_ID)->getRecordList().empty()){
            QMessageBox::critical(this,"错误","存档为空");
            return;
        }
        emit enterLoadGameScene();
        loadScenePtr->move(this->pos());
        loadScenePtr->showRenderScene();
        loadScenePtr->show();
        this->hide();
    });

    connect(ui->exitBtn,&QPushButton::clicked,this,[=](){
        qDebug()<<"主场景点击退出游戏";
        this->close();
    });
    connect(gameScenePtr,&GameScene::gameSceneBack,this,[=](){
        qDebug()<<"游戏场景点击返回按钮";
        this->move(gameScenePtr->pos());
        gameScenePtr->hide();
        this->show();
    });
    connect(settingScenePtr,&SettingScene::settingSceneBack,this,[=](){
        qDebug()<<"设置场景点击返回按钮";
        this->move(settingScenePtr->pos());
        settingScenePtr->hide();
        this->show();
    });
    connect(loadScenePtr,&LoadGameScene::loadSceneBack,this,[=](){
        qDebug()<<"读档场景点击返回按钮";
        this->move(loadScenePtr->pos());
        loadScenePtr->hide();
        this->show();
    });

}

mainscene::~mainscene()
{
    delete ui;
}

