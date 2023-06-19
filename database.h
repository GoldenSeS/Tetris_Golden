#ifndef DATABASE_H
#define DATABASE_H
#include <QColor>
#include <QString>

//游戏网格大小
extern int GAME_WIDTH;
extern int GAME_HEIGHT;
//方块颜色
extern QColor blockcolor[10];
//每次下落时间
extern int BLOCK_DESCENT_TIME;
//屏幕刷新时间
extern int REFRESHING_RATE;
//方块延迟下落时间
extern int DELAY_DESCENT;
//媒体播放路径
extern QString MEDIAFILE;
//媒体音量大小
extern int MEDIAVOLUME;
//键位设置
extern Qt::Key KEYSETTING[5];

//当前用户ID
extern int USER_ID;

void debugDatabase();

#endif // DATABASE_H
