/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *Mystatus_01;
    QGraphicsView *Mystatus_03;
    QGraphicsView *Game_print_down;
    QWidget *formLayoutWidget;
    QFormLayout *Mystatus_02;
    QLabel *mylv;
    QLabel *my_lv;
    QLabel *myhp;
    QLabel *my_hp;
    QLabel *myat;
    QLabel *my_at;
    QLabel *mydf;
    QLabel *my_df;
    QLabel *myexp;
    QLabel *my_exp;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *my_ykey;
    QLabel *my_bkey;
    QLabel *my_rkey;
    QLabel *my_gold;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *mystatus;
    QLabel *my_status;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *floor_status;
    QLabel *floor;
    QGraphicsView *floor_graphics;
    QGraphicsView *Game_print_up;
    QTextBrowser *system_status;
    QTextBrowser *item_status;
    QGraphicsView *graphicsView_4;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QGraphicsView *graphicsView_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(511, 534);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Mystatus_01 = new QGraphicsView(centralwidget);
        Mystatus_01->setObjectName(QString::fromUtf8("Mystatus_01"));
        Mystatus_01->setGeometry(QRect(20, 30, 101, 211));
        Mystatus_03 = new QGraphicsView(centralwidget);
        Mystatus_03->setObjectName(QString::fromUtf8("Mystatus_03"));
        Mystatus_03->setGeometry(QRect(20, 258, 101, 130));
        Game_print_down = new QGraphicsView(centralwidget);
        Game_print_down->setObjectName(QString::fromUtf8("Game_print_down"));
        Game_print_down->setGeometry(QRect(140, 30, 354, 354));
        Game_print_down->setMinimumSize(QSize(352, 352));
        Game_print_down->setMaximumSize(QSize(3520, 3520));
        Game_print_down->setSizeIncrement(QSize(352, 352));
        Game_print_down->setBaseSize(QSize(352, 352));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 80, 101, 111));
        Mystatus_02 = new QFormLayout(formLayoutWidget);
        Mystatus_02->setObjectName(QString::fromUtf8("Mystatus_02"));
        Mystatus_02->setHorizontalSpacing(6);
        Mystatus_02->setVerticalSpacing(7);
        Mystatus_02->setContentsMargins(2, 11, 0, 0);
        mylv = new QLabel(formLayoutWidget);
        mylv->setObjectName(QString::fromUtf8("mylv"));

        Mystatus_02->setWidget(0, QFormLayout::LabelRole, mylv);

        my_lv = new QLabel(formLayoutWidget);
        my_lv->setObjectName(QString::fromUtf8("my_lv"));
        my_lv->setContextMenuPolicy(Qt::ActionsContextMenu);
        my_lv->setLayoutDirection(Qt::LeftToRight);
        my_lv->setAutoFillBackground(false);
        my_lv->setAlignment(Qt::AlignCenter);

        Mystatus_02->setWidget(0, QFormLayout::FieldRole, my_lv);

        myhp = new QLabel(formLayoutWidget);
        myhp->setObjectName(QString::fromUtf8("myhp"));

        Mystatus_02->setWidget(1, QFormLayout::LabelRole, myhp);

        my_hp = new QLabel(formLayoutWidget);
        my_hp->setObjectName(QString::fromUtf8("my_hp"));
        my_hp->setContextMenuPolicy(Qt::ActionsContextMenu);
        my_hp->setAlignment(Qt::AlignCenter);
        my_hp->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        Mystatus_02->setWidget(1, QFormLayout::FieldRole, my_hp);

        myat = new QLabel(formLayoutWidget);
        myat->setObjectName(QString::fromUtf8("myat"));

        Mystatus_02->setWidget(2, QFormLayout::LabelRole, myat);

        my_at = new QLabel(formLayoutWidget);
        my_at->setObjectName(QString::fromUtf8("my_at"));
        my_at->setContextMenuPolicy(Qt::ActionsContextMenu);
        my_at->setAlignment(Qt::AlignCenter);
        my_at->setOpenExternalLinks(true);
        my_at->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        Mystatus_02->setWidget(2, QFormLayout::FieldRole, my_at);

        mydf = new QLabel(formLayoutWidget);
        mydf->setObjectName(QString::fromUtf8("mydf"));

        Mystatus_02->setWidget(3, QFormLayout::LabelRole, mydf);

        my_df = new QLabel(formLayoutWidget);
        my_df->setObjectName(QString::fromUtf8("my_df"));
        my_df->setContextMenuPolicy(Qt::ActionsContextMenu);
        my_df->setAlignment(Qt::AlignCenter);
        my_df->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        Mystatus_02->setWidget(3, QFormLayout::FieldRole, my_df);

        myexp = new QLabel(formLayoutWidget);
        myexp->setObjectName(QString::fromUtf8("myexp"));

        Mystatus_02->setWidget(4, QFormLayout::LabelRole, myexp);

        my_exp = new QLabel(formLayoutWidget);
        my_exp->setObjectName(QString::fromUtf8("my_exp"));
        my_exp->setContextMenuPolicy(Qt::ActionsContextMenu);
        my_exp->setAlignment(Qt::AlignCenter);
        my_exp->setWordWrap(false);
        my_exp->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        Mystatus_02->setWidget(4, QFormLayout::FieldRole, my_exp);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 260, 51, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        my_ykey = new QLabel(verticalLayoutWidget);
        my_ykey->setObjectName(QString::fromUtf8("my_ykey"));
        my_ykey->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(my_ykey);

        my_bkey = new QLabel(verticalLayoutWidget);
        my_bkey->setObjectName(QString::fromUtf8("my_bkey"));
        my_bkey->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(my_bkey);

        my_rkey = new QLabel(verticalLayoutWidget);
        my_rkey->setObjectName(QString::fromUtf8("my_rkey"));
        my_rkey->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(my_rkey);

        my_gold = new QLabel(verticalLayoutWidget);
        my_gold->setObjectName(QString::fromUtf8("my_gold"));
        my_gold->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(my_gold);

        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(60, 30, 62, 51));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        mystatus = new QLabel(verticalLayoutWidget_2);
        mystatus->setObjectName(QString::fromUtf8("mystatus"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\261\211\344\273\252\345\244\217\346\227\245\344\275\223W"));
        font.setBold(false);
        font.setWeight(50);
        mystatus->setFont(font);

        verticalLayout_2->addWidget(mystatus);

        my_status = new QLabel(verticalLayoutWidget_2);
        my_status->setObjectName(QString::fromUtf8("my_status"));
        my_status->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(my_status);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(280, 0, 71, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        floor_status = new QLabel(horizontalLayoutWidget);
        floor_status->setObjectName(QString::fromUtf8("floor_status"));
        floor_status->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(floor_status);

        floor = new QLabel(horizontalLayoutWidget);
        floor->setObjectName(QString::fromUtf8("floor"));
        floor->setLayoutDirection(Qt::LeftToRight);
        floor->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(floor);

        floor_graphics = new QGraphicsView(centralwidget);
        floor_graphics->setObjectName(QString::fromUtf8("floor_graphics"));
        floor_graphics->setGeometry(QRect(280, 0, 71, 31));
        Game_print_up = new QGraphicsView(centralwidget);
        Game_print_up->setObjectName(QString::fromUtf8("Game_print_up"));
        Game_print_up->setGeometry(QRect(140, 30, 354, 354));
        Game_print_up->setMinimumSize(QSize(352, 352));
        Game_print_up->setMaximumSize(QSize(3520, 3520));
        Game_print_up->setSizeIncrement(QSize(352, 352));
        Game_print_up->setBaseSize(QSize(352, 352));
        system_status = new QTextBrowser(centralwidget);
        system_status->setObjectName(QString::fromUtf8("system_status"));
        system_status->setGeometry(QRect(20, 400, 471, 41));
        item_status = new QTextBrowser(centralwidget);
        item_status->setObjectName(QString::fromUtf8("item_status"));
        item_status->setGeometry(QRect(20, 450, 471, 31));
        graphicsView_4 = new QGraphicsView(centralwidget);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        graphicsView_4->setGeometry(QRect(21, 292, 32, 32));
        graphicsView_4->setMinimumSize(QSize(32, 32));
        graphicsView_4->setMaximumSize(QSize(32, 32));
        graphicsView_5 = new QGraphicsView(centralwidget);
        graphicsView_5->setObjectName(QString::fromUtf8("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(21, 324, 32, 32));
        graphicsView_5->setMinimumSize(QSize(32, 32));
        graphicsView_5->setMaximumSize(QSize(32, 32));
        graphicsView_6 = new QGraphicsView(centralwidget);
        graphicsView_6->setObjectName(QString::fromUtf8("graphicsView_6"));
        graphicsView_6->setGeometry(QRect(21, 356, 32, 32));
        graphicsView_6->setMinimumSize(QSize(32, 32));
        graphicsView_6->setMaximumSize(QSize(32, 32));
        graphicsView_3 = new QGraphicsView(centralwidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(21, 260, 32, 32));
        graphicsView_3->setMinimumSize(QSize(32, 32));
        graphicsView_3->setMaximumSize(QSize(32, 32));
        MainWindow->setCentralWidget(centralwidget);
        Game_print_down->raise();
        Game_print_up->raise();
        floor_graphics->raise();
        Mystatus_01->raise();
        Mystatus_03->raise();
        formLayoutWidget->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();
        horizontalLayoutWidget->raise();
        system_status->raise();
        item_status->raise();
        graphicsView_4->raise();
        graphicsView_5->raise();
        graphicsView_6->raise();
        graphicsView_3->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 511, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        mylv->setText(QCoreApplication::translate("MainWindow", "\347\255\211\347\272\247", nullptr));
        my_lv->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        myhp->setText(QCoreApplication::translate("MainWindow", "\344\275\223\345\212\233", nullptr));
        my_hp->setText(QCoreApplication::translate("MainWindow", "900", nullptr));
        myat->setText(QCoreApplication::translate("MainWindow", "\346\224\273\345\207\273", nullptr));
        my_at->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        mydf->setText(QCoreApplication::translate("MainWindow", "\351\230\262\345\276\241", nullptr));
        my_df->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        myexp->setText(QCoreApplication::translate("MainWindow", "\347\273\217\351\252\214\345\200\274", nullptr));
        my_exp->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        my_ykey->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        my_bkey->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        my_rkey->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        my_gold->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        mystatus->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        my_status->setText(QCoreApplication::translate("MainWindow", "\346\255\243\345\270\270", nullptr));
        floor_status->setText(QCoreApplication::translate("MainWindow", "\344\270\273\345\241\224", nullptr));
        floor->setText(QCoreApplication::translate("MainWindow", "1F", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
