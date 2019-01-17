#include "switchtest.h"

std::string SwitchTest::serial =  "AAAAAAAAAA";
std::string SwitchTest::room = "room0";
Switch* SwitchTest::button = new Switch(serial,room);

const QJsonObject* SwitchTest::instruction;
std::list<QString> SwitchTest::keys;


void SwitchTest::testGetInstruction(){
    instruction = button->getDeviceInstruction();
    keys = instruction->keys().toStdList();
    QVERIFY(!instruction->isEmpty());
}

void SwitchTest::checkOffKey(){
    QString key = "off";
    QVERIFY(instruction->keys().contains(key));
}

void SwitchTest::checkOnKey(){
    QString key = "on";
    QVERIFY(instruction->keys().contains(key));
}

void SwitchTest::checkOnValue(){
    QString key = "on";
    QVERIFY(instruction->value(key).toInt(-1) == 1);
}

void SwitchTest::checkOffValue(){
    QString key = "off";
    QVERIFY(instruction->value(key).toInt(-1) == 0);
}
