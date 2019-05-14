#include <QtTest>
#include "../IoT/shutter/shutter.h"
// add necessary includes here

class test_shutter : public QObject
{
    static std::string serial;
    static std::string room;
    static Shutter* button;

    Q_OBJECT

public:
    test_shutter();
    ~test_shutter();

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
    void test_incorrectValueException();
    void test_serializzation();

};

std::string test_shutter::serial = "CCCCCC10";
std::string test_shutter::room = "room25";
Shutter* test_shutter::button = nullptr;


test_shutter::test_shutter()
{

}

test_shutter::~test_shutter()
{

}

void test_shutter::initTestCase(){

}
void test_shutter::cleanupTestCase(){
    delete button;
}
void test_shutter::test_constructor(){
    button = new Shutter(serial,room);
    QVERIFY(button!=nullptr);
}
void test_shutter::test_serial(){
    QCOMPARE(button->getSerial(),serial);
}
void test_shutter::test_room(){
    QCOMPARE(button->getRoom(),room);
}
void test_shutter::test_class(){
    QCOMPARE(button->getClass().c_str(),"shutter");
}
void test_shutter::test_Instruction(){
    QJsonDocument instructions = button->getDeviceInstruction();
    QVERIFY(instructions.object().value("height").toObject().value("min").toInt(-1) == 0);
    QVERIFY(instructions.object().value("height").toObject().value("max").toInt(-1) == 100);
}
void test_shutter::test_getStatus(){
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("height").toInt()==0);
}
void test_shutter::test_setDevice(){
    QJsonDocument toSet = QJsonDocument::fromJson("{\"height\":50}");
    button->setDevice(toSet);
    QJsonObject status = button->getStatus().object();
    QCOMPARE(status.value("height").toInt(),50);
}

void test_shutter::test_JsonConstructor(){
    QJsonDocument init = QJsonDocument::fromJson("{\"serial\":\"BBBBB\",\"room\":\"room1\",\"status\":{\"height\":60}}");
    delete button;
    button = new Shutter(init);
    QVERIFY(button->getSerial()=="BBBBB");
    QVERIFY(button->getRoom()=="room1");
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("height").toInt()==60);

}
void test_shutter::test_incorrectValueException(){
    std::string error = "value is not valid";
    try{
        button->setDevice(QJsonDocument::fromJson("{\"height\":1000}"));
    }catch(const std::invalid_argument& e){
        QCOMPARE(e.what(),error.c_str());
    }
}

void test_shutter::test_serializzation(){
    QJsonDocument s = button->JsonSerialize();
    std::cout<<QString(s.toJson()).toStdString()<<'\n';
    QVERIFY(true);
}

QTEST_APPLESS_MAIN(test_shutter)

#include "tst_test_shutter.moc"
