#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "gamescene.h"
#include "settingscene.h"
#include "loadgamescene.h"
#include "rankingsscene.h"
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

    int moonDayShift;

    void updatePaletteColor(QWidget* widget, const QPalette& pal);

    LoadGameScene *loadScenePtr = nullptr;
    GameScene *gameScenePtr = nullptr;
    SettingScene *settingScenePtr = nullptr;
    RankingsScene *rankingsScenePtr = nullptr;
};
#endif // MAINSCENE_H
