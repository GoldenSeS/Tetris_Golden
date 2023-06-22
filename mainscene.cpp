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

    this->setWindowTitle(QString("主页面"));
    this->setFixedSize(800,1000);

    ui->introBtn->setIcon(QIcon(":/intro_Iron.png"));
    ui->introBtn->setIconSize(QSize(60,60));

    connect(ui->introBtn,&QPushButton::clicked,[=](){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Introduction");
        msgBox.setText("俄罗斯方块是一款益智类游戏，最初由俄罗斯工程师Alexey Pajitnov于1984年在苏联开发。\n游戏界面由一个矩形框组成，下落的方块由四个小方块组成，玩家需要旋转和移动方块以使其拼接成完整的行，得分会随着消除的行数增加而逐渐提高。\n开发者：陈金海");
        msgBox.setFont(QFont("等线", 16));
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    });

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
        loadScenePtr->grabKeyboard();
        loadScenePtr->move(this->pos());
        loadScenePtr->showRenderScene();
        loadScenePtr->show();
        this->hide();
    });

    connect(loadScenePtr,&LoadGameScene::okSelectSignal,[=](int id){
        qDebug()<<"选择存档场景点击加载游戏";
        loadScenePtr->hide();
        gameScenePtr->move(loadScenePtr->pos());
        gameScenePtr->show();
        gameScenePtr->setRestartGameRecordId(id);
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

