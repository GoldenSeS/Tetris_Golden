/********************************************************************************
** Form generated from reading UI file 'optionblock.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONBLOCK_H
#define UI_OPTIONBLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optionBlock
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QWidget *optionBlock)
    {
        if (optionBlock->objectName().isEmpty())
            optionBlock->setObjectName(QString::fromUtf8("optionBlock"));
        optionBlock->resize(269, 94);
        verticalLayout = new QVBoxLayout(optionBlock);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(optionBlock);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(20);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(14);
        spinBox->setFont(font1);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addWidget(widget);

        horizontalSlider = new QSlider(optionBlock);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        retranslateUi(optionBlock);

        QMetaObject::connectSlotsByName(optionBlock);
    } // setupUi

    void retranslateUi(QWidget *optionBlock)
    {
        optionBlock->setWindowTitle(QCoreApplication::translate("optionBlock", "Form", nullptr));
        label->setText(QCoreApplication::translate("optionBlock", "\346\240\207\347\255\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class optionBlock: public Ui_optionBlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONBLOCK_H
