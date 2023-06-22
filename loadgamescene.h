#ifndef LOADGAMESCENE_H
#define LOADGAMESCENE_H

#include <QWidget>
#include <QGraphicsView>
#include "checkerboard.h"

namespace Ui {
class LoadGameScene;
}

class LoadGameScene : public QWidget
{
    Q_OBJECT

public:
    explicit LoadGameScene(QWidget *parent = nullptr);
    ~LoadGameScene();
    void showRenderScene();
    //改变色调
    void changePal();
private:
    void leftSelect();
    void rightSelect();
    void okSelect();
    void keyPressEvent(QKeyEvent *event)override;

    Ui::LoadGameScene *ui;
    int recordId;
    QGraphicsScene* gameGraphicScene;
    QGraphicsView* gameView;
    void render(CheckerBoard checkerboard);
    int pal;
signals:
    void loadSceneBack();
    void okSelectSignal(int recordId);
};

#endif // LOADGAMESCENE_H
