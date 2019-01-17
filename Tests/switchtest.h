#ifndef SWITCHTEST_H
#define SWITCHTEST_H

#include <QtTest/QTest>
#include "../IoT/switch.h"

class SwitchTest : public QObject
{
    Q_OBJECT
    static std::string serial;
    static std::string room;
    static Switch* button;
    const static QJsonObject* instruction;
    static std::list<QString> keys;

private slots:
    void testGetInstruction();
    void checkOffKey();
    void checkOnKey();
    void checkOnValue();
    void checkOffValue();
};



#endif // SWITCHTEST_H
