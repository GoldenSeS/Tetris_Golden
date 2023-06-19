#include "database.h"
#include "profilemanager.h"
#include <QDebug>
int GAME_WIDTH = 10;

int GAME_HEIGHT = 20;

QColor blockcolor[10]={
    Qt::white,//空棋盘颜色
    QColor("#3795D9"),//方块1颜色
    QColor("#F0CA2E"),//方块2颜色
    QColor("#88258B"),//方块3颜色
    QColor("#F56816"),//方块4颜色
    QColor("#2A51B6"),//方块5颜色
    QColor("#61B532"),//方块6颜色
    QColor("#BE1D23"),//方块7颜色
    Qt::white,
    Qt::gray//固定方块颜色
};

int REFRESHING_RATE=100;
int DELAY_DESCENT=10;
QString MEDIAFILE="";
int MEDIAVOLUME=50;

Qt::Key KEYSETTING[5]{
    Qt::Key_Left,
    Qt::Key_Right,
    Qt::Key_Down,
    Qt::Key_Up,
    Qt::Key_Escape
}; 

void debugDatabase(){
    qDebug()<<"游戏宽高"<<GAME_WIDTH<<GAME_HEIGHT;
    qDebug()<<"当前用户ID"<<USER_ID;
}

int USER_ID=0;
