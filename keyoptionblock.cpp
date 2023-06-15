#include "keyoptionblock.h"
#include "ui_keyoptionblock.h"
#include <QKeyEvent>
#include <QDebug>
keyOptionBlock::keyOptionBlock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::keyOptionBlock)
{
    ui->setupUi(this);
    ui->keyLineEdit->setReadOnly(true);
    connect(ui->resetBtn, &QPushButton::clicked, this, &keyOptionBlock::onButtonClicked);
    listeningEnabled=false;
}

void keyOptionBlock::setLabel(QString label){
    ui->keyLabel->setText(label);
}
void keyOptionBlock::setBtnStr(QString str){
    ui->resetBtn->setText(str);
}

void keyOptionBlock::setKey(Qt::Key key){
    this->m_key=key;
    ui->keyLineEdit->setText(QKeySequence(key).toString());
}

Qt::Key keyOptionBlock::getKey(){
    return m_key;
}

void keyOptionBlock::onButtonClicked()
{
    listeningEnabled = true; // 设置为正在监听键盘事件
    this->grabKeyboard();
    ui->keyLineEdit->setFocus();  // 设置文本框获得焦点，以便监听键盘事件
    ui->resetBtn->setText("等待按下");
    ui->resetBtn->setEnabled(false);  // 禁用按钮，避免重复按下
    emit disableMouseControl();
}

void keyOptionBlock::keyPressEvent(QKeyEvent *event){
    if(listeningEnabled){
        // 获取按下的键名，并将其设置在文本框中显示
        QString keyName = QKeySequence(event->key()).toString();
        ui->keyLineEdit->setText(keyName);
        m_key = static_cast<Qt::Key>(event->key());
        // 将按钮文本恢复为“重设”，同时启用按钮
        ui->resetBtn->setText("重设");
        ui->resetBtn->setEnabled(true);
        listeningEnabled=false;
        this->releaseKeyboard();
        emit enableMouseControl();
    }else{
        QWidget::keyPressEvent(event);
    }

}
keyOptionBlock::~keyOptionBlock()
{
    delete ui;
}
