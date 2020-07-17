/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QLabel *name_npc;
    QLabel *label_2;

    void setupUi(QWidget *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QString::fromUtf8("dialog"));
        dialog->resize(300, 211);
        name_npc = new QLabel(dialog);
        name_npc->setObjectName(QString::fromUtf8("name_npc"));
        name_npc->setGeometry(QRect(120, 20, 141, 41));
        label_2 = new QLabel(dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 90, 261, 111));

        retranslateUi(dialog);

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QWidget *dialog)
    {
        dialog->setWindowTitle(QCoreApplication::translate("dialog", "Form", nullptr));
        name_npc->setText(QCoreApplication::translate("dialog", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
