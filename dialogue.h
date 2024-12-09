#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <QtCharts/QLineSeries>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialogue;
}
QT_END_NAMESPACE

class Dialogue : public QMainWindow
{
    Q_OBJECT

public:
    Dialogue(QWidget *parent = nullptr);
    ~Dialogue();

private slots:

    void on_newBank_clicked();

    void on_end_ssuda_clicked();

    void on_end_clicked();

private:
    Ui::Dialogue *ui;
    QLineSeries *series;
};
#endif // DIALOGUE_H
