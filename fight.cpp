#include "fight.h"
#include "ui_fight.h"
#include"QMainWindow"
#include <QKeyEvent>

Fight::Fight(QString B, QString M, int B_hp, int M_hp, int B_at, int B_df, int M_at, int M_df) :
    ui(new Ui::Fight)
{
    ui->setupUi(this);
    this->setFixedSize(410,306);
    this->setWindowIcon(QPixmap(":/Titles/icon.png"));
    this->setWindowTitle("战斗");
    ui->at->setText(QString("攻击: %1").arg(B_at));
    ui->at->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->hp->setText(QString("生命值: %1").arg(B_hp));
     ui->hp->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->df->setText(QString("防御: %1").arg(B_df));
     ui->df->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->mtat->setText(QString("攻击: %1").arg(M_at));
     ui->mtat->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->mthp->setText(QString("生命值: %1").arg(M_hp));
     ui->mthp->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->mtdf->setText(QString("防御:%1").arg(M_df));
     ui->mtdf->setStyleSheet("QLabel {color:orange;font: bold 18px;}");
    ui->Braver->setText(QString(B));
     ui->Braver->setStyleSheet("QLabel {color:white;font: bold 24px;}");
    ui->Monster->setText(QString(M));
     ui->Monster->setStyleSheet("QLabel {color:white;font: bold 24px;}");
}

Fight::~Fight()
{
    delete ui;
}

void Fight::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Q)
    {
        emit this->quit();
    }
}

