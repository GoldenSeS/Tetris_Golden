#include "gamescene.h"
#include "ui_gamescene.h"
#include <QPushButton>
#include <QGraphicsRectItem>
#include "database.h"
#include <QDebug>
#include <blockL.h>
#include <blockO.h>
#include <blockJ.h>
#include <blockI.h>
#include <blockT.h>
#include <blockS.h>
#include <blockZ.h>
#include <QPainter>
#include <QMessageBox>
#include <QDateTime>
GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene)
{
    // 窗口初始化
    ui->setupUi(this);
    this->setFixedSize(800,1000);
    this->setWindowTitle("游戏界面");
    ui->pauseLabel->setVisible(false);
    ui->pauseLabel->setStyleSheet("color: rgba(0, 0, 0, 128);");

    //游戏状态初始化
    isStart=-1;
    isGameOver=true;
    restartGameRecordId = -1;
    pal = 1;
    //分数初始化
    score = 0;
    //随机数模块初始化
    qsrand(QTime::currentTime().msec());
    //音乐播放器初始化
    mediaPlayer = new QMediaPlayer;
    ui->musicSlider->setRange(0,100);
    ui->musicSlider->setValue(MEDIAVOLUME);
    connect(ui->musicBtn,&QPushButton::clicked,[=](){
        if (mediaPlayer->state() != QMediaPlayer::PlayingState&&MEDIAFILE!="") {
            mediaPlayer->setMedia(QUrl::fromLocalFile(MEDIAFILE));
            mediaPlayer->play();
            ui->musicBtn->setText("暂停");
        } else {
            mediaPlayer->stop();
            ui->musicBtn->setText("播放");
        }
    });
    connect(ui->musicSlider, &QSlider::valueChanged, mediaPlayer, &QMediaPlayer::setVolume);

    // 创建 QGraphicsView 对象
    gameView = ui->gameGraphicsView;
    nextBlkView = ui->nextBlockGraphicsView;

    // 创建 QGraphicsScene 对象并设置给 QGraphicsView
    gameGraphicScene = new QGraphicsScene;
    gameView->setScene(gameGraphicScene);

    nextBlkGraphicScene = new QGraphicsScene;
    nextBlkView->setScene(nextBlkGraphicScene);

    blockInit();

    // 设置重启按钮
    connect(ui->restart_btn,&QPushButton::clicked,this,[=](){
        this->grabKeyboard();
        //初始化游戏参数
        game_width = GAME_WIDTH;
        game_height = GAME_HEIGHT;
        game_speed = 170 - REFRESHING_RATE;
        isGameOver =false;
        //初始化时间参数
        timerId = startTimer(game_speed);
        timerCnt = DELAY_DESCENT;
        blockInit();
        ui->restart_btn->setText("重启");
        isStart=1;
        score=0;
        ui->scoreLCD->display(0);
        qDebug()<<"游戏界面点击重启按钮";
        ui->pauseLabel->setVisible(false);

        if(restartGameRecordId!=-1){
            Record temrecord = fm.getUserProfile(USER_ID)->getRecordList().at(restartGameRecordId);
            CheckerBoard ckb=temrecord.checkerboard;
            auto ckbArray=ckb.getCheckerBoardArray();
            game_height=ckbArray.size();
            game_width=ckbArray[0].size();
            checkerboard.setCheckerBoardArray(ckb.getFixedBlockCheckerBoardArray());
            present_block = *blocklist[temrecord.present_block-1];
            present_block.moveX(game_width/2);
            next_block = *blocklist[temrecord.next_block-1];
            next_block.moveX(game_width/2);
            restartGameRecordId=-1;
        }else{
            gm.gameRestart(checkerboard,present_block,next_block,blocklist);
            checkerboard.setBlock(present_block);
        }
        render();
        nextBlk_render();
    });

    // 设置返回按钮
    connect(ui->backBtn,&QPushButton::clicked,this,[=](){
        mediaPlayer->stop();
        ui->musicBtn->setText("播放");
        ui->restart_btn->setText("开始");
        if(isStart==1){
            isStart=-1;
            QMessageBox::StandardButton saveBox;
            saveBox=QMessageBox::question(this, "保存", "是否保存当前记录", QMessageBox::Yes|QMessageBox::No);
            if(saveBox==QMessageBox::Yes){
                fm.addRecordFromUserProfileIndex(USER_ID,getCurrentRecord());
                fm.saveProfilesToFile(FILEPATH);
                fm.debugProfilesOutput();
            }
        }
        isStart=-1;
        score=0;
        ui->scoreLCD->display(0);
        ui->pauseLabel->setVisible(false);
        gm.gameRestart(checkerboard,present_block,next_block,blocklist);
        checkerboard.clearCheckerBoard();
        nextBlkGraphicScene->clear();
        gameGraphicScene->clear();
        emit gameSceneBack();
    });
    //初始化方块
    present_block = *gm.get_random_block(blocklist);
    next_block = *gm.get_random_block(blocklist);

}

