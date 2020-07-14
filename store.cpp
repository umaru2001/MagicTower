#include "store.h"
#include "ui_store.h"

//store *wstore;
store::store(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::store)
{
    ui->setupUi(this);
    QImage img_background = QImage(":/new/prefix1/Images/Image 79.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QPixmap::fromImage(img_background));
    this->setPalette(palette);
}

store::~store()
{
    delete ui;
}

void store::keyPressEvent(QKeyEvent *event)
{
    int store_price_0 = 20;//第一个商店从20golds开始涨价
    int store_price_2 = 50;//第二个商店从50golds开始涨价
    store_price_0 += vars->BuyTimes_0;
    store_price_2 += vars->BuyTimes_1 * 2;
    switch (vars->store_no)
   {
    case 0:
        if(event->key() == Qt::Key_1){
            if (braver->gold >= store_price_0)
            {
                braver->gold -= store_price_0;
                braver->hp += 400;
                vars->BuyTimes_0++;
                store_price_0++;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_2){
            if (braver->gold >= store_price_0)
            {
                braver->gold -= store_price_0;
                braver->at += 3;
                vars->BuyTimes_0++;
                store_price_0++;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_3){
            if (braver->gold >= store_price_0)
            {
                braver->gold -= store_price_0;
                braver->df += 3;
                vars->BuyTimes_0++;
                store_price_0++;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_4){
            this->close();
            break;
        }
        else
        {
            vars->hint_msg = "请输入正确的选项！";
            break;
        }
    case 1:
        if(event->key() == Qt::Key_1){
            if (braver->exp >= 70)
            {
                braver->exp -= 70;
                braver->hp += 300;
                braver->lv += 1;
                braver->at += 3;
                braver->df += 3;
            }
            else
            {
                vars->hint_msg = "您的经验不够！";
            }break;
        }
        if(event->key() == Qt::Key_2){
            if (braver->exp >= 20)
            {
                braver->exp -= 20;
                braver->at += 1;
            }
            else
            {
                vars->hint_msg = "您的经验不够！";
            }break;
        }
        if(event->key() == Qt::Key_3){
            if (braver->exp >= 20)
            {
                braver->gold -= 20;
                braver->df += 2;
            }
            else
            {
                vars->hint_msg = "您的经验不够！";
            }break;
        }
        if(event->key() == Qt::Key_4){
            this->close();
            break;
        }
        else
        {
            vars->hint_msg = "请输入正确的选项！";
            break;
        }
    case 2:
        //商店2，第三个提升能力的商店
        if(event->key() == Qt::Key_1){
            if (braver->gold >= store_price_2)
            {
                braver->gold -= store_price_2;
                braver->hp += 800;
                vars->BuyTimes_1++;
                store_price_2 = store_price_2 + 2;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_2){
            if (braver->gold >= store_price_2)
            {
                braver->gold -= store_price_2;
                braver->at += 6;
                vars->BuyTimes_1++;
                store_price_2 = store_price_2 + 2;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_3){
            if (braver->gold >= store_price_2)
            {
                braver->gold -= store_price_2;
                braver->df += 6;
                vars->BuyTimes_1++;
                store_price_2 = store_price_2 + 2;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_4){
            this->close();
            break;
        }
        else{
            vars->hint_msg = "请输入正确的选项！";
            break;
        }
    case 4:
        if(event->key() == Qt::Key_1){
            if (braver->gold >= 20)
            {
                braver->gold -= 20;
                braver->ykey += 1;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_2){
            if (braver->gold >= 80)
            {
                braver->gold -= 80;
                braver->bkey += 1;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_4){
            this->close();
            break;
        }
        else
        {
            vars->hint_msg = "请输入正确的选项！";
            break;
        }
    case 3:
        if(event->key() == Qt::Key_1){
            if (braver->exp >= 190)
            {
                braver->exp -= 190;
                braver->hp += 800;
                braver->lv += 3;
                braver->at += 10;
                braver->df += 10;
            }
            else
            {
                vars->hint_msg = "您的经验不够！";
            }break;
        }
        if(event->key() == Qt::Key_2){
            if (braver->exp >= 50)
            {
                braver->exp -= 50;
                braver->at += 3;
            }
            else
            {
                vars->hint_msg = "您的经验不够！";
            }break;
        }
        if(event->key() == Qt::Key_3){
            if (braver->exp >= 50)
            {
                braver->gold -= 50;
                braver->df += 5;
            }
            else
            {
                vars->hint_msg = "您的经验不够！";
            }break;
        }
        if(event->key() == Qt::Key_4){
            this->close();
            break;
        }
        else
        {
            vars->hint_msg = "请输入正确的选项！";
            break;
        }

    case 5:
        if(event->key() == Qt::Key_1){
            if (braver->gold >= 30)
            {
                braver->gold -= 30;
                braver->dms_door += 1;
            }
            else
            {
                vars->hint_msg = "您的金币不够！";
            }break;
        }
        if(event->key() == Qt::Key_4){
            this->close();
            break;
        }
        else
        {
            vars->hint_msg = "请输入正确的选项！";
            break;
        }
    }
    set_text();
}

void store::set_text()
{
    int store_price_0 = 20;//第一个商店从20golds开始涨价
    int store_price_2 = 50;//第二个商店从50golds开始涨价
    store_price_0 += vars->BuyTimes_0;
    store_price_2 += vars->BuyTimes_1 * 2;
    switch (vars->store_no)
    {
    case 0:
        ui->god->setText("食婪之神");
        ui->store_message->setText("尊敬的勇士您好，如果您给我"+QString::number(store_price_0)+"金币,我便能满足你一个要求：");
        ui->hp_plus->setText("1.体力+400");
        ui->at_plus->setText("2.攻击+3");
        ui->df_plus->setText("3.防御+3");
        ui->exit->setText("4.离开");
        ui->label_2->setText("当前等级：");
        ui->label_3->setText("当前体力：");
        ui->label_4->setText("当前攻击：");
        ui->label_5->setText("当前防御：");
        ui->label_6->setText("当前金币：");
        ui->my_lv->setText(QString::number(braver->lv));
        ui->my_hp->setText(QString::number(braver->hp));
        ui->my_at->setText(QString::number(braver->at));
        ui->my_df->setText(QString::number(braver->df));
        ui->my_gold->setText(QString::number(braver->gold));
        break;
    case 1:
        ui->god->setText("经验之神");
        ui->store_message->setText("尊敬的勇士您好，看来您十分虚弱呢，这里可以将你的经验值化作你的力量：");
        ui->hp_plus->setText("1.升1等级(70 exp)");
        ui->at_plus->setText("2.攻击+1(20 exp)");
        ui->df_plus->setText("3.防御+2(20 exp)");
        ui->exit->setText("4.离开");
        ui->label_2->setText("当前等级：");
        ui->label_3->setText("当前体力：");
        ui->label_4->setText("当前攻击：");
        ui->label_5->setText("当前防御：");
        ui->label_6->setText("当前经验：");
        ui->my_lv->setText(QString::number(braver->lv));
        ui->my_hp->setText(QString::number(braver->hp));
        ui->my_at->setText(QString::number(braver->at));
        ui->my_df->setText(QString::number(braver->df));
        ui->my_gold->setText(QString::number(braver->exp));
        break;
    case 2:
        ui->god->setText("食婪之神");
        ui->store_message->setText("尊敬的勇士您好，如果您给我"+QString::number(store_price_2)+"金币,我便能满足你一个要求：");
        ui->hp_plus->setText("1.体力+800");
        ui->at_plus->setText("2.攻击+6");
        ui->df_plus->setText("3.防御+6");
        ui->exit->setText("4.离开");
        ui->label_2->setText("当前等级：");
        ui->label_3->setText("当前体力：");
        ui->label_4->setText("当前攻击：");
        ui->label_5->setText("当前防御：");
        ui->label_6->setText("当前金币：");
        ui->my_lv->setText(QString::number(braver->lv));
        ui->my_hp->setText(QString::number(braver->hp));
        ui->my_at->setText(QString::number(braver->at));
        ui->my_df->setText(QString::number(braver->df));
        ui->my_gold->setText(QString::number(braver->gold));
        break;
    case 3:
        ui->god->setText("经验之神");
        ui->store_message->setText("尊敬的勇士您好，看来您十分虚弱呢，这里可以将你的经验值化作你的力量：");
        ui->hp_plus->setText("1.升3等级(190 exp)");
        ui->at_plus->setText("2.攻击+1(50 exp)");
        ui->df_plus->setText("3.防御+2(50 exp)");
        ui->exit->setText("4.离开");
        ui->label_2->setText("当前等级：");
        ui->label_3->setText("当前体力：");
        ui->label_4->setText("当前攻击：");
        ui->label_5->setText("当前防御：");
        ui->label_6->setText("当前经验：");
        ui->my_lv->setText(QString::number(braver->lv));
        ui->my_hp->setText(QString::number(braver->hp));
        ui->my_at->setText(QString::number(braver->at));
        ui->my_df->setText(QString::number(braver->df));
        ui->my_gold->setText(QString::number(braver->exp));
        break;
    case 4:
        ui->god->setText("小偷");
        ui->store_message->setText("啊哈！看来你很缺钥匙呢，这里量大便宜哦！");
        ui->hp_plus->setText("1.黄钥匙(20 golds)");
        ui->at_plus->setText("2.蓝钥匙(80 golds)");
        ui->df_plus->setText("   ");
        ui->exit->setText("4.离开");
        ui->label_2->setText("当前黄钥匙：");
        ui->label_3->setText("  ");
        ui->label_4->setText("当前蓝钥匙：");
        ui->label_5->setText("  ");
        ui->label_6->setText("当前金币：");
        ui->my_lv->setText(QString::number(braver->ykey));
        ui->my_hp->setText("  ");
        ui->my_at->setText(QString::number(braver->bkey));
        ui->my_df->setText("  ");
        ui->my_gold->setText(QString::number(braver->gold));
        break;
    case 5:
        ui->god->setText("神奇老人");
        ui->store_message->setText("要不要任意门呢？这里一个30金币好了......");
        ui->hp_plus->setText("1.买(30 golds)");
        ui->at_plus->setText("   ");
        ui->df_plus->setText("   ");
        ui->exit->setText("4.离开");
        ui->label_2->setText("  ");
        ui->label_3->setText("当前任意门：");
        ui->label_4->setText("  ");
        ui->label_5->setText("  ");
        ui->label_6->setText("当前金币：");
        ui->my_lv->setText("  ");
        ui->my_hp->setText(QString::number(braver->dms_door));
        ui->my_at->setText("  ");
        ui->my_df->setText("  ");
        ui->my_gold->setText(QString::number(braver->gold));
        break;
    }

}

void store::closeEvent(QCloseEvent *event)
{
    emit closeSignal();
}
