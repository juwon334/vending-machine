#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkValue(){

    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }

    else if(money >= 100 && money < 150){
        ui->pbCoffee->setEnabled(true);
    }

    else if(money >= 150 && money < 200){
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }

    else if(money >= 200){
        ui->pbMilk->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }

}

void Widget::moneyReturn(){
    int n500 = money / 500;
    money = money % 500;
    int n100 = money / 100;
    money = money % 100;
    int n50 = money / 50;
    money = money % 50;
    int n10 = money / 10;
    money = money % 10;

    QString text = QString("500 : %1\n100 : %2\n50 : %3\n10 : %4\n")
        .arg(n500).arg(n100).arg(n50).arg(n10);

    QMessageBox::information(nullptr, "return", text);
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    checkValue();
}

void Widget::on_pb10_clicked(){
    changeMoney(10);
}

void Widget::on_pb50_clicked(){
    changeMoney(50);
}


void Widget::on_pb100_clicked(){
    changeMoney(100);
}


void Widget::on_PB500_clicked(){
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked(){
    changeMoney(-100);
}


void Widget::on_pbTea_clicked(){
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked(){
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    QMessageBox mb;
    moneyReturn();
    changeMoney(-money);

}

