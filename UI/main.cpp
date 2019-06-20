#include "mainwindow.h"
#include "interactiveiot.h"
#include "qmodel.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setApplicationName("Qontainer");
    QFile file(":/style/mainStyle.qss");
    file.open(QFile::ReadOnly);
    QString style = QLatin1String(file.readAll());
    a.setStyleSheet(style);
    MainWindow w;
    w.show();
    return a.exec();
}
