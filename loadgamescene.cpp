#include "loadgamescene.h"
#include "ui_loadgamescene.h"
#include "mainscene.h"
#include <QDebug>
#include <QGraphicsItem>
#include <QPen>

LoadGameScene::LoadGameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadGameScene)
{
    ui->setupUi(this);
    this->setWindowTitle("LoadGameScene");
    gameGraphicScene = new QGraphicsScene;
    ui->gameGraphicsView->setScene(gameGraphicScene);
    ui->timeLabel->setWordWrap(true);
    recordId = fm.getUserProfile(USER_ID)->getRecordList().size()-1;

    connect(ui->backBtn,&QPushButton::clicked,[=](){
        emit loadSceneBack();
    });

    connect(ui->leftBtn,&QPushButton::clicked,this,[=](){
        leftSelect();
    });

    connect(ui->rightBtn,&QPushButton::clicked,this,[=](){
        rightSelect();
    });

    connect(ui->okBtn,&QPushButton::clicked,this,[=](){
        okSelect();
    });
}

void LoadGameScene::leftSelect(){
    if(recordId>0){
        recordId--;
    }
    showRenderScene();
}
void LoadGameScene::rightSelect(){
    if(recordId<fm.getUserProfile(USER_ID)->getRecordList().size()-1){
        recordId++;
    }
    showRenderScene();
}
void LoadGameScene::okSelect(){
    qDebug()<<"存档已选定";
    emit okSelectSignal(recordId);
}
void LoadGameScene::keyPressEvent(QKeyEvent *event){
    if (event->key() == KEYSETTING[0])
    {
        leftSelect();
    }
    else if (event->key() == KEYSETTING[1])
    {
        rightSelect();
    }
    else if (event->key() == Qt::Key_Return)
    {
        okSelect();
    }
    QWidget::keyPressEvent(event);
}

void LoadGameScene::showRenderScene(){
    UserProfile* currentProfile = fm.getUserProfile(USER_ID);
    int maxsize = currentProfile->getRecordList().size()-1;
    if(recordId>maxsize){
        recordId=maxsize;
    }
    Record currentRecord = currentProfile->getRecordList().at(recordId);
    render(currentRecord.checkerboard);

    ui->IdLabel->setNum(currentRecord.id);
    ui->timeLabel->setText(currentRecord.time.toString("yyyy-MM-dd hh:mm:ss"));
    ui->scoreLabel->setNum(currentRecord.score);
    ui->speedLabel->setNum(currentRecord.gameSpeed);
    ui->userLabel->setText("当前用户："+fm.getUserProfile(USER_ID)->getUserName());
    ui->endLabel->setVisible(currentRecord.isGameOver);
    ui->okBtn->setEnabled(!currentRecord.isGameOver);
//    qDebug()<<recordId;
}

void LoadGameScene::render(CheckerBoard checkerboard)
{
    int height = checkerboard.getCheckerBoardArray().size();
    int width = checkerboard.getCheckerBoardArray()[0].size();
    gameGraphicScene->clear();

    // 计算网格方块的大小和间距
    const short blockSize = 20;
    const short spacing = 1;

    // 绘制网格
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; ++col) {
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
    QGraphicsLineItem* redLineItem = new QGraphicsLineItem(0, redLineY, width * (blockSize + spacing), redLineY);
    QPen linePen;
    if(checkerboard.getHighestFixedBlock()<7)
        linePen.setColor(Qt::red);
    else
        linePen.setColor(Qt::darkRed);
    linePen.setWidth(3);
    redLineItem->setPen(linePen);
    gameGraphicScene->addItem(redLineItem);
}

LoadGameScene::~LoadGameScene()
{
    delete ui;
}
