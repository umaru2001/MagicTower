#include "book.h"
#include "ui_book.h"

book::book(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::book)
{
    ui->setupUi(this);
}

book::~book()
{
    delete ui;
}

void book::show_book(){
        for (int i = 0; i < 40; i++)id[i] = 0;
        //遍历找怪
        book_a = 0;
        book_b = 0;
        for (int mon = 0; mon <= X * Y - 1; mon++) {
            if (Tower[braver->floor][mon] >= 51&&Tower[braver->floor][mon] <130) {
                id[book_a] = Tower[braver->floor][mon] - 50;
                book_a++;
            }
        }
        //数组去重
        for (book_a = 0; book_a < 40; book_a++) {
            for (book_b = 0; book_b < 40; book_b++) {
                if (id[book_a] == id[book_b] && book_a != book_b) {
                    id[book_b] = 0;
                }
            }
        }
        //冒泡排序(由大到小)
        for (book_a = 0; book_a < 40; book_a++){
            for (book_b = 0; book_b < 40 - book_a; book_b++){
                if (id[book_b] < id[book_b + 1])
                {
                    book_tem = id[book_b];
                    id[book_b] = id[book_b + 1];
                    id[book_b + 1] = book_tem;
                }
            }
        }
        //怪物种类的个数
        book_b = 0;
        for (book_a = 0; book_a < 40; book_a++) {
            if (id[book_a] != 0)book_b++;
        }

        if (book_b % 3 == 0 && book_b >= 3)    {Totalpage=book_b / 3;page=1;}
        else  {Totalpage=(book_b / 3) + 1;page=1;}
}


void book::keyPressEvent(QKeyEvent *event){
    int c1 = event->key();
        if (c1 == Qt::Key_Right) {
                if (page != Totalpage) {
                    page++;
                }
                emit refresh();
                eachpage();

}
        if (c1 == Qt::Key_Left){
                if (page != 1) {
                    page--;
                }
                emit refresh();
                eachpage();

            }
        if (c1 == Qt::Key_Q) {
           this->close();
        }
        }


