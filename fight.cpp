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
    ui->at->setText(QString("at: %1").arg(B_at));
    ui->hp->setText(QString("hp: %1").arg(B_hp));
    ui->df->setText(QString("df: %1").arg(B_df));
    ui->mtat->setText(QString("at: %1").arg(M_at));
    ui->mthp->setText(QString("hp: %1").arg(M_hp));
    ui->mtdf->setText(QString("df:%1").arg(M_df));
    ui->Braver->setText(QString(B));
    ui->Monster->setText(QString(M));
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

