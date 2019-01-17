#include "mainwindow.h"
#include <QApplication>
#include "Tests/switchtest.h"
#include "IoT/iot.h"
#include "IoT/switch.h"

/**int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}*/
QTEST_MAIN(SwitchTest)
