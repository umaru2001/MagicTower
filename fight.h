#ifndef FIGHT_H
#define FIGHT_H

#include <QWidget>

namespace Ui {
class Fight;
}

class Fight : public QWidget
{
    Q_OBJECT

signals:
        void quit();
public:
    explicit Fight(QString B,QString M,int B_hp,int M_hp,int B_at,int B_df,int M_at,int M_df);
    ~Fight();
    void keyEvent(QKeyEvent *event);
    void keyPressEvent(QKeyEvent *ev);
private:
    Ui::Fight *ui;
};

#endif // FIGHT_H
