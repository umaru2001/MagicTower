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
    QLabel *dialog_npc;
    QLabel *label;

    void setupUi(QWidget *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QString::fromUtf8("dialog"));
        dialog->resize(300, 251);
        name_npc = new QLabel(dialog);
        name_npc->setObjectName(QString::fromUtf8("name_npc"));
        name_npc->setGeometry(QRect(120, 20, 141, 41));
        name_npc->setWordWrap(true);
        dialog_npc = new QLabel(dialog);
        dialog_npc->setObjectName(QString::fromUtf8("dialog_npc"));
        dialog_npc->setGeometry(QRect(20, 80, 261, 121));
        dialog_npc->setWordWrap(true);
        label = new QLabel(dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 210, 271, 31));

        retranslateUi(dialog);

        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QWidget *dialog)
    {
        dialog->setWindowTitle(QCoreApplication::translate("dialog", "Form", nullptr));
        name_npc->setText(QCoreApplication::translate("dialog", "TextLabel", nullptr));
        dialog_npc->setText(QCoreApplication::translate("dialog", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("dialog", "<html><head/><body><p><span style=\" color:#ffaa00;\">\346\214\211\344\270\213\342\200\234Enter\342\200\235\351\224\256\345\217\257\344\273\245\350\277\224\345\233\236</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
