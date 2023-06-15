#include "checkerboard.h"

CheckerBoard::CheckerBoard()
{
    init();
}

void CheckerBoard::init(){
    this->CheckerBoardArray.resize(GAME_HEIGHT*GAME_WIDTH);
    for(int i=0;i<GAME_HEIGHT;i++)
    {
        this->CheckerBoardArray[i].resize(GAME_WIDTH);
    }
}

void CheckerBoard::setBlock(Block block)
{
    QVector<QPoint>all_pos = block.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.y()>=0&&pos.y()<GAME_HEIGHT&&pos.x()>=0&&pos.x()<GAME_WIDTH)
        this->CheckerBoardArray[pos.y()][pos.x()]=block.get_color();
    }
}

void CheckerBoard::setFixedBlock(Block block)
{
    QVector<QPoint>all_pos = block.get_all_block_pos();
    for(auto pos:all_pos){
        if(pos.y()>=0&&pos.y()<GAME_HEIGHT&&pos.x()>=0&&pos.x()<GAME_WIDTH)
        this->CheckerBoardArray[pos.y()][pos.x()]=9;//9代表固定块
    }
}

void CheckerBoard::clearMovingBlock(){
    for(int i=0;i<GAME_HEIGHT;i++){
        for(int j=0;j<GAME_WIDTH;j++){
            if(CheckerBoardArray[i][j]!=9){
                CheckerBoardArray[i][j]=0;
            }
        }
    }
}

int CheckerBoard::getHighestFixedBlock() const{
    for(int i=0;i<GAME_HEIGHT;i++){
        for(int j=0;j<GAME_WIDTH;j++){
            if(CheckerBoardArray[i][j]==9){
                return i;
            }
        }
    }
    return GAME_HEIGHT;
}

void CheckerBoard::clearCheckerBoard(){
    CheckerBoardArray = QVector<QVector<int>>(GAME_WIDTH,QVector<int>(GAME_HEIGHT,0));
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
