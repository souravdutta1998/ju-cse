#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

class my_label : public QLabel
{
    Q_OBJECT

public:
    my_label(QWidget *parent = 0);
    int x,y;

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
signals:
    void sendMousePosition(QPoint&);
    void Mouse_Pos();
};

#endif // MY_LABEL_H
