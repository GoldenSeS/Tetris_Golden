#ifndef COLOROPTIONBLOCK_H
#define COLOROPTIONBLOCK_H

#include <QWidget>

namespace Ui {
class colorOptionBlock;
}

class colorOptionBlock : public QWidget
{
    Q_OBJECT

public:
    explicit colorOptionBlock(QWidget *parent = nullptr);

    void setText(QString text);
    QString getColorText();

    void setColorfromDialog();
    void setColor(QColor color);

    QColor getColor();

    ~colorOptionBlock();

private:
    Ui::colorOptionBlock *ui;

    QColor m_color;
};

#endif // COLOROPTIONBLOCK_H
