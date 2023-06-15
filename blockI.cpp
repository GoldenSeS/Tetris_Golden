#include "blockI.h"

BlockI::BlockI()
{
    this->block_color=4;
    QVector<QPoint> vec;
    vec.append(QPoint(1,0));
    vec.append(QPoint(0,0));
    vec.append(QPoint(-1,0));
    vec.append(QPoint(2,0));
    blockshape.append(vec);

    vec.clear();
    vec.append(QPoint(0,1));
    vec.append(QPoint(0,-1));
    vec.append(QPoint(0,0));
    vec.append(QPoint(0,-2));
    blockshape.append(vec);

    vec.clear();
    vec.append(QPoint(-1,0));
    vec.append(QPoint(0,0));
    vec.append(QPoint(1,0));
    vec.append(QPoint(-2,0));
    blockshape.append(vec);

    vec.clear();
    vec.append(QPoint(0,-1));
    vec.append(QPoint(0,0));
    vec.append(QPoint(0,1));
    vec.append(QPoint(0,2));
    blockshape.append(vec);
}
