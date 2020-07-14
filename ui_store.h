/********************************************************************************
** Form generated from reading UI file 'store.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORE_H
#define UI_STORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_store
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *god;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *hp_plus;
    QLabel *at_plus;
    QLabel *df_plus;
    QLabel *exit;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *my_lv;
    QLabel *label_3;
    QLabel *my_hp;
    QLabel *label_4;
    QLabel *my_at;
    QLabel *label_5;
    QLabel *my_df;
    QLabel *label_6;
    QLabel *my_gold;
    QLabel *store_message;

    void setupUi(QWidget *store)
    {
        if (store->objectName().isEmpty())
            store->setObjectName(QString::fromUtf8("store"));
        store->resize(352, 260);
        verticalLayoutWidget_2 = new QWidget(store);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(99, 10, 131, 51));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        god = new QLabel(verticalLayoutWidget_2);
        god->setObjectName(QString::fromUtf8("god"));
        god->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(god);

        verticalLayoutWidget = new QWidget(store);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(29, 130, 201, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        hp_plus = new QLabel(verticalLayoutWidget);
        hp_plus->setObjectName(QString::fromUtf8("hp_plus"));
        hp_plus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(hp_plus);

        at_plus = new QLabel(verticalLayoutWidget);
        at_plus->setObjectName(QString::fromUtf8("at_plus"));
        at_plus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(at_plus);

        df_plus = new QLabel(verticalLayoutWidget);
        df_plus->setObjectName(QString::fromUtf8("df_plus"));
        df_plus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(df_plus);

        exit = new QLabel(verticalLayoutWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(exit);

        verticalLayoutWidget_3 = new QWidget(store);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(240, 10, 101, 241));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(3, 3, 0, 7);
        label_1 = new QLabel(verticalLayoutWidget_3);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        verticalLayout_3->addWidget(label_1);

        label_2 = new QLabel(verticalLayoutWidget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);

        my_lv = new QLabel(verticalLayoutWidget_3);
        my_lv->setObjectName(QString::fromUtf8("my_lv"));
        my_lv->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(my_lv);

        label_3 = new QLabel(verticalLayoutWidget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        my_hp = new QLabel(verticalLayoutWidget_3);
        my_hp->setObjectName(QString::fromUtf8("my_hp"));
        my_hp->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(my_hp);

        label_4 = new QLabel(verticalLayoutWidget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        my_at = new QLabel(verticalLayoutWidget_3);
        my_at->setObjectName(QString::fromUtf8("my_at"));
        my_at->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(my_at);

        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        my_df = new QLabel(verticalLayoutWidget_3);
        my_df->setObjectName(QString::fromUtf8("my_df"));
        my_df->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(my_df);

        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_3->addWidget(label_6);

        my_gold = new QLabel(verticalLayoutWidget_3);
        my_gold->setObjectName(QString::fromUtf8("my_gold"));
        my_gold->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(my_gold);

        store_message = new QLabel(store);
        store_message->setObjectName(QString::fromUtf8("store_message"));
        store_message->setGeometry(QRect(31, 61, 200, 60));
        store_message->setMinimumSize(QSize(200, 60));
        store_message->setMaximumSize(QSize(200, 60));
        store_message->setBaseSize(QSize(0, 0));
        store_message->setWordWrap(true);

        retranslateUi(store);

        QMetaObject::connectSlotsByName(store);
    } // setupUi

    void retranslateUi(QWidget *store)
    {
        store->setWindowTitle(QCoreApplication::translate("store", "Form", nullptr));
        god->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        hp_plus->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        at_plus->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        df_plus->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        exit->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        label_1->setText(QCoreApplication::translate("store", "\345\275\223\345\211\215\350\247\222\350\211\262\347\212\266\346\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("store", "\347\255\211\347\272\247\357\274\232", nullptr));
        my_lv->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("store", "\347\224\237\345\221\275\357\274\232", nullptr));
        my_hp->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("store", "\346\224\273\345\207\273\357\274\232", nullptr));
        my_at->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("store", "\351\230\262\345\276\241\357\274\232", nullptr));
        my_df->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("store", "\351\207\221\345\270\201\357\274\232", nullptr));
        my_gold->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
        store_message->setText(QCoreApplication::translate("store", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class store: public Ui_store {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORE_H
