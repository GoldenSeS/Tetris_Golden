/********************************************************************************
** Form generated from reading UI file 'rankingsscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKINGSSCENE_H
#define UI_RANKINGSSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RankingsScene
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *rankwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *numLabel;
    QLabel *nameLabel;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *scoreLabel;
    QLabel *timeLabel;
    QWidget *rankwidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *numLabel_2;
    QLabel *nameLabel_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *scoreLabel_2;
    QLabel *timeLabel_2;
    QWidget *rankwidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *numLabel_3;
    QLabel *nameLabel_3;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *scoreLabel_3;
    QLabel *timeLabel_3;
    QWidget *rankwidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *numLabel_4;
    QLabel *nameLabel_4;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *scoreLabel_4;
    QLabel *timeLabel_4;
    QPushButton *backBtn;
    QLabel *ss;

    void setupUi(QWidget *RankingsScene)
    {
        if (RankingsScene->objectName().isEmpty())
            RankingsScene->setObjectName(QString::fromUtf8("RankingsScene"));
        RankingsScene->resize(800, 1000);
        RankingsScene->setMinimumSize(QSize(800, 1000));
        RankingsScene->setMaximumSize(QSize(800, 1000));
        widget = new QWidget(RankingsScene);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 150, 601, 691));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rankwidget = new QWidget(widget);
        rankwidget->setObjectName(QString::fromUtf8("rankwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rankwidget->sizePolicy().hasHeightForWidth());
        rankwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(rankwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        numLabel = new QLabel(rankwidget);
        numLabel->setObjectName(QString::fromUtf8("numLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(numLabel->sizePolicy().hasHeightForWidth());
        numLabel->setSizePolicy(sizePolicy1);
        numLabel->setMinimumSize(QSize(100, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(72);
        numLabel->setFont(font);
        numLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(numLabel);

        nameLabel = new QLabel(rankwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        sizePolicy1.setHeightForWidth(nameLabel->sizePolicy().hasHeightForWidth());
        nameLabel->setSizePolicy(sizePolicy1);
        nameLabel->setMinimumSize(QSize(300, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font1.setPointSize(28);
        nameLabel->setFont(font1);
        nameLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(nameLabel);

        widget_3 = new QWidget(rankwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMinimumSize(QSize(100, 0));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scoreLabel = new QLabel(widget_3);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scoreLabel->sizePolicy().hasHeightForWidth());
        scoreLabel->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(16);
        scoreLabel->setFont(font2);
        scoreLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(scoreLabel);

        timeLabel = new QLabel(widget_3);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        sizePolicy2.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy2);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Agency FB"));
        font3.setPointSize(14);
        timeLabel->setFont(font3);
        timeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(timeLabel);


        horizontalLayout->addWidget(widget_3);


        verticalLayout_2->addWidget(rankwidget);

        rankwidget_2 = new QWidget(widget);
        rankwidget_2->setObjectName(QString::fromUtf8("rankwidget_2"));
        sizePolicy.setHeightForWidth(rankwidget_2->sizePolicy().hasHeightForWidth());
        rankwidget_2->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(rankwidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        numLabel_2 = new QLabel(rankwidget_2);
        numLabel_2->setObjectName(QString::fromUtf8("numLabel_2"));
        sizePolicy1.setHeightForWidth(numLabel_2->sizePolicy().hasHeightForWidth());
        numLabel_2->setSizePolicy(sizePolicy1);
        numLabel_2->setMinimumSize(QSize(100, 0));
        numLabel_2->setFont(font);
        numLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(numLabel_2);

        nameLabel_2 = new QLabel(rankwidget_2);
        nameLabel_2->setObjectName(QString::fromUtf8("nameLabel_2"));
        sizePolicy1.setHeightForWidth(nameLabel_2->sizePolicy().hasHeightForWidth());
        nameLabel_2->setSizePolicy(sizePolicy1);
        nameLabel_2->setMinimumSize(QSize(300, 0));
        nameLabel_2->setFont(font1);
        nameLabel_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(nameLabel_2);

        widget_4 = new QWidget(rankwidget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(100, 0));
        verticalLayout_3 = new QVBoxLayout(widget_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scoreLabel_2 = new QLabel(widget_4);
        scoreLabel_2->setObjectName(QString::fromUtf8("scoreLabel_2"));
        sizePolicy2.setHeightForWidth(scoreLabel_2->sizePolicy().hasHeightForWidth());
        scoreLabel_2->setSizePolicy(sizePolicy2);
        scoreLabel_2->setFont(font2);
        scoreLabel_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(scoreLabel_2);

        timeLabel_2 = new QLabel(widget_4);
        timeLabel_2->setObjectName(QString::fromUtf8("timeLabel_2"));
        sizePolicy2.setHeightForWidth(timeLabel_2->sizePolicy().hasHeightForWidth());
        timeLabel_2->setSizePolicy(sizePolicy2);
        timeLabel_2->setFont(font3);
        timeLabel_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(timeLabel_2);


        horizontalLayout_2->addWidget(widget_4);


        verticalLayout_2->addWidget(rankwidget_2);

        rankwidget_3 = new QWidget(widget);
        rankwidget_3->setObjectName(QString::fromUtf8("rankwidget_3"));
        sizePolicy.setHeightForWidth(rankwidget_3->sizePolicy().hasHeightForWidth());
        rankwidget_3->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(rankwidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        numLabel_3 = new QLabel(rankwidget_3);
        numLabel_3->setObjectName(QString::fromUtf8("numLabel_3"));
        sizePolicy1.setHeightForWidth(numLabel_3->sizePolicy().hasHeightForWidth());
        numLabel_3->setSizePolicy(sizePolicy1);
        numLabel_3->setMinimumSize(QSize(100, 0));
        numLabel_3->setFont(font);
        numLabel_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(numLabel_3);

        nameLabel_3 = new QLabel(rankwidget_3);
        nameLabel_3->setObjectName(QString::fromUtf8("nameLabel_3"));
        sizePolicy1.setHeightForWidth(nameLabel_3->sizePolicy().hasHeightForWidth());
        nameLabel_3->setSizePolicy(sizePolicy1);
        nameLabel_3->setMinimumSize(QSize(300, 0));
        nameLabel_3->setFont(font1);
        nameLabel_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(nameLabel_3);

        widget_5 = new QWidget(rankwidget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        sizePolicy1.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy1);
        widget_5->setMinimumSize(QSize(100, 0));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scoreLabel_3 = new QLabel(widget_5);
        scoreLabel_3->setObjectName(QString::fromUtf8("scoreLabel_3"));
        sizePolicy2.setHeightForWidth(scoreLabel_3->sizePolicy().hasHeightForWidth());
        scoreLabel_3->setSizePolicy(sizePolicy2);
        scoreLabel_3->setFont(font2);
        scoreLabel_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(scoreLabel_3);

        timeLabel_3 = new QLabel(widget_5);
        timeLabel_3->setObjectName(QString::fromUtf8("timeLabel_3"));
        sizePolicy2.setHeightForWidth(timeLabel_3->sizePolicy().hasHeightForWidth());
        timeLabel_3->setSizePolicy(sizePolicy2);
        timeLabel_3->setFont(font3);
        timeLabel_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(timeLabel_3);


        horizontalLayout_3->addWidget(widget_5);


        verticalLayout_2->addWidget(rankwidget_3);

        rankwidget_4 = new QWidget(widget);
        rankwidget_4->setObjectName(QString::fromUtf8("rankwidget_4"));
        sizePolicy.setHeightForWidth(rankwidget_4->sizePolicy().hasHeightForWidth());
        rankwidget_4->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(rankwidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        numLabel_4 = new QLabel(rankwidget_4);
        numLabel_4->setObjectName(QString::fromUtf8("numLabel_4"));
        sizePolicy1.setHeightForWidth(numLabel_4->sizePolicy().hasHeightForWidth());
        numLabel_4->setSizePolicy(sizePolicy1);
        numLabel_4->setMinimumSize(QSize(100, 0));
        numLabel_4->setFont(font);
        numLabel_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(numLabel_4);

        nameLabel_4 = new QLabel(rankwidget_4);
        nameLabel_4->setObjectName(QString::fromUtf8("nameLabel_4"));
        sizePolicy1.setHeightForWidth(nameLabel_4->sizePolicy().hasHeightForWidth());
        nameLabel_4->setSizePolicy(sizePolicy1);
        nameLabel_4->setMinimumSize(QSize(300, 0));
        nameLabel_4->setFont(font1);
        nameLabel_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(nameLabel_4);

        widget_6 = new QWidget(rankwidget_4);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        sizePolicy1.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy1);
        widget_6->setMinimumSize(QSize(100, 0));
        verticalLayout_5 = new QVBoxLayout(widget_6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        scoreLabel_4 = new QLabel(widget_6);
        scoreLabel_4->setObjectName(QString::fromUtf8("scoreLabel_4"));
        sizePolicy2.setHeightForWidth(scoreLabel_4->sizePolicy().hasHeightForWidth());
        scoreLabel_4->setSizePolicy(sizePolicy2);
        scoreLabel_4->setFont(font2);
        scoreLabel_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(scoreLabel_4);

        timeLabel_4 = new QLabel(widget_6);
        timeLabel_4->setObjectName(QString::fromUtf8("timeLabel_4"));
        sizePolicy2.setHeightForWidth(timeLabel_4->sizePolicy().hasHeightForWidth());
        timeLabel_4->setSizePolicy(sizePolicy2);
        timeLabel_4->setFont(font3);
        timeLabel_4->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(timeLabel_4);


        horizontalLayout_4->addWidget(widget_6);


        verticalLayout_2->addWidget(rankwidget_4);

        backBtn = new QPushButton(RankingsScene);
        backBtn->setObjectName(QString::fromUtf8("backBtn"));
        backBtn->setGeometry(QRect(610, 880, 111, 61));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font4.setPointSize(16);
        backBtn->setFont(font4);
        ss = new QLabel(RankingsScene);
        ss->setObjectName(QString::fromUtf8("ss"));
        ss->setGeometry(QRect(30, 50, 241, 111));
        sizePolicy1.setHeightForWidth(ss->sizePolicy().hasHeightForWidth());
        ss->setSizePolicy(sizePolicy1);
        ss->setFont(font1);
        ss->setAlignment(Qt::AlignCenter);

        retranslateUi(RankingsScene);

        QMetaObject::connectSlotsByName(RankingsScene);
    } // setupUi

    void retranslateUi(QWidget *RankingsScene)
    {
        RankingsScene->setWindowTitle(QCoreApplication::translate("RankingsScene", "Form", nullptr));
        numLabel->setText(QCoreApplication::translate("RankingsScene", "1", nullptr));
        nameLabel->setText(QCoreApplication::translate("RankingsScene", "\346\265\213\350\257\225\347\224\250\344\276\213", nullptr));
        scoreLabel->setText(QCoreApplication::translate("RankingsScene", "score", nullptr));
        timeLabel->setText(QCoreApplication::translate("RankingsScene", "time", nullptr));
        numLabel_2->setText(QCoreApplication::translate("RankingsScene", "2", nullptr));
        nameLabel_2->setText(QCoreApplication::translate("RankingsScene", "\346\265\213\350\257\225\347\224\250\344\276\213", nullptr));
        scoreLabel_2->setText(QCoreApplication::translate("RankingsScene", "score", nullptr));
        timeLabel_2->setText(QCoreApplication::translate("RankingsScene", "time", nullptr));
        numLabel_3->setText(QCoreApplication::translate("RankingsScene", "3", nullptr));
        nameLabel_3->setText(QCoreApplication::translate("RankingsScene", "\346\265\213\350\257\225\347\224\250\344\276\213", nullptr));
        scoreLabel_3->setText(QCoreApplication::translate("RankingsScene", "score", nullptr));
        timeLabel_3->setText(QCoreApplication::translate("RankingsScene", "time", nullptr));
        numLabel_4->setText(QCoreApplication::translate("RankingsScene", "4", nullptr));
        nameLabel_4->setText(QCoreApplication::translate("RankingsScene", "\346\265\213\350\257\225\347\224\250\344\276\213", nullptr));
        scoreLabel_4->setText(QCoreApplication::translate("RankingsScene", "score", nullptr));
        timeLabel_4->setText(QCoreApplication::translate("RankingsScene", "time", nullptr));
        backBtn->setText(QCoreApplication::translate("RankingsScene", "\350\277\224\345\233\236", nullptr));
        ss->setText(QCoreApplication::translate("RankingsScene", "\346\216\222\350\241\214\346\246\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RankingsScene: public Ui_RankingsScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKINGSSCENE_H
