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
private:
    Ui::LoadGameScene *ui;
    int recordId;
    QGraphicsScene* gameGraphicScene;
    QGraphicsView* gameView;
    void render(CheckerBoard checkerboard);
signals:
    void loadSceneBack();
};

#endif // LOADGAMESCENE_H
