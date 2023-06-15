#ifndef BLOCK_H
#define BLOCK_H
#include <QPoint>
#include <QColor>
#include <QVector>
class Block
{
public:
    Block();
    //旋转至下一个状态
    void status_forward();
    //旋转至上一个状态
    void status_backward();
    //获取当前状态
    int get_status();
    //获取当前占用的位置
    QVector<QPoint> get_all_block_pos() const;
    //获取原始占用的位置
    QVector<QPoint> get_init_block_pos() const;
    //向下移动
    void move_down();
    //向左移动
    void move_left();
    //向右移动
    void move_right();
    //获取当前颜色
    int get_color();
protected:
    QPoint block_pos;
    int block_color;
    int block_status;
    QVector<QVector<QPoint>> blockshape;
};

#endif // BLOCK_H
