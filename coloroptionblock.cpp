#include "coloroptionblock.h"
#include "ui_coloroptionblock.h"
#include <QColorDialog>
#include <QDebug>
colorOptionBlock::colorOptionBlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::colorOptionBlock)
{
    ui->setupUi(this);
    ui->colorLineEdit->setReadOnly(true);

    connect(ui->selectColorBtn,&QPushButton::clicked,this,[=](){
        this->setColorfromDialog();
    });
}

void colorOptionBlock::setText(QString text){
    ui->selectColorBtn->setText(text);
}

QString colorOptionBlock::getColorText(){
    return m_color.name(QColor::HexRgb);
}

void colorOptionBlock::setColorfromDialog(){
    QColor color = QColorDialog::getColor(Qt::white, this, tr("Choose a color"));
    m_color = color;
    QPalette palette;
    if (color.isValid())
    {
        // 将RGB颜色代码显示在文本框中
        ui->colorLineEdit->setText(color.name(QColor::HexRgb));
        // 根据颜色深浅调节文本颜色
        if (color.lightness() < 127)
        {
            palette.setColor(QPalette::Text,Qt::white);
        }
        else
        {
            palette.setColor(QPalette::Text,Qt::black);
        }

        // 调整文本框背景颜色为用户选择的颜色
        ui->colorLineEdit->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue()));
        ui->colorLineEdit->setPalette(palette);
    }
}

void colorOptionBlock::setColor(QColor color){
    this->m_color=color;
    QPalette palette;
    if (color.isValid())
    {
        // 将RGB颜色代码显示在文本框中
        ui->colorLineEdit->setText(color.name(QColor::HexRgb));
        // 根据颜色深浅调节文本颜色
        if (color.lightness() < 127)
        {
            palette.setColor(QPalette::Text,Qt::white);
        }
        else
        {
            palette.setColor(QPalette::Text,Qt::black);
        }

        // 调整文本框背景颜色为用户选择的颜色
        ui->colorLineEdit->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(color.red()).arg(color.green()).arg(color.blue()));
        ui->colorLineEdit->setPalette(palette);
    }
}

QColor colorOptionBlock::getColor(){
    return m_color;
}

colorOptionBlock::~colorOptionBlock()
{
    delete ui;
}
