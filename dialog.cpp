#include "dialog.h"
#include "ui_dialog.h"

dialog::dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));
    this->setWindowTitle("对话");
    QImage img_background = QImage(":/new/prefix1/Images/Image 79.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);
}

dialog::~dialog()
{
    delete ui;
}

void dialog::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Return)
    {
        this->close();
    }
}

void dialog::dialog_1f()
{
    ui->name_npc->setText("妖精");
    ui->name_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->dialog_npc->setText("哈哈哈哈，闯塔没有一点帮助可是不行的呀！我这里有两件宝物，你拿去用吧！希望它们对你有一点帮助！");
    ui->dialog_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    braver->book+=1;
    braver->floor_up+=1;
    vars->hint_msg="获得了楼层传送器和心镜 心镜可以用来查看怪物的数据";
}

void dialog::dialog_11f()
{
    ui->name_npc->setText("妖精");
    ui->name_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->dialog_npc->setText("留意一些角落，可能会有暗墙，暗墙的背后往往有密室，密室里好东西可多了。");
    ui->dialog_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
}

void dialog::dialog_12f()
{
    ui->name_npc->setText("妖精");
    ui->name_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->dialog_npc->setText("真没想到你都这么强了还记得回来救我，我会尽我所能给你强化的。来个全属性提高30%?");
    ui->dialog_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    braver->hp=braver->hp*1.3;
    braver->df=braver->df*1.3;
    braver->at=braver->at*1.3;
}

void dialog::dialog_15f()
{
    ui->name_npc->setText("妖精");
    ui->name_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->dialog_npc->setText("红钥匙十分珍贵，请小心使用。");
    ui->dialog_npc->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    braver->rkey+=2;
}

void dialog::is_dialog()
{
    if(braver->floor==1)
    {
        dialog_1f();
    }
    else if(braver->floor==11)
    {
        dialog_11f();
    }
    else if(braver->floor==12)
    {
        dialog_12f();
    }
    else if(braver->floor==15)
    {
        dialog_15f();
    }
}

void dialog::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}

