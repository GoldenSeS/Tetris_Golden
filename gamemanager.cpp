#include "gamemanager.h"
#include <QTime>
GameManager::GameManager()
{
    qsrand(QTime::currentTime().msec());
}

void GameManager::gameRestart(CheckerBoard &board,Block &present_blk,Block &next_blk,const QList<Block*> &blocklist){
    board.clearCheckerBoard();
    board.init();
    present_blk = *get_random_block(blocklist);
    next_blk = *get_random_block(blocklist);
}

Block* GameManager::GameManager::get_random_block(const QList<Block*> &blocklist){
    return blocklist[qrand()%blocklist.count()];
}

bool GameManager::canMoveDown(const CheckerBoard &board,const Block &present_blk) const
{
    QVector<QPoint>all_pos = present_blk.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.y()+1==GAME_HEIGHT){
            return false;
        }
        if(board.getCheckerBoardArray()[pos.y()+1][pos.x()]==9){
            return false;
        }
    }
    return true;
}

bool GameManager::canMoveLeft(const CheckerBoard &board,const Block &present_blk) const
{
    QVector<QPoint>all_pos = present_blk.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.x()==0){
            return false;
        }
        if(board.getCheckerBoardArray()[pos.y()][pos.x()-1]==9){
            return false;
        }
    }
    return true;
}

bool GameManager::canMoveRight(const CheckerBoard &board,const Block &present_blk) const
{
    QVector<QPoint>all_pos = present_blk.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.x()+1==GAME_WIDTH){
            return false;
        }
        if(board.getCheckerBoardArray()[pos.y()][pos.x()+1]==9){
            return false;
        }
    }
    return true;
}

bool GameManager::canRolate(const CheckerBoard &board,const Block &present_blk) const
{
    Block ghostBlock = present_blk;
    ghostBlock.status_forward();
    QVector<QPoint>all_pos = ghostBlock.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.x()==GAME_WIDTH||pos.x()+1==0||pos.y()+1==GAME_HEIGHT){
            return false;
        }
        if(board.getCheckerBoardArray()[pos.y()][pos.x()]==9){
            return false;
        }
    }
    return true;
}

QList<int> GameManager::canLineElimination(const CheckerBoard &board) const
{
    QList<int> res;
    for(int i=0;i<GAME_HEIGHT;i++){
        bool canElimination=1;
        for(int j=0;j<GAME_WIDTH;j++){
            if(board.getCheckerBoardArray()[i][j]!=9){
                canElimination=0;
                break;
            }
        }
        if(canElimination==1)
        {
            res.append(i);
        }
    }
    return res;
}

void GameManager::eliminateLine(CheckerBoard &board,const QList <int> &lineList)
{
    if(lineList.empty()){
        return;
    }
    for(auto line:lineList){
        for(int i=line;i>0;i--){
            board.setCheckerBoardLine(board.getCheckerBoardLine(i-1),i);
        }
    }
}