void GameScene::changePal(){
    if(pal==1){
        ui->gameGraphicsView->setStyleSheet("background-color: rgb(64, 66, 68);");
        ui->nextBlockGraphicsView->setStyleSheet("background-color: rgb(64, 66, 68);");
        blockcolor[0]=QColor(64, 66, 68);
        blockcolor[9]=Qt::lightGray;
    }else{
        ui->gameGraphicsView->setStyleSheet("background-color: white");
        ui->nextBlockGraphicsView->setStyleSheet("background-color: white");
        blockcolor[0]=Qt::white;
        blockcolor[9]=Qt::gray;
    }
    pal*=-1;
}

void GameScene::setRestartGameRecordId(int id){
    this->restartGameRecordId=id;
}

Record GameScene::getCurrentRecord(){
    Record tempRecord;
    tempRecord.id=fm.getUserProfile(USER_ID)->getRecordList().size();
    tempRecord.time=QDateTime::currentDateTime();
    tempRecord.score=score;
    tempRecord.gameSpeed=game_speed;
    tempRecord.isGameOver=isGameOver;
    tempRecord.next_block=next_block.get_color();
    tempRecord.present_block=present_block.get_color();
    tempRecord.checkerboard=checkerboard;
    return tempRecord;
}

void GameScene::blockInit(){
    blocklist.clear();
    // 初始化方块
    BlockL* blockL_ptr = new BlockL;
    BlockO* blockO_ptr = new BlockO;
    BlockJ* blockJ_ptr = new BlockJ;
    BlockI* blockI_ptr = new BlockI;
    BlockT* blockT_ptr = new BlockT;
    BlockS* blockS_ptr = new BlockS;
    BlockZ* blockZ_ptr = new BlockZ;
    // 方块列表初始化 "L","O","J","I","T","S","Z"
    blocklist.append(blockL_ptr);
    blocklist.append(blockO_ptr);
    blocklist.append(blockJ_ptr);
    blocklist.append(blockI_ptr);
    blocklist.append(blockT_ptr);
    blocklist.append(blockS_ptr);
    blocklist.append(blockZ_ptr);
}
void GameScene::timerEvent(QTimerEvent* event)
{
    if(isStart!=1)
    {
        return;
    }
    static int tm = 0;
    if(event->timerId() != timerId)
        return;
    tm++;
    if(tm < timerCnt)
    {
        return;
    }
    else {
        tm = 0;
    }
    if(gm.canMoveDown(checkerboard,present_block))
        present_block.move_down();
    singleStepHandle();
}
void GameScene::keyPressEvent(QKeyEvent *event)
{
    if(isStart==0){
        if(event->key()==KEYSETTING[4]){
            qDebug()<<"游戏开始";
            ui->pauseLabel->setVisible(false);
            isStart=1;
        }else{
            return;
        }
    }else if(isStart==1){
        if(event->key()==KEYSETTING[4]){
            qDebug()<<"游戏暂停";
            ui->pauseLabel->setVisible(true);
            isStart=0;
        }
    }else{
        return;
    }
    short operation = 0;
    // 处理按键事件
    if (event->key() == KEYSETTING[0])
    {
        operation=1;
    }
    else if (event->key() == KEYSETTING[1])
    {
        operation=2;
    }
    else if (event->key() == KEYSETTING[2])
    {
        operation=3;
    }
    else if (event->key() == KEYSETTING[3])
    {
        operation=4;
    }
    // 调用基类的键盘事件处理函数，以确保其他键盘事件正常处理
    QWidget::keyPressEvent(event);

    switch (operation) {
    case 1:
    {
        // 左移操作
        if(gm.canMoveLeft(checkerboard,present_block))
            present_block.move_left();
        break;
    }
    case 2:
    {
        // 右移操作
        if(gm.canMoveRight(checkerboard,present_block))
            present_block.move_right();
        break;
    }
    case 3:
    {
        // 下移加速操作
        timerCnt=1;
        break;
    }
    case 4:
    {
        // 旋转操作
        if(gm.canRolate(checkerboard,present_block))
            present_block.status_forward();
        break;
    }
    default:
        break;
    }
    singleStepHandle();
}
void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == KEYSETTING[2])
    {
        timerCnt=DELAY_DESCENT;
    }
}
void GameScene::singleStepHandle(){
    //获取最高固定块
    const int highestNum=checkerboard.getHighestFixedBlock();
    if(highestNum<2){
        isStart=-1;
        isGameOver=true;
        fm.addRecordFromUserProfileIndex(USER_ID,getCurrentRecord());
        fm.saveProfilesToFile(FILEPATH);
        fm.debugProfilesOutput();
        QMessageBox msgBox;
        msgBox.setText(QString("游戏结束！您的分数为：%1").arg(QString::number(score)));
        msgBox.exec();
    }
    //获取能消除的行数
    QList<int> lineList=gm.canLineElimination(checkerboard);
    //消除行数
    gm.eliminateLine(checkerboard,lineList);
    //根据消除的行数加分
    score+=5*lineList.count()*(lineList.count()+1);
    ui->scoreLCD->display(score);
    checkerboard.clearMovingBlock();
    if(gm.canMoveDown(checkerboard,present_block)){
        checkerboard.setBlock(present_block);
    }
    else{
        checkerboard.setFixedBlock(present_block);
        present_block=next_block;
        next_block=*gm.get_random_block(blocklist);
    }
    render();
    nextBlk_render();
}
void GameScene::render()
{
    gameGraphicScene->clear();

    // 计算网格方块的大小和间距
    const short blockSize = 30;
    const short spacing = 1;

    // 绘制网格
    for (int row = 0; row < game_height; ++row) {
        for (int col = 0; col < game_width; ++col) {
            // 创建方块项
            QGraphicsRectItem* blockItem = new QGraphicsRectItem;
            if(pal==-1){
                blockItem->setPen(QPen(Qt::white));
            }else{
                blockItem->setPen(QPen(Qt::black));
            }

            // 设置方块项的位置和尺寸
            int x = col * (blockSize + spacing);
            int y = row * (blockSize + spacing);
            blockItem->setRect(x, y, blockSize, blockSize);

            int blockIndex = checkerboard.getCheckerBoardArray()[row][col];

            if (blockIndex >= 0 && blockIndex < 10)
                blockItem->setBrush(QBrush(blockcolor[blockIndex]));

            // 添加方块项到场景中
            gameGraphicScene->addItem(blockItem);

        }
    }
    // 绘制警戒线
    int redLineY = 1 * (blockSize + spacing) + blockSize;
    QGraphicsLineItem* redLineItem = new QGraphicsLineItem(0, redLineY, game_width * (blockSize + spacing), redLineY);
    QPen linePen;
    if(checkerboard.getHighestFixedBlock()<7)
        linePen.setColor(Qt::red);
    else
        linePen.setColor(Qt::darkRed);
    linePen.setWidth(3);
    redLineItem->setPen(linePen);
    gameGraphicScene->addItem(redLineItem);
}
void GameScene::nextBlk_render(){
    nextBlkGraphicScene->clear();

    // 计算网格方块的大小和间距
    const short blockSize = 30;
    const short spacing = 1;

    // 绘制网格
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 5; ++col) {
            // 创建方块项
            QGraphicsRectItem* blockItem = new QGraphicsRectItem;

            if(pal==-1){
                blockItem->setPen(QPen(Qt::white));
            }else{
                blockItem->setPen(QPen(Qt::black));
            }

            // 设置方块项的位置和尺寸
            int x = col * (blockSize + spacing);
            int y = row * (blockSize + spacing);
            blockItem->setRect(x, y, blockSize, blockSize);

            bool needPaint=false;
            for(QPoint i:next_block.get_init_block_pos()){
                if(i==QPoint(row-2,col-2)){
                    needPaint=true;
                    break;
                }
            }
            if(needPaint==true)
                blockItem->setBrush(QBrush(blockcolor[next_block.get_color()]));
            // 添加方块项到场景中
            nextBlkGraphicScene->addItem(blockItem);
        }
    }
}

GameScene::~GameScene()
{
    delete ui;
}
