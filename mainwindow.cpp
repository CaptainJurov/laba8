#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bank.h"
#include <vector>
#include <sstream>

ASS Z;
QString buf;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AppendSsuda_clicked()
{
    buf+=ui->Year->text()+" "+ui->Ssuda->text()+" ";
    ui->BankInfo->setText(buf);
}


void MainWindow::on_AppendBank_clicked()
{
    QLabel *label = new QLabel(ui->BankName->text()+" "+ui->BankInfo->text());
    label->setWordWrap(true);
    label->setStyleSheet("background-color: #4099ff;");
    ui->verticalLayout->addWidget(label);

    std::stringstream bu;
    bu << ui->BankInfo->text().toStdString();
    auto name = ui->BankName->text().toStdString();
    std::vector<Ссуда> Ссуды;
    int year, ssuda;
    while (bu>>year>>ssuda) {
        Ссуда ssudaa(year, ssuda);
        Ссуды.push_back(ssudaa);
    }
    Bank current_bank(name, Ссуды);
    Z.Банки.push_back(current_bank);
    QString count = QString::number(Z.Банки.size());
}


void MainWindow::on_Build_clicked()
{

}
