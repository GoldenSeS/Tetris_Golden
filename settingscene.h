#ifndef SETTINGSCENE_H
#define SETTINGSCENE_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVector>
#include "coloroptionblock.h"
#include "keyoptionblock.h"
namespace Ui {
class SettingScene;
}

class SettingScene : public QWidget
{
    Q_OBJECT

public:
    explicit SettingScene(QWidget *parent = nullptr);
    ~SettingScene();

private:
    Ui::SettingScene *ui;
    void init();
    void setNumFromDatabase();
    void setNumFromDefault();
    void saveSettingToDatabase();

    QMediaPlayer *mediaPlayer;

    QVector<colorOptionBlock*> colorOptionBlk_Vector;
    QVector<keyOptionBlock*> keyOptionBlk_Vector;

    bool keyRepetition();

    void disableMouseClick(QWidget *widget);
    void enableMouseClick(QWidget *widget);

    void addNewProfile();

signals:
    void settingSceneBack();
};

#endif // SETTINGSCENE_H
