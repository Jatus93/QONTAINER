#include <QtTest>
#include <iot.h>
#include <switch.h>

// add necessary includes here

class test_Switch : public QObject
{
    Q_OBJECT
    static std::string serial;
    static std::string room;
    static Switch *button;

public:
    test_Switch();
    ~test_Switch();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_constructor();
    void test_serial();
    void test_room();
    void test_class();
    void test_Instruction();
    void test_getStatus();
    void test_setDevice();
    void test_JsonConstructor();

};

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
    delete button;
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
    QVERIFY(status.value("power").toInt()==0);
}
void test_Switch::test_setDevice(){
    QJsonDocument toSet = QJsonDocument::fromJson("{\"power\":1}");
    button->setDevice(toSet);
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("power").toInt()==1);
}

void test_Switch::test_JsonConstructor(){
    QJsonDocument init = QJsonDocument::fromJson("{\"serial\":\"BBBBB\",\"room\":\"room1\",\"status\":{\"power\":1}}");
    delete button;
    button = new Switch(init);
    QVERIFY(button->getSerial()=="BBBBB");
    QVERIFY(button->getRoom()=="room1");
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("power").toInt()==1);

}

QTEST_APPLESS_MAIN(test_Switch)

#include "tst_test_switch.moc"
