#ifndef KEYOPTIONBLOCK_H
#define KEYOPTIONBLOCK_H

#include <QWidget>

namespace Ui {
class keyOptionBlock;
}

class keyOptionBlock : public QWidget
{
    Q_OBJECT

public:
    explicit keyOptionBlock(QWidget *parent = nullptr);
    ~keyOptionBlock();

    void setLabel(QString label);
    void setBtnStr(QString str);

    void setKey(Qt::Key key);
    Qt::Key getKey();

private:
    Ui::keyOptionBlock *ui;
    void onButtonClicked();
    void keyPressEvent(QKeyEvent *event)override;

    Qt::Key m_key;


    bool listeningEnabled; // 标识是否正在监听键盘事件
signals:
    void disableMouseControl();
    void enableMouseControl();
};

#endif // KEYOPTIONBLOCK_H
