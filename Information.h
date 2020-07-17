#ifndef INFO_H
#define INFO_H

#include <QMainWindow>

class Information : public QMainWindow
{
    Q_OBJECT
public:
    explicit Information(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

signals:
    void back();

};

#endif // INFO_H
