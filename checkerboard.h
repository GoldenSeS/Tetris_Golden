#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H
#include "database.h"
#include "block.h"
#include <QPoint>
#include <QVector>

class CheckerBoard
{
public:
    CheckerBoard();
    //棋盘大小初始化
    void init();

    //设置方块
    void setBlock(Block block);

    //设置固定方块
    void setFixedBlock(Block block);

    //获取棋盘数组
    QVector<QVector<int>> getCheckerBoardArray() const;

    //获取单行数据
    QVector<int> getCheckerBoardLine(int lineNum) const;

    //设置单行数据
    void setCheckerBoardLine(QVector<int>,int lineNum);

    //debug棋盘数据
    void debugCheckerBoard();

    //清除棋盘非固定块
    void clearMovingBlock();

    //完全清除棋盘
    void clearCheckerBoard();

    //获取最高固定块的所在行数
    int getHighestFixedBlock() const;

    //设置棋盘数组
    void setCheckerBoardArray(QVector<QVector<int>> CheckerBoardArray);
private:
    QVector<QVector<int>> CheckerBoardArray;
};

#endif // CHECKERBOARD_H
