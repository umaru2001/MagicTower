#include "Information.h"
#include<QMenuBar>
#include<QPainter>
#include"mypushbutton.h"
#include<QTimer>

Information::Information(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(510,506);
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));

    this->setWindowTitle("游戏说明");

    QMenuBar * bar = this->menuBar();

    this->setMenuBar(bar);

    QMenu * startMenu = bar->addMenu("开始");

    QAction * quitAction = startMenu->addAction("退出");

    connect(quitAction,&QAction::triggered,[=](){this->close();});
    MyPushButton * closeBtn = new MyPushButton(":/Titles/close.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),20);
    connect(closeBtn,&QPushButton::clicked,[=]()
    {
        closeBtn->zoom1();
        closeBtn->zoom2();
        QTimer::singleShot(500,this,[=]()
        {
            this->hide();
            emit this->back();
        });
    });
}
void Information::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Titles/Information.png");
    painter.drawPixmap(0,0,510,506,pix);
}
