#ifndef BEGINNING_H
#define BEGINNING_H

#include <QMainWindow>
#include"Information.h"
#include"mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Beginning; }
QT_END_NAMESPACE

class Beginning : public QMainWindow
{
    Q_OBJECT

public:
    Beginning(QWidget *parent = nullptr);
    Information *info = NULL;
    MainWindow *main = NULL;
    ~Beginning();

private:
    Ui::Beginning *ui;
};
#endif // BEGINNING_H
