#include "block.h"
#include "database.h"
Block::Block()
{
    this->block_pos.setX(GAME_WIDTH/2);
    this->block_pos.setY(1);
    block_status=0;
}

void Block::status_forward()
{
    if(this->get_status()<3)
        this->block_status++;
    else
        this->block_status=0;
}

void Block::status_backward()
{
    if(this->get_status()>0)
        this->block_status--;
    else
        this->block_status=3;
}

int Block::get_status()
{
    return this->block_status;
}

QVector<QPoint> Block::get_all_block_pos() const
{
    QVector<QPoint> all_block_pos;
    for(int i=0;i<blockshape[block_status].size();i++)
    {
        all_block_pos.push_back(block_pos+blockshape[block_status][i]);
    }
    return all_block_pos;
}

QVector<QPoint> Block::get_init_block_pos() const
{
    QVector<QPoint> all_block_pos;
    for(int i=0;i<blockshape[block_status].size();i++)
    {
        all_block_pos.push_back(blockshape[block_status][i]);
    }
    return all_block_pos;
}

void Block::move_down()
{
    block_pos.setY(block_pos.y()+1);
}

void Block::move_left()
{
    block_pos.setX(block_pos.x()-1);
}

void Block::move_right()
{
    block_pos.setX(block_pos.x()+1);
}

int Block::get_color()
{
    return block_color;
}
