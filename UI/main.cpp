#include "mainwindow.h"
#include "interactiveiot.h"
#include "qmodel.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
