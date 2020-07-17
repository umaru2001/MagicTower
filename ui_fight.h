/********************************************************************************
** Form generated from reading UI file 'fight.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIGHT_H
#define UI_FIGHT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fight
{
public:
    QLabel *label;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_1;
    QLabel *mo_at;
    QLabel *label_2;
    QLabel *mo_df;
    QLabel *label_5;
    QLabel *mo_ma;
    QLabel *label_7;
    QLabel *mo_ti;
    QLabel *mo_hp;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *my_hp;
    QLabel *mtat_3;
    QLabel *my_at;
    QLabel *mtat_2;
    QLabel *my_df;
    QLabel *mtdf_2;
    QLabel *my_ma;
    QLabel *label_12;
    QLabel *my_ti;
    QLabel *label_14;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *win;
    QLabel *text_gold;
    QLabel *gold;
    QLabel *text_exp;
    QLabel *exp;
    QLabel *mo_name;
    QLabel *label_6;
    QLabel *mo_minhp;
    QLabel *my_minhp;

    void setupUi(QWidget *Fight)
    {
        if (Fight->objectName().isEmpty())
            Fight->setObjectName(QString::fromUtf8("Fight"));
        Fight->resize(381, 331);
        Fight->setMinimumSize(QSize(0, 0));
        Fight->setMaximumSize(QSize(1000, 3060));
        label = new QLabel(Fight);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 81, 55));
        formLayoutWidget = new QWidget(Fight);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 100, 125, 174));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(14);
        formLayout->setContentsMargins(0, 11, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFrameShape(QFrame::NoFrame);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_1 = new QLabel(formLayoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_1);

        mo_at = new QLabel(formLayoutWidget);
        mo_at->setObjectName(QString::fromUtf8("mo_at"));

        formLayout->setWidget(1, QFormLayout::FieldRole, mo_at);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        mo_df = new QLabel(formLayoutWidget);
        mo_df->setObjectName(QString::fromUtf8("mo_df"));

        formLayout->setWidget(2, QFormLayout::FieldRole, mo_df);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        mo_ma = new QLabel(formLayoutWidget);
        mo_ma->setObjectName(QString::fromUtf8("mo_ma"));

        formLayout->setWidget(3, QFormLayout::FieldRole, mo_ma);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        mo_ti = new QLabel(formLayoutWidget);
        mo_ti->setObjectName(QString::fromUtf8("mo_ti"));

        formLayout->setWidget(4, QFormLayout::FieldRole, mo_ti);

        mo_hp = new QLabel(formLayoutWidget);
        mo_hp->setObjectName(QString::fromUtf8("mo_hp"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mo_hp->sizePolicy().hasHeightForWidth());
        mo_hp->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, mo_hp);

        formLayoutWidget_2 = new QWidget(Fight);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(240, 100, 131, 171));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setVerticalSpacing(14);
        formLayout_2->setContentsMargins(12, 11, 0, 0);
        my_hp = new QLabel(formLayoutWidget_2);
        my_hp->setObjectName(QString::fromUtf8("my_hp"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, my_hp);

        mtat_3 = new QLabel(formLayoutWidget_2);
        mtat_3->setObjectName(QString::fromUtf8("mtat_3"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, mtat_3);

        my_at = new QLabel(formLayoutWidget_2);
        my_at->setObjectName(QString::fromUtf8("my_at"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, my_at);

        mtat_2 = new QLabel(formLayoutWidget_2);
        mtat_2->setObjectName(QString::fromUtf8("mtat_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, mtat_2);

        my_df = new QLabel(formLayoutWidget_2);
        my_df->setObjectName(QString::fromUtf8("my_df"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, my_df);

        mtdf_2 = new QLabel(formLayoutWidget_2);
        mtdf_2->setObjectName(QString::fromUtf8("mtdf_2"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, mtdf_2);

        my_ma = new QLabel(formLayoutWidget_2);
        my_ma->setObjectName(QString::fromUtf8("my_ma"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, my_ma);

        label_12 = new QLabel(formLayoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, label_12);

        my_ti = new QLabel(formLayoutWidget_2);
        my_ti->setObjectName(QString::fromUtf8("my_ti"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, my_ti);

        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, label_14);

        horizontalLayoutWidget = new QWidget(Fight);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 280, 361, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        win = new QLabel(horizontalLayoutWidget);
        win->setObjectName(QString::fromUtf8("win"));

        horizontalLayout->addWidget(win);

        text_gold = new QLabel(horizontalLayoutWidget);
        text_gold->setObjectName(QString::fromUtf8("text_gold"));
        text_gold->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(text_gold);

        gold = new QLabel(horizontalLayoutWidget);
        gold->setObjectName(QString::fromUtf8("gold"));

        horizontalLayout->addWidget(gold);

        text_exp = new QLabel(horizontalLayoutWidget);
        text_exp->setObjectName(QString::fromUtf8("text_exp"));
        text_exp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(text_exp);

        exp = new QLabel(horizontalLayoutWidget);
        exp->setObjectName(QString::fromUtf8("exp"));

        horizontalLayout->addWidget(exp);

        mo_name = new QLabel(Fight);
        mo_name->setObjectName(QString::fromUtf8("mo_name"));
        mo_name->setGeometry(QRect(10, 60, 81, 31));
        label_6 = new QLabel(Fight);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(320, 60, 51, 31));
        label_6->setAlignment(Qt::AlignCenter);
        mo_minhp = new QLabel(Fight);
        mo_minhp->setObjectName(QString::fromUtf8("mo_minhp"));
        mo_minhp->setGeometry(QRect(100, 60, 91, 31));
        my_minhp = new QLabel(Fight);
        my_minhp->setObjectName(QString::fromUtf8("my_minhp"));
        my_minhp->setGeometry(QRect(220, 60, 91, 31));

        retranslateUi(Fight);

        QMetaObject::connectSlotsByName(Fight);
    } // setupUi

    void retranslateUi(QWidget *Fight)
    {
        Fight->setWindowTitle(QCoreApplication::translate("Fight", "Form", nullptr));
        label->setText(QCoreApplication::translate("Fight", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; color:#ffaa00;\">VS</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">\344\275\223\345\212\233:</span></p></body></html>", nullptr));
        label_1->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">\346\224\273\345\207\273:</span></p></body></html>", nullptr));
        mo_at->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">\351\230\262\345\276\241:</span></p></body></html>", nullptr));
        mo_df->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">\346\260\224\346\201\257:</span></p></body></html>", nullptr));
        mo_ma->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">\347\226\262\345\212\263:</span></p></body></html>", nullptr));
        mo_ti->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        mo_hp->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        my_hp->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        mtat_3->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">:\344\275\223\345\212\233</span></p></body></html>", nullptr));
        my_at->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        mtat_2->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">:\346\224\273\345\207\273</span></p></body></html>", nullptr));
        my_df->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        mtdf_2->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">:\351\230\262\345\276\241</span></p></body></html>", nullptr));
        my_ma->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">:\346\260\224\346\201\257</span></p></body></html>", nullptr));
        my_ti->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:11pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffaa00;\">:\347\226\262\345\212\263</span></p></body></html>", nullptr));
        win->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" color:#ffaa00;\">\350\203\234\345\210\251\357\274\201</span></p></body></html>", nullptr));
        text_gold->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" color:#ffaa00;\">\351\207\221\345\270\201\357\274\232</span></p></body></html>", nullptr));
        gold->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        text_exp->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" color:#ffaa00;\">\347\273\217\351\252\214\345\200\274\357\274\232</span></p></body></html>", nullptr));
        exp->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        mo_name->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:16pt; color:#ffaa00;\">TextLabel</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:16pt; color:#ffaa00;\">\345\213\207\350\200\205</span></p></body></html>", nullptr));
        mo_minhp->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:16pt; color:#ff0000;\">TextLabel</span></p></body></html>", nullptr));
        my_minhp->setText(QCoreApplication::translate("Fight", "<html><head/><body><p><span style=\" font-size:16pt; color:#ff0000;\">TextLabel</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fight: public Ui_Fight {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIGHT_H
