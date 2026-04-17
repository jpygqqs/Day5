#ifndef WIDGET_H
#define WIDGET_H

#include<fsmpLed.h>
#include<fsmpBeeper.h>
#include<fsmpFan.h>
#include <QWidget>
#include<fsmpEvents.h>
#include<fsmpTempHum.h>

#include<QTimer>

class Monitor;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_3_stateChanged(int arg1);

    void pushbutton(int num);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void timeout();

    void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
    fsmpBeeper mybeeper;
    fsmpFan myfan;
    fsmpLeds myled;
    fsmpEvents myevent;
    fsmpTempHum myth;

    QTimer *time;
    Monitor *monitor_ui;
};
#endif // WIDGET_H