void book::eachpage(){
    //输出怪物信息
    int a = book_b-3*page;
    QImage img_background = QImage(":/new/prefix1/Images/Image 79.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);
    switch(a){
    case -1:
        ui->labelname->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
        ui->labelname->setText("名称：");
        ui->name->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->name->setText(m_array[id[(page - 1) * 3]-1].name);
        ui->labelhp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelhp->setText("体力：");
        ui->hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->hp->setText(QString::number(m_array[id[(page - 1) * 3]-1].hp));
        ui->labelat->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelat->setText("攻击力：");
        ui->at->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->at->setText(QString::number(m_array[id[(page - 1) * 3]-1].at));
        ui->labeldf->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldf->setText("防御力：");
        ui->df->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->df->setText(QString::number(m_array[id[(page - 1) * 3]-1].df));
        ui->labeldam->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldam->setText("估计伤害：");
        ui->damage->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->damage->setText(QString::number(damage[0]));
        ui->labelexp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelexp->setText("经验值：");
        ui->exp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->exp->setText(QString::number(m_array[id[(page - 1) * 3]-1].exp));
        ui->labelgold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelgold->setText("金币：");
        ui->gold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->gold->setText(QString::number(m_array[id[(page - 1) * 3]-1].gold));
        ui->pic->setPixmap(QPixmap::fromImage(mo[0]));

            ui->labelname_2->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
            ui->labelname_2->setText("名称：");
            ui->name_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->name_2->setText(m_array[id[(page - 1) * 3+1]-1].name);
            ui->labelhp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelhp_2->setText("体力：");
            ui->hp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->hp_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].hp));
            ui->labelat_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelat_2->setText("攻击力：");
            ui->at_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->at_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].at));
            ui->labeldf_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labeldf_2->setText("防御力：");
            ui->df_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->df_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].df));
            ui->labeldam_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labeldam_2->setText("估计伤害：");
            ui->damage_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->damage_2->setText(QString::number(damage[1]));
            ui->labelexp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelexp_2->setText("经验值：");
            ui->exp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->exp_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].exp));
            ui->labelgold_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelgold_2->setText("金币：");
            ui->gold_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->gold_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].gold));
            ui->pic_2->setPixmap(QPixmap::fromImage(mo[1]));

            ui->labelname_3->setText(" ");
            ui->name_3->setText(" ");
            ui->labelhp_3->setText(" ");
            ui->hp_3->setText(" ");
            ui->labelat_3->setText(" ");
            ui->at_3->setText(" ");
            ui->labeldf_3->setText(" ");
            ui->df_3->setText(" ");
            ui->labeldam_3->setText(" ");
            ui->damage_3->setText(" ");
            ui->labelexp_3->setText(" ");
            ui->exp_3->setText(" ");
            ui->labelgold_3->setText(" ");
            ui->gold_3->setText(" ");
            ui->pic_3->setText(" ");
           break;
    case -2:
        ui->labelname->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
        ui->labelname->setText("名称：");
        ui->name->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->name->setText(m_array[id[(page - 1) * 3]-1].name);
        ui->labelhp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelhp->setText("体力：");
        ui->hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->hp->setText(QString::number(m_array[id[(page - 1) * 3]-1].hp));
        ui->labelat->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelat->setText("攻击力：");
        ui->at->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->at->setText(QString::number(m_array[id[(page - 1) * 3]-1].at));
        ui->labeldf->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldf->setText("防御力：");
        ui->df->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->df->setText(QString::number(m_array[id[(page - 1) * 3]-1].df));
        ui->labeldam->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldam->setText("估计伤害：");
        ui->damage->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->damage->setText(QString::number(damage[0]));
        ui->labelexp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelexp->setText("经验值：");
        ui->exp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->exp->setText(QString::number(m_array[id[(page - 1) * 3]-1].exp));
        ui->labelgold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelgold->setText("金币：");
        ui->gold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->gold->setText(QString::number(m_array[id[(page - 1) * 3]-1].gold));
        ui->pic->setPixmap(QPixmap::fromImage(mo[0]));

        ui->labelname_2->setText(" ");
        ui->name_2->setText(" ");
        ui->labelhp_2->setText(" ");
        ui->hp_2->setText(" ");
        ui->labelat_2->setText(" ");
        ui->at_2->setText(" ");
        ui->labeldf_2->setText(" ");
        ui->df_2->setText(" ");
        ui->labeldam_2->setText(" ");
        ui->damage_2->setText(" ");
        ui->labelexp_2->setText(" ");
        ui->exp_2->setText(" ");
        ui->labelgold_2->setText(" ");
        ui->gold_2->setText(" ");
        ui->pic_2->setText(" ");

        ui->labelname_3->setText(" ");
        ui->name_3->setText(" ");
        ui->labelhp_3->setText(" ");
        ui->hp_3->setText(" ");
        ui->labelat_3->setText(" ");
        ui->at_3->setText(" ");
        ui->labeldf_3->setText(" ");
        ui->df_3->setText(" ");
        ui->labeldam_3->setText(" ");
        ui->damage_3->setText(" ");
        ui->labelexp_3->setText(" ");
        ui->exp_3->setText(" ");
        ui->labelgold_3->setText(" ");
        ui->gold_3->setText(" ");
        ui->pic_3->setText(" ");
        break;
    default:
        ui->labelname->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
        ui->labelname->setText("名称：");
        ui->name->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->name->setText(m_array[id[(page - 1) * 3]-1].name);
        ui->labelhp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelhp->setText("体力：");
        ui->hp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->hp->setText(QString::number(m_array[id[(page - 1) * 3]-1].hp));
        ui->labelat->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelat->setText("攻击力：");
        ui->at->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->at->setText(QString::number(m_array[id[(page - 1) * 3]-1].at));
        ui->labeldf->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldf->setText("防御力：");
        ui->df->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->df->setText(QString::number(m_array[id[(page - 1) * 3]-1].df));
        ui->labeldam->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldam->setText("估计伤害：");
        ui->damage->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->damage->setText(QString::number(damage[0]));
        ui->labelexp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelexp->setText("经验值：");
        ui->exp->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->exp->setText(QString::number(m_array[id[(page - 1) * 3]-1].exp));
        ui->labelgold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelgold->setText("金币：");
        ui->gold->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->gold->setText(QString::number(m_array[id[(page - 1) * 3]-1].gold));
        ui->pic->setPixmap(QPixmap::fromImage(mo[0]));

        ui->labelname_2->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
        ui->labelname_2->setText("名称：");
        ui->name_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->name_2->setText(m_array[id[(page - 1) * 3+1]-1].name);
        ui->labelhp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelhp_2->setText("体力：");
        ui->hp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->hp_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].hp));
        ui->labelat_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelat_2->setText("攻击力：");
        ui->at_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->at_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].at));
        ui->labeldf_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldf_2->setText("防御力：");
        ui->df_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->df_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].df));
        ui->labeldam_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labeldam_2->setText("估计伤害：");
        ui->damage_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->damage_2->setText(QString::number(damage[1]));
        ui->labelexp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelexp_2->setText("经验值：");
        ui->exp_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->exp_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].exp));
        ui->labelgold_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->labelgold_2->setText("金币：");
        ui->gold_2->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
        ui->gold_2->setText(QString::number(m_array[id[(page - 1) * 3+1]-1].gold));
        ui->pic_2->setPixmap(QPixmap::fromImage(mo[1]));

            ui->labelname_3->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
            ui->gold_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelgold_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->exp_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelexp_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->damage_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labeldam_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->df_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labeldf_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->at_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelat_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->hp_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelhp_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->name_3->setStyleSheet("QLabel {color:orange;font: bold 15px;}");
            ui->labelname_3->setStyleSheet("QLabel {color:orange;font: bold 16px;}");
            ui->labelname_3->setText("名称：");
            ui->name_3->setText(m_array[id[(page - 1) * 3+2]-1].name);
            ui->labelhp_3->setText("体力：");
            ui->hp_3->setText(QString::number(m_array[id[(page - 1) * 3+2]-1].hp));
            ui->labelat_3->setText("攻击力：");
            ui->at_3->setText(QString::number(m_array[id[(page - 1) * 3+2]-1].at));
            ui->labeldf_3->setText("防御力：");
            ui->df_3->setText(QString::number(m_array[id[(page - 1) * 3+2]-1].df));
            ui->labeldam_3->setText("估计伤害：");
            ui->damage_3->setText(QString::number(damage[2]));
            ui->labelexp_3->setText("经验值：");
            ui->exp_3->setText(QString::number(m_array[id[(page - 1) * 3+2]-1].exp));
            ui->labelgold_3->setText("金币：");
            ui->gold_3->setText(QString::number(m_array[id[(page - 1) * 3+2]-1].gold));
            ui->pic_3->setPixmap(QPixmap::fromImage(mo[2]));
        break;

    }

    }

void book::fun(int page){
    for (int i = 0; i < 3; i++) {
           if ((page - 1) * 3 + i < book_b) {
            int monster_id = id[(page - 1) * 3+i]-1;
            damage[i] = calc_damage(monster_id);
            if (damage[i] == -1) {
                damage[i] = 9999999;
            }
            else if (damage[i] == -2) {
                damage[i] = 0;
            }
           }
    }
}

int book::calc_damage(int monster_id)
{
    //计算伤害值。
    if (braver->at <= m_array[monster_id].df)
    {
        if (m_array[monster_id].at > braver->df)
            return -1;
        else
            return -2;
    }
    else {
        if (m_array[monster_id].at > braver->df) {
            int atk_times = (m_array[monster_id].hp - 1) / (braver->at - m_array[monster_id].df);
            return atk_times * (m_array[monster_id].at - braver->df);
        }
        else {
            return 0;
        }
    }
}

