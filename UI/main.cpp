#include "mainwindow.h"
#include "interactiveiot.h"
#include "qmodel.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QModel model("/home/gian/Uni/Pao/Qontainer/IoT.json");
    QApplication a(argc, argv);
    InteractiveIot iot(QString::fromStdString(model.getAllRooms()));
    iot.show();
    return a.exec();
}
