/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainscene
{
public:
    QLabel *GameTitleLabel;
    QWidget *mainSceneBtnWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startGameBtn;
    QPushButton *loadGameBtn;
    QPushButton *settingBtn;
    QPushButton *exitBtn;
    QToolButton *introBtn;

    void setupUi(QWidget *mainscene)
    {
        if (mainscene->objectName().isEmpty())
            mainscene->setObjectName(QString::fromUtf8("mainscene"));
        mainscene->resize(800, 1000);
        mainscene->setMinimumSize(QSize(800, 1000));
        mainscene->setMaximumSize(QSize(800, 1000));
        mainscene->setLayoutDirection(Qt::LeftToRight);
        GameTitleLabel = new QLabel(mainscene);
        GameTitleLabel->setObjectName(QString::fromUtf8("GameTitleLabel"));
        GameTitleLabel->setGeometry(QRect(200, 180, 400, 200));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GameTitleLabel->sizePolicy().hasHeightForWidth());
        GameTitleLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(72);
        GameTitleLabel->setFont(font);
        GameTitleLabel->setAlignment(Qt::AlignCenter);
        mainSceneBtnWidget = new QWidget(mainscene);
        mainSceneBtnWidget->setObjectName(QString::fromUtf8("mainSceneBtnWidget"));
        mainSceneBtnWidget->setGeometry(QRect(300, 479, 200, 301));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainSceneBtnWidget->sizePolicy().hasHeightForWidth());
        mainSceneBtnWidget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(mainSceneBtnWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        startGameBtn = new QPushButton(mainSceneBtnWidget);
        startGameBtn->setObjectName(QString::fromUtf8("startGameBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(startGameBtn->sizePolicy().hasHeightForWidth());
        startGameBtn->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(16);
        startGameBtn->setFont(font1);

        verticalLayout->addWidget(startGameBtn);

        loadGameBtn = new QPushButton(mainSceneBtnWidget);
        loadGameBtn->setObjectName(QString::fromUtf8("loadGameBtn"));
        sizePolicy2.setHeightForWidth(loadGameBtn->sizePolicy().hasHeightForWidth());
        loadGameBtn->setSizePolicy(sizePolicy2);
        loadGameBtn->setFont(font1);

        verticalLayout->addWidget(loadGameBtn);

        settingBtn = new QPushButton(mainSceneBtnWidget);
        settingBtn->setObjectName(QString::fromUtf8("settingBtn"));
        sizePolicy2.setHeightForWidth(settingBtn->sizePolicy().hasHeightForWidth());
        settingBtn->setSizePolicy(sizePolicy2);
        settingBtn->setFont(font1);

        verticalLayout->addWidget(settingBtn);

        exitBtn = new QPushButton(mainSceneBtnWidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        sizePolicy2.setHeightForWidth(exitBtn->sizePolicy().hasHeightForWidth());
        exitBtn->setSizePolicy(sizePolicy2);
        exitBtn->setFont(font1);

        verticalLayout->addWidget(exitBtn);

        introBtn = new QToolButton(mainscene);
        introBtn->setObjectName(QString::fromUtf8("introBtn"));
        introBtn->setGeometry(QRect(30, 30, 71, 71));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(16);
        introBtn->setFont(font2);

        retranslateUi(mainscene);

        QMetaObject::connectSlotsByName(mainscene);
    } // setupUi

    void retranslateUi(QWidget *mainscene)
    {
        mainscene->setWindowTitle(QCoreApplication::translate("mainscene", "mainscene", nullptr));
        GameTitleLabel->setText(QCoreApplication::translate("mainscene", "Tetris", nullptr));
        startGameBtn->setText(QCoreApplication::translate("mainscene", "\346\226\260\346\270\270\346\210\217", nullptr));
        loadGameBtn->setText(QCoreApplication::translate("mainscene", "\345\212\240\350\275\275\346\270\270\346\210\217", nullptr));
        settingBtn->setText(QCoreApplication::translate("mainscene", "\350\256\276\347\275\256", nullptr));
        exitBtn->setText(QCoreApplication::translate("mainscene", "\351\200\200\345\207\272", nullptr));
        introBtn->setText(QCoreApplication::translate("mainscene", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainscene: public Ui_mainscene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
