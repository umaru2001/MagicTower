#include "mypushbutton.h"
#include<QPushButton>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImg)
{
    normalImgPath = normalImg;
    QPixmap pixmap;
    pixmap.load(normalImgPath);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setIcon(pixmap);
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
void MyPushButton::zoom1()
{
    //创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();
}

void MyPushButton::zoom2()
{
    QPropertyAnimation * animation1 =  new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}
