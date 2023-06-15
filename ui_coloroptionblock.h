/********************************************************************************
** Form generated from reading UI file 'coloroptionblock.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLOROPTIONBLOCK_H
#define UI_COLOROPTIONBLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_colorOptionBlock
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *colorLineEdit;
    QPushButton *selectColorBtn;

    void setupUi(QWidget *colorOptionBlock)
    {
        if (colorOptionBlock->objectName().isEmpty())
            colorOptionBlock->setObjectName(QString::fromUtf8("colorOptionBlock"));
        colorOptionBlock->resize(343, 98);
        horizontalLayout = new QHBoxLayout(colorOptionBlock);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        colorLineEdit = new QLineEdit(colorOptionBlock);
        colorLineEdit->setObjectName(QString::fromUtf8("colorLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorLineEdit->sizePolicy().hasHeightForWidth());
        colorLineEdit->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(20);
        colorLineEdit->setFont(font);

        horizontalLayout->addWidget(colorLineEdit);

        selectColorBtn = new QPushButton(colorOptionBlock);
        selectColorBtn->setObjectName(QString::fromUtf8("selectColorBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectColorBtn->sizePolicy().hasHeightForWidth());
        selectColorBtn->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(14);
        selectColorBtn->setFont(font1);

        horizontalLayout->addWidget(selectColorBtn);


        retranslateUi(colorOptionBlock);

        QMetaObject::connectSlotsByName(colorOptionBlock);
    } // setupUi

    void retranslateUi(QWidget *colorOptionBlock)
    {
        colorOptionBlock->setWindowTitle(QCoreApplication::translate("colorOptionBlock", "Form", nullptr));
        selectColorBtn->setText(QCoreApplication::translate("colorOptionBlock", "\346\226\271\345\235\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class colorOptionBlock: public Ui_colorOptionBlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLOROPTIONBLOCK_H
