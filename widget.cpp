#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include"monitor.h"
#include<QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,time(new QTimer(this))
    ,monitor_ui(nullptr)
{
    ui->setupUi(this);
    ui->horizontalSlider->setRange(0,9999);
    QPixmap pix;
    pix.load(":/img/222.jpg");
    ui->label_3->setPixmap(pix);

    connect(&myevent,&fsmpEvents::keyPressed,this,&Widget::pushbutton);
    connect(time,&QTimer::timeout,this,&Widget::timeout);
    time->start(1000);
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_pushButton_clicked()
{
  if(ui->pushButton->text()=="开灯"){

      myled.on(fsmpLeds::LED1);
      ui->pushButton->setText("关灯");
  }else{
      myled.off(fsmpLeds::LED1);
      ui->pushButton->setText("开灯");
  }
}
void Widget::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text()=="开灯"){

        myled.on(fsmpLeds::LED2);
        ui->pushButton_2->setText("关灯");
    }else{
        myled.off(fsmpLeds::LED2);
        ui->pushButton_2->setText("开灯");
    }
}
void Widget::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text()=="开灯"){

        myled.on(fsmpLeds::LED3);
        ui->pushButton_3->setText("关灯");
    }else{
        myled.off(fsmpLeds::LED3);
        ui->pushButton_3->setText("开灯");
    }
}
void Widget::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        myled.on(fsmpLeds::LED1);
    }else{
        myled.off(fsmpLeds::LED1);
    }
}
void Widget::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1){
        mybeeper.setRate(5000);
        mybeeper.start();
    }else{
        mybeeper.stop();
    }
}
void Widget::on_horizontalSlider_valueChanged(int value)
{
    qDebug() << ui->horizontalSlider->value();
    mybeeper.setRate(value);//调整频率，不能控制大小
    mybeeper.start();
    ui->progressBar->setValue(ui->horizontalSlider->value());
}
void Widget::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1){
    myfan.setSpeed (100);myfan.start();
    }else{
    myfan.stop();}
}
void Widget::pushbutton(int num)
{
    switch (num) {
    case 1:
        ui->checkBox->toggle();
        break;
    case 2:
        ui->checkBox_4->toggle();
        break;
    case 3:
        ui->checkBox_5->toggle();
        break;
    default:
        break;
    }
}
void Widget::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1){
        myled.on(fsmpLeds::LED2);
    }else{
        myled.off(fsmpLeds::LED2);
    }
}
void Widget::on_checkBox_5_stateChanged(int arg1)
{
    if(arg1){
        myled.on(fsmpLeds::LED3);
    }else{
        myled.off(fsmpLeds::LED3);
    }
}
void Widget::timeout()
{
    ui->doubleSpinBox->setValue(myth.temperature());
    ui->doubleSpinBox_2->setValue(myth.humidity());
}
void Widget::on_pushButton_4_clicked()
{
    if(!monitor_ui)
    {
            monitor_ui = new Monitor(nullptr);
    }
    this->hide();
    monitor_ui->show();
}


