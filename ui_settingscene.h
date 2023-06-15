/********************************************************************************
** Form generated from reading UI file 'settingscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSCENE_H
#define UI_SETTINGSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <coloroptionblock.h>
#include <keyoptionblock.h>
#include <optionblock.h>

QT_BEGIN_NAMESPACE

class Ui_SettingScene
{
public:
    QPushButton *resetBtn;
    QPushButton *settingBackBtn;
    QTabWidget *tabWidget;
    QWidget *generalTab;
    QVBoxLayout *verticalLayout;
    optionBlock *heightOptionBlock;
    optionBlock *widthOptionBlock;
    optionBlock *fallingOptionBlock;
    QWidget *mediaOptionWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *otherMediaWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *mediaLineEdit;
    QPushButton *chooseMediaFileBtn;
    QPushButton *tryListeningBtn;
    optionBlock *mediaOptionBlock;
    QWidget *videoTab;
    QVBoxLayout *verticalLayout_3;
    colorOptionBlock *blockL_colorOptionBlock;
    colorOptionBlock *blockO_colorOptionBlock;
    colorOptionBlock *blockJ_colorOptionBlock;
    colorOptionBlock *blockI_colorOptionBlock;
    colorOptionBlock *blockT_colorOptionBlock;
    colorOptionBlock *blockS_colorOptionBlock;
    colorOptionBlock *blockZ_colorOptionBlock;
    QWidget *keyboardTab;
    QVBoxLayout *verticalLayout_4;
    keyOptionBlock *left_keyOptionBlock;
    keyOptionBlock *right_keyOptionBlock;
    keyOptionBlock *down_keyOptionBlock;
    keyOptionBlock *spin_keyOptionBlock;
    keyOptionBlock *pause_keyOptionBlock;
    QWidget *profileTab;
    QLabel *label;

    void setupUi(QWidget *SettingScene)
    {
        if (SettingScene->objectName().isEmpty())
            SettingScene->setObjectName(QString::fromUtf8("SettingScene"));
        SettingScene->resize(800, 1000);
        SettingScene->setMinimumSize(QSize(800, 1000));
        SettingScene->setMaximumSize(QSize(800, 1000));
        resetBtn = new QPushButton(SettingScene);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
        resetBtn->setGeometry(QRect(590, 780, 131, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(16);
        resetBtn->setFont(font);
        settingBackBtn = new QPushButton(SettingScene);
        settingBackBtn->setObjectName(QString::fromUtf8("settingBackBtn"));
        settingBackBtn->setGeometry(QRect(590, 850, 131, 61));
        settingBackBtn->setFont(font);
        tabWidget = new QTabWidget(SettingScene);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(60, 190, 461, 771));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(14);
        tabWidget->setFont(font1);
        generalTab = new QWidget();
        generalTab->setObjectName(QString::fromUtf8("generalTab"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(generalTab->sizePolicy().hasHeightForWidth());
        generalTab->setSizePolicy(sizePolicy);
        generalTab->setMaximumSize(QSize(16777215, 16777209));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(12);
        generalTab->setFont(font2);
        verticalLayout = new QVBoxLayout(generalTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        heightOptionBlock = new optionBlock(generalTab);
        heightOptionBlock->setObjectName(QString::fromUtf8("heightOptionBlock"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(150);
        sizePolicy1.setHeightForWidth(heightOptionBlock->sizePolicy().hasHeightForWidth());
        heightOptionBlock->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(heightOptionBlock);

        widthOptionBlock = new optionBlock(generalTab);
        widthOptionBlock->setObjectName(QString::fromUtf8("widthOptionBlock"));
        sizePolicy1.setHeightForWidth(widthOptionBlock->sizePolicy().hasHeightForWidth());
        widthOptionBlock->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(widthOptionBlock);

        fallingOptionBlock = new optionBlock(generalTab);
        fallingOptionBlock->setObjectName(QString::fromUtf8("fallingOptionBlock"));
        sizePolicy1.setHeightForWidth(fallingOptionBlock->sizePolicy().hasHeightForWidth());
        fallingOptionBlock->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(fallingOptionBlock);

        mediaOptionWidget = new QWidget(generalTab);
        mediaOptionWidget->setObjectName(QString::fromUtf8("mediaOptionWidget"));
        sizePolicy1.setHeightForWidth(mediaOptionWidget->sizePolicy().hasHeightForWidth());
        mediaOptionWidget->setSizePolicy(sizePolicy1);
        mediaOptionWidget->setMinimumSize(QSize(150, 150));
        verticalLayout_2 = new QVBoxLayout(mediaOptionWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        otherMediaWidget = new QWidget(mediaOptionWidget);
        otherMediaWidget->setObjectName(QString::fromUtf8("otherMediaWidget"));
        horizontalLayout = new QHBoxLayout(otherMediaWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mediaLineEdit = new QLineEdit(otherMediaWidget);
        mediaLineEdit->setObjectName(QString::fromUtf8("mediaLineEdit"));

        horizontalLayout->addWidget(mediaLineEdit);

        chooseMediaFileBtn = new QPushButton(otherMediaWidget);
        chooseMediaFileBtn->setObjectName(QString::fromUtf8("chooseMediaFileBtn"));

        horizontalLayout->addWidget(chooseMediaFileBtn);

        tryListeningBtn = new QPushButton(otherMediaWidget);
        tryListeningBtn->setObjectName(QString::fromUtf8("tryListeningBtn"));

        horizontalLayout->addWidget(tryListeningBtn);


        verticalLayout_2->addWidget(otherMediaWidget);

        mediaOptionBlock = new optionBlock(mediaOptionWidget);
        mediaOptionBlock->setObjectName(QString::fromUtf8("mediaOptionBlock"));

        verticalLayout_2->addWidget(mediaOptionBlock);


        verticalLayout->addWidget(mediaOptionWidget);

        tabWidget->addTab(generalTab, QString());
        videoTab = new QWidget();
        videoTab->setObjectName(QString::fromUtf8("videoTab"));
        verticalLayout_3 = new QVBoxLayout(videoTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        blockL_colorOptionBlock = new colorOptionBlock(videoTab);
        blockL_colorOptionBlock->setObjectName(QString::fromUtf8("blockL_colorOptionBlock"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(100);
        sizePolicy2.setHeightForWidth(blockL_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockL_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockL_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockL_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockL_colorOptionBlock);

        blockO_colorOptionBlock = new colorOptionBlock(videoTab);
        blockO_colorOptionBlock->setObjectName(QString::fromUtf8("blockO_colorOptionBlock"));
        sizePolicy2.setHeightForWidth(blockO_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockO_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockO_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockO_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockO_colorOptionBlock);

        blockJ_colorOptionBlock = new colorOptionBlock(videoTab);
        blockJ_colorOptionBlock->setObjectName(QString::fromUtf8("blockJ_colorOptionBlock"));
        sizePolicy2.setHeightForWidth(blockJ_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockJ_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockJ_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockJ_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockJ_colorOptionBlock);

        blockI_colorOptionBlock = new colorOptionBlock(videoTab);
        blockI_colorOptionBlock->setObjectName(QString::fromUtf8("blockI_colorOptionBlock"));
        sizePolicy2.setHeightForWidth(blockI_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockI_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockI_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockI_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockI_colorOptionBlock);

        blockT_colorOptionBlock = new colorOptionBlock(videoTab);
        blockT_colorOptionBlock->setObjectName(QString::fromUtf8("blockT_colorOptionBlock"));
        sizePolicy2.setHeightForWidth(blockT_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockT_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockT_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockT_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockT_colorOptionBlock);

        blockS_colorOptionBlock = new colorOptionBlock(videoTab);
        blockS_colorOptionBlock->setObjectName(QString::fromUtf8("blockS_colorOptionBlock"));
        sizePolicy2.setHeightForWidth(blockS_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockS_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockS_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockS_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockS_colorOptionBlock);

        blockZ_colorOptionBlock = new colorOptionBlock(videoTab);
        blockZ_colorOptionBlock->setObjectName(QString::fromUtf8("blockZ_colorOptionBlock"));
        sizePolicy2.setHeightForWidth(blockZ_colorOptionBlock->sizePolicy().hasHeightForWidth());
        blockZ_colorOptionBlock->setSizePolicy(sizePolicy2);
        blockZ_colorOptionBlock->setMinimumSize(QSize(0, 100));
        blockZ_colorOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_3->addWidget(blockZ_colorOptionBlock);

        tabWidget->addTab(videoTab, QString());
        keyboardTab = new QWidget();
        keyboardTab->setObjectName(QString::fromUtf8("keyboardTab"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Agency FB"));
        font3.setPointSize(14);
        keyboardTab->setFont(font3);
        verticalLayout_4 = new QVBoxLayout(keyboardTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        left_keyOptionBlock = new keyOptionBlock(keyboardTab);
        left_keyOptionBlock->setObjectName(QString::fromUtf8("left_keyOptionBlock"));
        sizePolicy2.setHeightForWidth(left_keyOptionBlock->sizePolicy().hasHeightForWidth());
        left_keyOptionBlock->setSizePolicy(sizePolicy2);
        left_keyOptionBlock->setMinimumSize(QSize(0, 100));
        left_keyOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(left_keyOptionBlock);

        right_keyOptionBlock = new keyOptionBlock(keyboardTab);
        right_keyOptionBlock->setObjectName(QString::fromUtf8("right_keyOptionBlock"));
        sizePolicy2.setHeightForWidth(right_keyOptionBlock->sizePolicy().hasHeightForWidth());
        right_keyOptionBlock->setSizePolicy(sizePolicy2);
        right_keyOptionBlock->setMinimumSize(QSize(0, 100));
        right_keyOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(right_keyOptionBlock);

        down_keyOptionBlock = new keyOptionBlock(keyboardTab);
        down_keyOptionBlock->setObjectName(QString::fromUtf8("down_keyOptionBlock"));
        sizePolicy2.setHeightForWidth(down_keyOptionBlock->sizePolicy().hasHeightForWidth());
        down_keyOptionBlock->setSizePolicy(sizePolicy2);
        down_keyOptionBlock->setMinimumSize(QSize(0, 100));
        down_keyOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(down_keyOptionBlock);

        spin_keyOptionBlock = new keyOptionBlock(keyboardTab);
        spin_keyOptionBlock->setObjectName(QString::fromUtf8("spin_keyOptionBlock"));
        sizePolicy2.setHeightForWidth(spin_keyOptionBlock->sizePolicy().hasHeightForWidth());
        spin_keyOptionBlock->setSizePolicy(sizePolicy2);
        spin_keyOptionBlock->setMinimumSize(QSize(0, 100));
        spin_keyOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(spin_keyOptionBlock);

        pause_keyOptionBlock = new keyOptionBlock(keyboardTab);
        pause_keyOptionBlock->setObjectName(QString::fromUtf8("pause_keyOptionBlock"));
        sizePolicy2.setHeightForWidth(pause_keyOptionBlock->sizePolicy().hasHeightForWidth());
        pause_keyOptionBlock->setSizePolicy(sizePolicy2);
        pause_keyOptionBlock->setMinimumSize(QSize(0, 100));
        pause_keyOptionBlock->setMaximumSize(QSize(16777215, 100));

        verticalLayout_4->addWidget(pause_keyOptionBlock);

        tabWidget->addTab(keyboardTab, QString());
        profileTab = new QWidget();
        profileTab->setObjectName(QString::fromUtf8("profileTab"));
        tabWidget->addTab(profileTab, QString());
        label = new QLabel(SettingScene);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 70, 191, 101));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(36);
        label->setFont(font4);

        retranslateUi(SettingScene);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SettingScene);
    } // setupUi

    void retranslateUi(QWidget *SettingScene)
    {
        SettingScene->setWindowTitle(QCoreApplication::translate("SettingScene", "Form", nullptr));
        resetBtn->setText(QCoreApplication::translate("SettingScene", "\351\207\215\347\275\256", nullptr));
        settingBackBtn->setText(QCoreApplication::translate("SettingScene", "\350\277\224\345\233\236", nullptr));
        chooseMediaFileBtn->setText(QCoreApplication::translate("SettingScene", "\351\200\211\346\213\251\351\237\263\351\242\221", nullptr));
        tryListeningBtn->setText(QCoreApplication::translate("SettingScene", "\350\257\225\345\220\254", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(generalTab), QCoreApplication::translate("SettingScene", "\351\200\232\347\224\250", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(videoTab), QCoreApplication::translate("SettingScene", "\345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(keyboardTab), QCoreApplication::translate("SettingScene", "\351\224\256\347\233\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(profileTab), QCoreApplication::translate("SettingScene", "\345\255\230\346\241\243", nullptr));
        label->setText(QCoreApplication::translate("SettingScene", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingScene: public Ui_SettingScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSCENE_H
