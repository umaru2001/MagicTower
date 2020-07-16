#include "fight.h"
#include "ui_fight.h"

Fight::Fight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Fight)
{
    ui->setupUi(this);
    //this->setFixedSize(410,306);
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));
    this->setWindowTitle("战斗");
    QImage img_background = QImage(":/new/prefix1/Images/Image 79.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);
}


Fight::~Fight()
{
    delete ui;
}

void Fight::keyPressEvent(QKeyEvent *ev)
{
    if(mo_hp>0)
    {
        if(ev->key() == Qt::Key_Q)
        {
            this->close();
        }
    }
    else
    {
        if(ev->key()==Qt::Key_Return)
        {
            this->close();
        }
    }

}

void Fight::setTextMonster()
{
    if(mo_hp > 0)
    {
        ui->mo_hp->setText(QString::number(mo_hp));
        ui->mo_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    }
    else
    {
        ui->mo_hp->setText("0");
        ui->mo_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    }
}

void Fight::setTextBraver()
{
    if(braver->hp > 0)
    {
        ui->my_hp->setText(QString::number(braver->hp));
        ui->my_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    }
    else
    {
        ui->my_hp->setText("0");
        ui->my_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    }
}

void Fight::setTextGoldExp()
{
    ui->gold->setText(QString::number(mo.gold));
    ui->exp->setText(QString::number(mo.exp));
    ui->win->setText("胜利！");
    ui->text_gold->setText("金币：");
    ui->text_exp->setText("经验值：");
    ui->win->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->gold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->exp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->text_exp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->text_gold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
}

void Fight::fight()
{
    QTimer *timer1=new QTimer(this);
    timer1->start(1000);
    QTimer *timer2=new QTimer(this);
    QTimer::singleShot(500, timer2, [=](){
        timer2->start(1000);
    });
        connect(timer1,&QTimer::timeout,[=](){
            if(braver->hp>0)
            {
                mo_hp-=calc_mo_damage();
                setTextMonster();
            }
            else
            {
                timer1->stop();
                timer2->stop();
                delete timer1;
                delete timer2;
                this->close();
            }
        });
        connect(timer2,&QTimer::timeout,[=](){
            if(mo_hp > 0)
            {
                braver->hp-=calc_my_damage();
                setTextBraver();
            }
            else
            {
                timer1->stop();
                timer2->stop();
                delete timer1;
                delete timer2;
                is_monster_remain();
                is_braver_survival();
                setTextGoldExp();
            }
        });
}

int Fight::calc_my_damage()
{
    if(mo.id>=21&&mo.id<=34) //魔法师攻击
    {
        return mo.at;
    }
    else
    {
        if(mo.at>braver->df)
        {
            return mo.at-braver->df;
        }
        else
        {
            return 0;
        }
    }
}

int Fight::calc_mo_damage()
{
    if(braver->at>mo.df)
    {
        return braver->at-mo.df;
    }
    else
    {
        return 0;
    }
}

void Fight::init_text()
{
    ui->mo_hp->setText(QString::number(mo.hp));
    ui->mo_at->setText(QString::number(mo.at));
    ui->mo_df->setText(QString::number(mo.df));
    ui->my_hp->setText(QString::number(braver->hp));
    ui->my_at->setText(QString::number(braver->at));
    ui->my_df->setText(QString::number(braver->df));
    ui->my_minhp->setText(" ");
    ui->mo_minhp->setText(" ");
    ui->mo_name->setText(mo.name);
    ui->win->setText(" ");
    ui->gold->setText(" ");
    ui->exp->setText(" ");
    ui->text_gold->setText(" ");
    ui->text_exp->setText(" ");
    ui->mo_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_at->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->my_df->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->mo_name->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->mo_at->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    ui->mo_df->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
    mo_hp = mo.hp;
}

void Fight::is_braver_survival()
{
    if(braver->hp>0)
    {
        braver->gold += mo.gold;
        braver->exp += mo.exp;
    }
    else
    {
        this->close();
    }
}

void Fight::is_monster_remain()
{
    if(mo.id==28||50) //炎之身躯
    {
        Tower[braver->floor][tar_pos] = 9;
    }
    if(mo.id==59||25) //寒冰身躯
    {
        Tower[braver->floor][tar_pos] = 7;
    }
    if(mo.id==38) //复活技能
    {
        Tower[braver->floor][tar_pos] = 100;
    }
    if(mo.id==52)
    {
        Tower[braver->floor][tar_pos] = 92;
    }
    if(mo.id==41)
    {
        Tower[braver->floor][tar_pos] = 102;
    }
    else
    {
        Tower[braver->floor][tar_pos] = 0;
    }
}

void Fight::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}
