#include "dialogue.h"
#include "./ui_dialogue.h"
#include <QMessageBox>
#include "bank.h"
#include <sstream>
#include <QtCharts/QChartView>
#include <QtCharts/QtCharts>
std::stringstream banks;
ASS Goal;
Dialogue::Dialogue(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dialogue)
{
    ui->setupUi(this);

}

Dialogue::~Dialogue()
{
    delete ui;
}



void Dialogue::on_newBank_clicked()
{
    banks<<ui->bankname->text().toStdString()<<ui->resultstring->text().toStdString()<<"\n";
    QString text = ui->bankname->text()+ui->resultstring->text();
    QLabel *label = new QLabel(text);
    label->setWordWrap(true);
    label->setStyleSheet("background-color: #4099ff;");
    ui->verticalLayout_2->addWidget(label);
}


void Dialogue::on_end_ssuda_clicked()
{
    QString result=ui->resultstring->text();
    result += " " + ui->year->text() + " " + ui->ssuda->text();
    ui->resultstring->setText(result);
}


void Dialogue::on_end_clicked()
{
    QChart *chart = new QChart(); // создание графика
    chart->setAnimationOptions(QChart::AllAnimations); // анимированное появление
    chart->legend()->hide(); // не показывать легенду
    chart->addSeries(series); // добавить набор данных
    chart->createDefaultAxes(); // создать основные оси
    chart->setTitle("График функции");
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(640, 480);
    QMainWindow *window = new QMainWindow();
    window->setCentralWidget(chartView);
    window->show();
    QString str;
    str.append(banks.str());
    QMessageBox::information(this, "goal",str);

}

