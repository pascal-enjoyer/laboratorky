#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "case.h"
#include "tempquastion1.h"
Case c;
void MainWindow::HideCase() {
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->TimeLabelDyn->hide();
    ui->MoneyLabelDyn->hide();
    ui->CaseNumber->hide();
    ui->PlaceLabelDyn->hide();
}
void MainWindow::ShowCase() {
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->TimeLabelDyn->show();
    ui->MoneyLabelDyn->show();
    ui->CaseNumber->show();
    ui->PlaceLabelDyn->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->hide();
    HideCase();
    c.GenerateMoney();
    c.GenerateTime();
    c.GeneratePlace();
    ui->CaseNumber->setText("Заказ №" + QString::number(c.CaseNumber()));
    ui->TimeLabelDyn->setText(c.money);
    ui->MoneyLabelDyn->setText(c.time_to_take);
    ui->PlaceLabelDyn->setText(c.place);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ShowCase();
    ui->pushButton->hide();
    ui->pushButton_2->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    TempQuastion1 b;
    b.setModal(true);
    b.exec();
    c.GenerateMoney();
    c.GeneratePlace();
    c.GenerateTime();
    ui->CaseNumber->setText("Заказ №" + QString::number(c.CaseNumber()));
    ui->TimeLabelDyn->setText(c.money);
    ui->MoneyLabelDyn->setText(c.time_to_take);
    ui->PlaceLabelDyn->setText(c.place);
}

