#include "mainwindow.h"
#include <QApplication>
#include"beginning.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Beginning w;
    w.show();
    return a.exec();    
}
