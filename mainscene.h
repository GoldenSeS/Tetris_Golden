#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "gamescene.h"
#include "settingscene.h"
#include "loadgamescene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class mainscene; }
QT_END_NAMESPACE

class mainscene : public QWidget
{
    Q_OBJECT

public:
    mainscene(QWidget *parent = nullptr);
    ~mainscene();

private:
    Ui::mainscene *ui;

    LoadGameScene *loadScenePtr = nullptr;
    GameScene *gameScenePtr = nullptr;
    SettingScene *settingScenePtr = nullptr;

};
#endif // MAINSCENE_H
