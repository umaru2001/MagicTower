#include "beginning.h"
#include "ui_beginning.h"
#include"mypushbutton.h"
#include<QTimer>
#include"Information.h"
#include<QDebug>
#include<QPainter>
#include"mainwindow.h"

Beginning::Beginning(QWidget *parent): QMainWindow(parent), ui(new Ui::Beginning)
{
    ui->setupUi(this);
    this->setFixedSize(510,506);
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));

    this->setWindowTitle("魔塔");
    connect(ui->actionquit,&QAction::triggered,[=]()
    {
        this->close();
    });
    info = new Information;
    main = new MainWindow;

    MyPushButton *startBtn = new MyPushButton(":/Titles/start.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.4);
    MyPushButton *infoBtn = new MyPushButton(":/Titles/info.png");
    infoBtn->setParent(this);
    infoBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.8);
    connect(startBtn,&QPushButton::clicked,[=]()
    {
        startBtn->zoom1();
        startBtn->zoom2();

        QTimer::singleShot(500,this,[=]()
        {
            this->hide();
            main->setGeometry(this->geometry());
            main->show();
            main->game_start();

        });

    });
    connect(infoBtn,&QPushButton::clicked,[=]()
    {
        infoBtn->zoom1();
        infoBtn->zoom2();
        QTimer::singleShot(500,this,[=]()
        {
            this->hide();
            info->setGeometry(this->geometry());
            info->show();

        });
    });
    connect(info,&Information::back,[=](){
                    this->setGeometry(info->geometry());
                    this->show();
                });
    connect(main,&MainWindow::back,[=](){
                    this->setGeometry(main->geometry());
                    this->show();
                });
    MyPushButton *loadBtn = new MyPushButton(":/Titles/load.png");
    loadBtn->setParent(this);
    loadBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()*0.6);
    connect(loadBtn,&QPushButton::clicked,[=]()
    {
        loadBtn->zoom1();
        loadBtn->zoom2();
    });






}



Beginning::~Beginning()
{
    delete ui;
}

