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
        if(Tower[braver->floor][(braver->pos_y+1) * X + braver->pos_x] == 26&&braver->face==0)
        {
            Tower[braver->floor][(braver->pos_y+1) * X + braver->pos_x] = 21;
        }
        else if(Tower[braver->floor][(braver->pos_y-1) * X + braver->pos_x] == 26&&braver->face==3)
        {
            Tower[braver->floor][(braver->pos_y-1) * X + braver->pos_x] = 21;
        }
        else if(Tower[braver->floor][braver->pos_y * X + braver->pos_x-1] == 26&&braver->face==1)
        {
            Tower[braver->floor][braver->pos_y * X + braver->pos_x-1] = 21;
        }
        else if(Tower[braver->floor][braver->pos_y * X + braver->pos_x+1] == 26&&braver->face==2)
        {
            Tower[braver->floor][braver->pos_y * X + braver->pos_x+1] = 21;
        }
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
