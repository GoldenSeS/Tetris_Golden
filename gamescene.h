#ifndef GAMESCENE_H
#define GAMESCENE_H
#include <QWidget>
#include <QGraphicsView>
#include "checkerboard.h"
#include <QKeyEvent>
#include "block.h"
#include "QList"
#include <QTimer>
#include <QTimerEvent>
#include <QTime>
#include "gamemanager.h"
#include "profilemanager.h"
#include "profile.h"
namespace Ui {
class GameScene;
}

class GameScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    ~GameScene();
    // 渲染游戏场景
    void render();
    // 渲染下一个块场景
    void nextBlk_render();

    // 单步处理
    void singleStepHandle();

private:
    Ui::GameScene *ui;

    // 游戏视图
    QGraphicsView* gameView;
    // 游戏场景
    QGraphicsScene* gameGraphicScene;

    // 下一个块视图
    QGraphicsView* nextBlkView;
    // 下一个块场景
    QGraphicsScene* nextBlkGraphicScene;

    // 游戏棋盘
    CheckerBoard checkerboard;

    //重写键盘事件处理函数
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    //重写时间事件函数
    void timerEvent(QTimerEvent* event) override;
    int timerId;
    int timerCnt;

    //游戏得分
    int score;

    //游戏状态参数
    int isStart;
    int game_width;
    int game_height;
    int game_speed;

    //判断游戏当前是否结束
    bool isGameOver;

    //方块列表
    QList<Block*> blocklist;
    Block present_block;
    Block next_block;

    //游戏管理类
    GameManager gm;

    //获取当前状态记录
    Record getCurrentRecord();

    //方块初始化
    void blockInit();
signals:
    //写一个自定义信号 告诉主场景 点击了返回
    void gameSceneBack();
};

#endif // GAMESCENE_H
