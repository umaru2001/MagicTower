#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include<QWidget>
#include<QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString normalImg);

    QString normalImgPath;  //默认显示图片路径
    void zoom1();
    void zoom2();

signals:

};

#endif // MYPUSHBUTTON_H
