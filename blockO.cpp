#include "blockO.h"

BlockO::BlockO()
{
    this->block_color=2;
    QVector<QPoint> vec;
    vec.append(QPoint(-1,0));
    vec.append(QPoint(0,0));
    vec.append(QPoint(-1,1));
    vec.append(QPoint(0,1));
    blockshape.append(vec);

    vec.clear();
    vec.append(QPoint(1,1));
    vec.append(QPoint(0,1));
    vec.append(QPoint(0,0));
    vec.append(QPoint(1,0));
    blockshape.append(vec);

    vec.clear();
    vec.append(QPoint(1,-1));
    vec.append(QPoint(0,0));
    vec.append(QPoint(1,0));
    vec.append(QPoint(0,-1));
    blockshape.append(vec);

    vec.clear();
    vec.append(QPoint(0,-1));
    vec.append(QPoint(0,0));
    vec.append(QPoint(-1,0));
    vec.append(QPoint(-1,-1));
    blockshape.append(vec);
}
