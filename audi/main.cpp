#include "mainwindow.h"
#include "auth.h"
#include <QApplication>
#include "case.h"
int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    Auth w;
    w.show();
    return a.exec();
}
