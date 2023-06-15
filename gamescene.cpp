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

    testProfile = new UserProfile;
    testProfile->setUserId(1);
    testProfile->setUserName("golden");

    ui->pauseLabel->setVisible(false);
    ui->pauseLabel->setStyleSheet("color: rgba(0, 0, 0, 128);");
    //游戏状态初始化
    isStart=-1;
    //分数初始化
    score = 0;
    //随机数模块初始化
    qsrand(QTime::currentTime().msec());

    this->setFixedSize(800,1000);
    this->setWindowTitle("TetrisGameScene");

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

        game_width = GAME_WIDTH;
        game_height = GAME_HEIGHT;
        game_speed = 170 - REFRESHING_RATE;

        //初始化时间参数
        timerId = startTimer(game_speed);
        timerCnt = DELAY_DESCENT;

        ui->restart_btn->setText("重启");
        isStart=1;
        score=0;
        ui->scoreLCD->display(0);
        qDebug()<<"游戏界面点击重启按钮";
        ui->pauseLabel->setVisible(false);
        gm.gameRestart(checkerboard,present_block,next_block,blocklist);
        checkerboard.setBlock(present_block);
        render();
        nextBlk_render();
    });

    // 设置返回按钮
    connect(ui->backBtn,&QPushButton::clicked,this,[=](){
        ui->restart_btn->setText("开始");
        isStart=-1;
        score=0;
        ui->scoreLCD->display(0);
        qDebug()<<"游戏界面点击返回按钮";
        ui->pauseLabel->setVisible(false);
        gm.gameRestart(checkerboard,present_block,next_block,blocklist);
        checkerboard.clearCheckerBoard();
        nextBlkGraphicScene->clear();
        render();
        fm.addUserProfile(testProfile);
        fm.saveProfilesToFile("test.json");
        emit gameSceneBack();
    });

    connect(ui->save_btn,&QPushButton::clicked,this,[=](){
        QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
        Block* present_block_ptr = &present_block;
        Block* next_block_ptr = &next_block;
        testProfile->addRecord(1,QDateTime::currentDateTime(),checkerboard,present_block_ptr,next_block_ptr,score,true);
        qDebug()<<"存档成功";
    });

    //初始化方块
    present_block = *gm.get_random_block(blocklist);
    next_block = *gm.get_random_block(blocklist);

}
void GameScene::blockInit(){
    // 初始化方块
    BlockL* blockL_ptr = new BlockL;
    BlockO* blockO_ptr = new BlockO;
    BlockJ* blockJ_ptr = new BlockJ;
    BlockI* blockI_ptr = new BlockI;
    BlockT* blockT_ptr = new BlockT;
    BlockS* blockS_ptr = new BlockS;
    BlockZ* blockZ_ptr = new BlockZ;
    // 方块列表初始化
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