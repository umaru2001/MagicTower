#include "dmsdoor.h"
#include "ui_dmsdoor.h"
#include "mainwindow.h"

//dmsdoor *wdmsdoor;
dmsdoor::dmsdoor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dmsdoor)
{
    ui->setupUi(this);
    this->setFixedSize(203,188);
    ui->label->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->label_2->setStyleSheet("QLabel {color:orange;font: bold 13px;}");
    ui->label_3->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->my_dmsdoor->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    QImage img_background = QImage(":/new/prefix1/Images/Image 79.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));
    this->setWindowTitle("任意门");
    gain = new QSound("D:/C++/magicTower/Music/Sound_tx/gain.wav");
    gain->setLoops(1);
}

dmsdoor::~dmsdoor()
{
    delete ui;
}

void dmsdoor::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Return)
    {
        is_falsewall();
        this->close();
    }
    else if(event->key()==Qt::Key_T)
    {
        this->close();
    }
}

void dmsdoor::set_text()
{
    ui->my_dmsdoor->setText(QString::number(braver->dms_door));
}

void dmsdoor::is_falsewall()
{
    if(braver->dms_door>0)
    {
        if(olddata == 26)
        {
            Tower[braver->floor][pos] = 21;
        }
        else if(olddata>=27&&olddata<=30)
        {
            Tower[braver->floor][pos] = 13;
        }
        gain->play();
        braver->dms_door--;
    }
    else
    {
        vars->hint_msg="您的任意门不够！";
    }
}

void dmsdoor::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}
