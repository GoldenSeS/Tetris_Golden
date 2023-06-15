#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "checkerboard.h"
#include "block.h"

class GameManager
{
public:
    GameManager();
    //重启游戏
    void gameRestart(CheckerBoard &board,Block &present_blk,Block &next_blk,const QList<Block*> &blocklist);
    //获取随机方块
    Block* get_random_block(const QList<Block*> &blocklist);

    //判断是否能够下降
    bool canMoveDown(const CheckerBoard &board,const Block &present_blk) const;

    //判断是否能够往左
    bool canMoveLeft(const CheckerBoard &board,const Block &present_blk) const;

    //判断是否能够往右
    bool canMoveRight(const CheckerBoard &board,const Block &present_blk) const;

    //判断是否能够旋转到下一状态
    bool canRolate(const CheckerBoard &board,const Block &present_blk) const;

    //获取能够消除的行数
    QList<int> canLineElimination(const CheckerBoard &board) const;

    //消除一定行数的固定块
    void eliminateLine(CheckerBoard &board,const QList <int> &lineList);
};

#endif // GAMEMANAGER_H
