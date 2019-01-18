#include "tst_test_switch.h"

std::string test_Switch::serial = "AAAAAAAAA";
std::string test_Switch::room = "room0";
Switch* test_Switch::button = nullptr;

test_Switch::test_Switch()
{

}

test_Switch::~test_Switch()
{

}

void test_Switch::initTestCase()
{

}

void test_Switch::cleanupTestCase()
{

}

void test_Switch::test_constructor(){
    button = new Switch(serial,room);
}

void test_Switch::test_serial(){
    QVERIFY(button->getSerial()==serial);
}
void test_Switch::test_room(){
    QVERIFY(button->getRoom()==room);
}
void test_Switch::test_class(){
    QVERIFY(button->getClass()=="switch");
}
void test_Switch::test_Instruction(){
    QJsonDocument instructions = button->getDeviceInstruction();
}

void test_Switch::test_getStatus(){
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("power").toString()=="off");
}
void test_Switch::test_setDevice(){
    QJsonDocument toSet = QJsonDocument::fromRawData("{\"power\":\"on\"}",0);
    button->setDevice(toSet);
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("power").toString()=="on");
}

void test_Switch::test_JsonConstructor(){
    QJsonDocument init = QJsonDocument::fromRawData("{\"serial\":\"BBBBB\",\"room\":\"room1\",\"status\":{\"power\":\"on\"}}",0);
    delete button;
    button = new Switch(init);
    QVERIFY(button->getSerial()=="BBBBB");
    QVERIFY(button->getRoom()=="room1");
    QJsonObject status = button->getStatus().object();
    std::cout << status.value("power").toString("empty").toStdString()<<'\n';
    QVERIFY(status.value("power").toString()=="on");

}
QTEST_APPLESS_MAIN(test_Switch)

//#include "tst_test_switch.moc"
