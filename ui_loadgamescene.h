/********************************************************************************
** Form generated from reading UI file 'loadgamescene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADGAMESCENE_H
#define UI_LOADGAMESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadGameScene
{
public:
    QGraphicsView *gameGraphicsView;
    QPushButton *okBtn;
    QPushButton *leftBtn;
    QPushButton *rightBtn;
    QLabel *label;
    QLabel *endLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *IdLabel;
    QLabel *label_4;
    QLabel *timeLabel;
    QLabel *label_7;
    QLabel *speedLabel;
    QLabel *label_3;
    QLabel *scoreLabel;
    QLabel *userLabel;
    QPushButton *backBtn;

    void setupUi(QWidget *LoadGameScene)
    {
        if (LoadGameScene->objectName().isEmpty())
            LoadGameScene->setObjectName(QString::fromUtf8("LoadGameScene"));
        LoadGameScene->resize(800, 1000);
        LoadGameScene->setMinimumSize(QSize(800, 1000));
        LoadGameScene->setMaximumSize(QSize(800, 1000));
        gameGraphicsView = new QGraphicsView(LoadGameScene);
        gameGraphicsView->setObjectName(QString::fromUtf8("gameGraphicsView"));
        gameGraphicsView->setGeometry(QRect(120, 200, 330, 550));
        okBtn = new QPushButton(LoadGameScene);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setGeometry(QRect(330, 820, 140, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(14);
        okBtn->setFont(font);
        leftBtn = new QPushButton(LoadGameScene);
        leftBtn->setObjectName(QString::fromUtf8("leftBtn"));
        leftBtn->setGeometry(QRect(230, 820, 81, 61));
        leftBtn->setFont(font);
        rightBtn = new QPushButton(LoadGameScene);
        rightBtn->setObjectName(QString::fromUtf8("rightBtn"));
        rightBtn->setGeometry(QRect(490, 820, 81, 61));
        rightBtn->setFont(font);
        label = new QLabel(LoadGameScene);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 50, 251, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(28);
        label->setFont(font1);
        endLabel = new QLabel(LoadGameScene);
        endLabel->setObjectName(QString::fromUtf8("endLabel"));
        endLabel->setGeometry(QRect(160, 430, 250, 91));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(24);
        font2.setBold(true);
        font2.setWeight(75);
        endLabel->setFont(font2);
        endLabel->setAlignment(Qt::AlignCenter);
        widget = new QWidget(LoadGameScene);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(500, 170, 241, 521));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font3.setPointSize(16);
        label_2->setFont(font3);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_2);

        IdLabel = new QLabel(widget);
        IdLabel->setObjectName(QString::fromUtf8("IdLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(IdLabel->sizePolicy().hasHeightForWidth());
        IdLabel->setSizePolicy(sizePolicy);
        IdLabel->setMinimumSize(QSize(0, 40));
        IdLabel->setMaximumSize(QSize(16777215, 40));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(18);
        IdLabel->setFont(font4);
        IdLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(IdLabel);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_4);

        timeLabel = new QLabel(widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        sizePolicy.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy);
        timeLabel->setMinimumSize(QSize(0, 80));
        timeLabel->setMaximumSize(QSize(16777215, 80));
        timeLabel->setFont(font4);
        timeLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(timeLabel);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_7);

        speedLabel = new QLabel(widget);
        speedLabel->setObjectName(QString::fromUtf8("speedLabel"));
        sizePolicy.setHeightForWidth(speedLabel->sizePolicy().hasHeightForWidth());
        speedLabel->setSizePolicy(sizePolicy);
        speedLabel->setMinimumSize(QSize(0, 40));
        speedLabel->setMaximumSize(QSize(16777215, 40));
        speedLabel->setFont(font4);
        speedLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(speedLabel);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_3);

        scoreLabel = new QLabel(widget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        sizePolicy.setHeightForWidth(scoreLabel->sizePolicy().hasHeightForWidth());
        scoreLabel->setSizePolicy(sizePolicy);
        scoreLabel->setMinimumSize(QSize(0, 40));
        scoreLabel->setMaximumSize(QSize(16777215, 40));
        scoreLabel->setFont(font4);
        scoreLabel->setFrameShape(QFrame::Box);

        verticalLayout->addWidget(scoreLabel);

        userLabel = new QLabel(LoadGameScene);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(80, 130, 301, 41));
        userLabel->setFont(font3);
        backBtn = new QPushButton(LoadGameScene);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(620, 70, 111, 61));
        backBtn->setFont(font);

        retranslateUi(LoadGameScene);

        QMetaObject::connectSlotsByName(LoadGameScene);
    } // setupUi

    void retranslateUi(QWidget *LoadGameScene)
    {
        LoadGameScene->setWindowTitle(QCoreApplication::translate("LoadGameScene", "Form", nullptr));
        okBtn->setText(QCoreApplication::translate("LoadGameScene", "\347\241\256\345\256\232", nullptr));
        leftBtn->setText(QCoreApplication::translate("LoadGameScene", "\342\206\220", nullptr));
        rightBtn->setText(QCoreApplication::translate("LoadGameScene", "\342\206\222", nullptr));
        label->setText(QCoreApplication::translate("LoadGameScene", "\350\257\273\345\217\226\345\255\230\346\241\243", nullptr));
        endLabel->setText(QCoreApplication::translate("LoadGameScene", "\345\267\262\347\273\223\346\235\237", nullptr));
        label_2->setText(QCoreApplication::translate("LoadGameScene", "\350\256\260\345\275\225ID", nullptr));
        IdLabel->setText(QCoreApplication::translate("LoadGameScene", "testnum", nullptr));
        label_4->setText(QCoreApplication::translate("LoadGameScene", "\346\270\270\347\216\251\346\227\266\351\227\264", nullptr));
        timeLabel->setText(QCoreApplication::translate("LoadGameScene", "testnum", nullptr));
        label_7->setText(QCoreApplication::translate("LoadGameScene", "\346\270\270\346\210\217\351\200\237\345\272\246", nullptr));
        speedLabel->setText(QCoreApplication::translate("LoadGameScene", "testnum", nullptr));
        label_3->setText(QCoreApplication::translate("LoadGameScene", "\345\210\206\346\225\260", nullptr));
        scoreLabel->setText(QCoreApplication::translate("LoadGameScene", "testnum", nullptr));
        userLabel->setText(QCoreApplication::translate("LoadGameScene", "\345\275\223\345\211\215\347\224\250\346\210\267", nullptr));
        backBtn->setText(QCoreApplication::translate("LoadGameScene", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadGameScene: public Ui_LoadGameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADGAMESCENE_H
