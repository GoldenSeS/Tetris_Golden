#ifndef OPTIONBLOCK_H
#define OPTIONBLOCK_H

#include <QWidget>

namespace Ui {
class optionBlock;
}

class optionBlock : public QWidget
{
    Q_OBJECT

public:
    explicit optionBlock(QWidget *parent = nullptr);
    ~optionBlock();
    //设置标签
    void setText(QString str);
    //获取标签
    QString getText();
    //设置上下限
    void setlimit(int upper,int lower);
    //设置点击和左右键的步进值
    void setstep(int num);
    //设置数字
    void setNum(int num);
    //获取数字
    int getNum();
private:
    Ui::optionBlock *ui;
signals:
    void valueChanged();
};

#endif // OPTIONBLOCK_H
