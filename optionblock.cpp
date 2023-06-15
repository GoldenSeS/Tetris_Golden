#include "optionblock.h"
#include "ui_optionblock.h"
#include <QDebug>
optionBlock::optionBlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::optionBlock)
{
    ui->setupUi(this);

    //QSpinBox 改变 QSlider 跟着移动
    void(QSpinBox::*spSignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->spinBox,spSignal,[=](){
        emit valueChanged();
    });
    //QSlider 滑动 QSpinBox 数字跟着改变
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

void optionBlock::setNum(int num)
{
    ui->spinBox->setValue(num);
}

int optionBlock::getNum()
{
    return ui->spinBox->value();
}

void optionBlock::setstep(int num){
    ui->horizontalSlider->setSingleStep(num);
    ui->horizontalSlider->setPageStep(num);
}

//设置标签
void optionBlock::setText(QString str){
    ui->label->setText(str);
}
//获取标签
QString optionBlock::getText(){
    return ui->label->text();
}
//设置上下限
void optionBlock::setlimit(int upper,int lower){
    ui->spinBox->setMinimum(lower);
    ui->horizontalSlider->setMinimum(lower);
    ui->spinBox->setMaximum(upper);
    ui->horizontalSlider->setMaximum(upper);
}

optionBlock::~optionBlock()
{
    delete ui;
}
