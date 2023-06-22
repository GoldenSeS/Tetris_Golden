#include "checkerboard.h"
#include <QDebug>
CheckerBoard::CheckerBoard()
{
    init();
}

void CheckerBoard::init(){
    this->CheckerBoardArray.resize(GAME_HEIGHT);
    for(int i=0;i<GAME_HEIGHT;i++)
    {
        this->CheckerBoardArray[i].resize(GAME_WIDTH);
    }
}

void CheckerBoard::debugCheckerBoard(){
    for(int i=0;i<CheckerBoardArray.size();i++)
    {
        qDebug()<<"        "<<CheckerBoardArray[i];
    }
    qDebug()<<"";
}

void CheckerBoard::CheckerBoard::setBlock(Block block)
{
    QVector<QPoint>all_pos = block.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.y()>=0&&pos.y()<CheckerBoardArray.size()&&pos.x()>=0&&pos.x()<CheckerBoardArray[0].size())
        this->CheckerBoardArray[pos.y()][pos.x()]=block.get_color();
    }
}

void CheckerBoard::setFixedBlock(Block block)
{
    QVector<QPoint>all_pos = block.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.y()>=0&&pos.y()<CheckerBoardArray.size()&&pos.x()>=0&&pos.x()<CheckerBoardArray[0].size())
        this->CheckerBoardArray[pos.y()][pos.x()]=9;//9代表固定块
    }
}

void CheckerBoard::clearMovingBlock(){
    for(int i=0;i<CheckerBoardArray.size();i++){
        for(int j=0;j<CheckerBoardArray[0].size();j++){
            if(CheckerBoardArray[i][j]!=9){
                CheckerBoardArray[i][j]=0;
            }
        }
    }
}

QVector<QVector<int>> CheckerBoard::getFixedBlockCheckerBoardArray(){
    for(int i=0;i<CheckerBoardArray.size();i++){
        for(int j=0;j<CheckerBoardArray[0].size();j++){
            if(CheckerBoardArray[i][j]!=9){
                CheckerBoardArray[i][j]=0;
            }
        }
    }
    return CheckerBoardArray;
}

int CheckerBoard::getHighestFixedBlock() const{
    for(int i=0;i<CheckerBoardArray.size();i++){
        for(int j=0;j<CheckerBoardArray[0].size();j++){
            if(CheckerBoardArray[i][j]==9){
                return i;
            }
        }
    }
    return CheckerBoardArray.size();
}

void CheckerBoard::clearCheckerBoard(){
    CheckerBoardArray = QVector<QVector<int>>(CheckerBoardArray[0].size(),QVector<int>(CheckerBoardArray.size(),0));
    init();
}

QVector<QVector<int>> CheckerBoard::getCheckerBoardArray() const
{
    return this->CheckerBoardArray;
}

QVector<int> CheckerBoard::getCheckerBoardLine(int lineNum) const
{
    return this->CheckerBoardArray[lineNum];
}

void CheckerBoard::setCheckerBoardLine(QVector<int> lineData,int lineNum){
    this->CheckerBoardArray[lineNum]=lineData;
}

void CheckerBoard::setCheckerBoardArray(QVector<QVector<int>> CheckerBoardArray)
{
    this->CheckerBoardArray = CheckerBoardArray;
}
