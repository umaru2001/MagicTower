/********************************************************************************
** Form generated from reading UI file 'beginning.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEGINNING_H
#define UI_BEGINNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Beginning
{
public:
    QAction *actionquit;
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *Beginning)
    {
        if (Beginning->objectName().isEmpty())
            Beginning->setObjectName(QString::fromUtf8("Beginning"));
        Beginning->resize(755, 600);
        actionquit = new QAction(Beginning);
        actionquit->setObjectName(QString::fromUtf8("actionquit"));
        centralwidget = new QWidget(Beginning);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -10, 612, 527));
        Beginning->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Beginning);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 755, 26));
        menubar->setStyleSheet(QString::fromUtf8(""));
        menubar->setNativeMenuBar(true);
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Beginning->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionquit);

        retranslateUi(Beginning);

        QMetaObject::connectSlotsByName(Beginning);
    } // setupUi

    void retranslateUi(QMainWindow *Beginning)
    {
        Beginning->setWindowTitle(QCoreApplication::translate("Beginning", "Beginning", nullptr));
        actionquit->setText(QCoreApplication::translate("Beginning", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("Beginning", "<html><head/><body><p><img src=\":/Titles/bg.png\"/></p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("Beginning", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Beginning: public Ui_Beginning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEGINNING_H
