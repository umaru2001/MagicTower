#include "floortrans.h"
#include "ui_floortrans.h"
#include<QMainWindow>

floortrans::floortrans(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::floortrans)
{
    ui->setupUi(this);
}

floortrans::~floortrans()
{
    delete ui;
}

void floortrans::keyPressEvent(QKeyEvent *event){
        if (event->key() == Qt::Key_Up||event->key() == Qt::Key_Down){
                switch (event->key()) {
                case Qt::Key_Up:
                    if (Tfloor != TOTAL_FLOOR)
                        Tfloor++;
                    break;
                case Qt::Key_Down:
                    if (Tfloor != 1)
                        Tfloor--;
                    break;
                }
            }
        if (event->key() == Qt::Key_Space) {
            floorswitch();
            this->close();
        }
        else if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_F) {
            this->close();
        }
        setText();
}


void floortrans::setText(){
    QImage img_background = QImage(":/new/prefix1/Images/Image 79.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);
    ui->labelname->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
    ui->labelup->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
    ui->label->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
    ui->labeldown->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
    ui->labelhint->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
    ui->labelexit->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
    ui->labelname->setText("楼层传送器");
    ui->labelup->setText("↑");
    ui->label->setText(QString::number(Tfloor));
    ui->labeldown->setText("↓");
    ui->labelhint->setText("按下空格键确认");
    ui->labelexit->setText("F取消");
}

int floortrans::atstairs(){
    int arrive = braver->pos_y*X+braver->pos_x;
    if (Tower[braver->floor][braver->pos_y * X + braver->pos_x] == 10) {
        braver->floor += 1;
        for (int _it = 0; _it <= X * Y - 1; _it++) {
            if (Tower[braver->floor][_it] == 11) {
                arrive = _it;
                break;
            }
        }
    }
    else if (Tower[braver->floor][braver->pos_y * X + braver->pos_x] == 11) {
        braver->floor -= 1;
        for (int _it = 0; _it <= X * Y - 1; _it++) {
            if (Tower[braver->floor][_it] == 10) {
                arrive = _it;
                break;
            }
        }

    }
    return arrive;
}

void floortrans::floorswitch(){
    int arrive = 0;//目标到达地点
     if (Tfloor < braver->floor ) {//下n楼
            braver->floor = Tfloor;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[braver->floor][_it] == 10) {
                    arrive = _it;
                    break;
                }
            }
    }
      else if (Tfloor > braver->floor ) {//上n楼
            braver->floor = Tfloor ;
            for (int _it = 0; _it <= X * Y - 1; _it++) {
                if (Tower[braver->floor][_it] == 11) {
                    arrive = _it;
                    break;
                }

            }
        }
     else if (Tfloor == braver->floor) {
       arrive = braver->pos_x+braver->pos_y*X;
     }
        braver->pos_x = arrive % X;
        braver->pos_y = arrive / X;
        emit refresh();
}
