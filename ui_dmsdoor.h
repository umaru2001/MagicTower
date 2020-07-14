/********************************************************************************
** Form generated from reading UI file 'dmsdoor.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DMSDOOR_H
#define UI_DMSDOOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dmsdoor
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *my_dmsdoor;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *dmsdoor)
    {
        if (dmsdoor->objectName().isEmpty())
            dmsdoor->setObjectName(QString::fromUtf8("dmsdoor"));
        dmsdoor->resize(191, 140);
        verticalLayoutWidget = new QWidget(dmsdoor);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 10, 81, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        my_dmsdoor = new QLabel(verticalLayoutWidget);
        my_dmsdoor->setObjectName(QString::fromUtf8("my_dmsdoor"));
        my_dmsdoor->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(my_dmsdoor);

        verticalLayoutWidget_2 = new QWidget(dmsdoor);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 69, 81, 61));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        retranslateUi(dmsdoor);

        QMetaObject::connectSlotsByName(dmsdoor);
    } // setupUi

    void retranslateUi(QWidget *dmsdoor)
    {
        dmsdoor->setWindowTitle(QCoreApplication::translate("dmsdoor", "Form", nullptr));
        label->setText(QCoreApplication::translate("dmsdoor", "\345\211\251\344\275\231\344\273\273\346\204\217\351\227\250\357\274\232", nullptr));
        my_dmsdoor->setText(QCoreApplication::translate("dmsdoor", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("dmsdoor", "Enter\351\224\256\344\275\277\347\224\250", nullptr));
        label_3->setText(QCoreApplication::translate("dmsdoor", "T\351\224\256\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dmsdoor: public Ui_dmsdoor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DMSDOOR_H
