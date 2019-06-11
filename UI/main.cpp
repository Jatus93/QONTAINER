#include "mainwindow.h"
#include "interactiveiot.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InteractiveIot* iot = new InteractiveIot();
    return a.exec();
}
