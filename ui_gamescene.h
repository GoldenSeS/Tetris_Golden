/********************************************************************************
** Form generated from reading UI file 'gamescene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENE_H
#define UI_GAMESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameScene
{
public:
    QGraphicsView *gameGraphicsView;
    QGraphicsView *nextBlockGraphicsView;
    QWidget *scoreWidget;
    QVBoxLayout *verticalLayout;
    QLabel *scoreLabel;
    QLCDNumber *scoreLCD;
    QPushButton *backBtn;
    QPushButton *restart_btn;
    QLabel *pauseLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *scoreWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *musicLabel;
    QPushButton *musicBtn;
    QSlider *musicSlider;

    void setupUi(QWidget *GameScene)
    {
        if (GameScene->objectName().isEmpty())
            GameScene->setObjectName(QString::fromUtf8("GameScene"));
        GameScene->resize(800, 1000);
        GameScene->setMinimumSize(QSize(800, 1000));
        GameScene->setMaximumSize(QSize(800, 1000));
        gameGraphicsView = new QGraphicsView(GameScene);
        gameGraphicsView->setObjectName(QString::fromUtf8("gameGraphicsView"));
        gameGraphicsView->setGeometry(QRect(50, 100, 400, 800));
        nextBlockGraphicsView = new QGraphicsView(GameScene);
        nextBlockGraphicsView->setObjectName(QString::fromUtf8("nextBlockGraphicsView"));
        nextBlockGraphicsView->setGeometry(QRect(500, 100, 200, 200));
        scoreWidget = new QWidget(GameScene);
        scoreWidget->setObjectName(QString::fromUtf8("scoreWidget"));
        scoreWidget->setGeometry(QRect(500, 335, 201, 191));
        verticalLayout = new QVBoxLayout(scoreWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scoreLabel = new QLabel(scoreWidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scoreLabel->sizePolicy().hasHeightForWidth());
        scoreLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(20);
        scoreLabel->setFont(font);

        verticalLayout->addWidget(scoreLabel);

        scoreLCD = new QLCDNumber(scoreWidget);
        scoreLCD->setObjectName(QString::fromUtf8("scoreLCD"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scoreLCD->sizePolicy().hasHeightForWidth());
        scoreLCD->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(scoreLCD);

        backBtn = new QPushButton(GameScene);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(550, 840, 150, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(12);
        backBtn->setFont(font1);
        restart_btn = new QPushButton(GameScene);
        restart_btn->setObjectName(QString::fromUtf8("restart_btn"));
        restart_btn->setGeometry(QRect(550, 770, 150, 50));
        restart_btn->setFont(font1);
        pauseLabel = new QLabel(GameScene);
        pauseLabel->setObjectName(QString::fromUtf8("pauseLabel"));
        pauseLabel->setGeometry(QRect(110, 420, 281, 181));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(48);
        pauseLabel->setFont(font2);
        pauseLabel->setLayoutDirection(Qt::LeftToRight);
        pauseLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(GameScene);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(510, 540, 201, 131));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scoreWidget_2 = new QWidget(widget);
        scoreWidget_2->setObjectName(QString::fromUtf8("scoreWidget_2"));
        horizontalLayout = new QHBoxLayout(scoreWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        musicLabel = new QLabel(scoreWidget_2);
        musicLabel->setObjectName(QString::fromUtf8("musicLabel"));
        sizePolicy1.setHeightForWidth(musicLabel->sizePolicy().hasHeightForWidth());
        musicLabel->setSizePolicy(sizePolicy1);
        musicLabel->setFont(font);
        musicLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(musicLabel);

        musicBtn = new QPushButton(scoreWidget_2);
        musicBtn->setObjectName(QString::fromUtf8("musicBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(musicBtn->sizePolicy().hasHeightForWidth());
        musicBtn->setSizePolicy(sizePolicy2);
        musicBtn->setMaximumSize(QSize(60, 16777215));
        musicBtn->setFont(font1);

        horizontalLayout->addWidget(musicBtn);


        verticalLayout_2->addWidget(scoreWidget_2);

        musicSlider = new QSlider(widget);
        musicSlider->setObjectName(QString::fromUtf8("musicSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(musicSlider->sizePolicy().hasHeightForWidth());
        musicSlider->setSizePolicy(sizePolicy3);
        musicSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(musicSlider);


        retranslateUi(GameScene);

        QMetaObject::connectSlotsByName(GameScene);
    } // setupUi

    void retranslateUi(QWidget *GameScene)
    {
        GameScene->setWindowTitle(QCoreApplication::translate("GameScene", "Form", nullptr));
        scoreLabel->setText(QCoreApplication::translate("GameScene", "\345\210\206\346\225\260", nullptr));
        backBtn->setText(QCoreApplication::translate("GameScene", "\350\277\224\345\233\236", nullptr));
        restart_btn->setText(QCoreApplication::translate("GameScene", "\345\274\200\345\247\213", nullptr));
        pauseLabel->setText(QCoreApplication::translate("GameScene", "PAUSE", nullptr));
        musicLabel->setText(QCoreApplication::translate("GameScene", "\351\237\263\344\271\220", nullptr));
        musicBtn->setText(QCoreApplication::translate("GameScene", "\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameScene: public Ui_GameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENE_H
