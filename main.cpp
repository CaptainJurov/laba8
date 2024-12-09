#include "dialogue.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialogue w;
    w.show();
    return a.exec();
}
