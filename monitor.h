#ifndef MONITOR_H
#define MONITOR_H
#include "widget.h"
#include<fsmpCamera.h>
#include <QWidget>
#include<QTimer>
class Widget;

namespace Ui {
class Monitor;
}

class Monitor : public QWidget
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = nullptr);
    ~Monitor();

private slots:
    void on_pushButton_clicked();
    void newpicture();
    void timeout();

private:
    Ui::Monitor *ui;
    Widget *main_ui;
    fsmpCamera *mycamera;
    QTimer *time;
};

#endif // MONITOR_H
