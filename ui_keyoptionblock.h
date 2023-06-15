/********************************************************************************
** Form generated from reading UI file 'keyoptionblock.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYOPTIONBLOCK_H
#define UI_KEYOPTIONBLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_keyOptionBlock
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *keyLabel;
    QLineEdit *keyLineEdit;
    QPushButton *resetBtn;

    void setupUi(QWidget *keyOptionBlock)
    {
        if (keyOptionBlock->objectName().isEmpty())
            keyOptionBlock->setObjectName(QString::fromUtf8("keyOptionBlock"));
        keyOptionBlock->resize(363, 78);
        horizontalLayout = new QHBoxLayout(keyOptionBlock);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        keyLabel = new QLabel(keyOptionBlock);
        keyLabel->setObjectName(QString::fromUtf8("keyLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(20);
        keyLabel->setFont(font);

        horizontalLayout->addWidget(keyLabel);

        keyLineEdit = new QLineEdit(keyOptionBlock);
        keyLineEdit->setObjectName(QString::fromUtf8("keyLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(keyLineEdit->sizePolicy().hasHeightForWidth());
        keyLineEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(16);
        keyLineEdit->setFont(font1);
        keyLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(keyLineEdit);

        resetBtn = new QPushButton(keyOptionBlock);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resetBtn->sizePolicy().hasHeightForWidth());
        resetBtn->setSizePolicy(sizePolicy1);
        resetBtn->setMinimumSize(QSize(140, 0));
        resetBtn->setMaximumSize(QSize(140, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font2.setPointSize(16);
        resetBtn->setFont(font2);

        horizontalLayout->addWidget(resetBtn);


        retranslateUi(keyOptionBlock);

        QMetaObject::connectSlotsByName(keyOptionBlock);
    } // setupUi

    void retranslateUi(QWidget *keyOptionBlock)
    {
        keyOptionBlock->setWindowTitle(QCoreApplication::translate("keyOptionBlock", "Form", nullptr));
        keyLabel->setText(QCoreApplication::translate("keyOptionBlock", "\350\257\264\346\230\216", nullptr));
        resetBtn->setText(QCoreApplication::translate("keyOptionBlock", "\351\207\215\350\256\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class keyOptionBlock: public Ui_keyOptionBlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYOPTIONBLOCK_H
