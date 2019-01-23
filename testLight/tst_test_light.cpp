#include <QtTest>
#include <dimmerablelight.h>
// add necessary includes here

class test_light : public QObject
{
    static std::string serial;
    static std::string room;
    static DimmerableLight* button;

    Q_OBJECT

public:
    test_light();
    ~test_light();

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
    void test_clone();

};

std::string test_light::serial = "CCCCCC10";
std::string test_light::room = "room25";
DimmerableLight* test_light::button = nullptr;

test_light::test_light()
{

}

test_light::~test_light()
{

}

void test_light::initTestCase(){

}
void test_light::cleanupTestCase(){
    delete button;
}
void test_light::test_constructor(){
    button = new DimmerableLight(serial,room);
    QVERIFY(button!=nullptr);
}
void test_light::test_serial(){
    QCOMPARE(button->getSerial(),serial);
}
void test_light::test_room(){
    QCOMPARE(button->getRoom(),room);
}
void test_light::test_class(){
    QCOMPARE(button->getClass(),"dimmerableLight");
}
void test_light::test_Instruction(){
    QJsonDocument instructions = button->getDeviceInstruction();
    std::cout<<QString(instructions.toJson()).toStdString()<<'\n';
    QVERIFY(instructions.object().value("brightness").toObject().value("min").toInt(-1) == 0);
    QVERIFY(instructions.object().value("brightness").toObject().value("max").toInt(-1) == 100);
}
void test_light::test_getStatus(){
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("height").toInt()==0);
}
void test_light::test_setDevice(){
    QJsonDocument toSet = QJsonDocument::fromJson("{\"brightness\":50}");
    button->setDevice(toSet);
    QJsonObject status = button->getStatus().object();
    QCOMPARE(status.value("brightness").toInt(),50);
}

void test_light::test_JsonConstructor(){
    QJsonDocument init = QJsonDocument::fromJson("{\"serial\":\"BBBBB\",\"room\":\"room1\",\"status\":{\"brightness\":60}}");
    delete button;
    button = new DimmerableLight(init);
    QVERIFY(button->getSerial()=="BBBBB");
    QVERIFY(button->getRoom()=="room1");
    QJsonObject status = button->getStatus().object();
    QVERIFY(status.value("brightness").toInt()==60);

}
void test_light::test_incorrectValueException(){
    std::string error = "brightness field value is not valid";
    try{
        button->setDevice(QJsonDocument::fromJson("{\"brightness\":1000}"));
    }catch(const std::invalid_argument& e){
        QCOMPARE(e.what(),error);
    }
}

void test_light::test_serializzation(){
    QJsonDocument s = button->JsonSerialize();
    std::cout<<QString(s.toJson()).toStdString()<<'\n';
    QVERIFY(true);
}

void test_light::test_clone(){
    IoT* light = button->clone();
    QCOMPARE(light->JsonSerialize(),button->JsonSerialize());
}

QTEST_APPLESS_MAIN(test_light)

#include "tst_test_light.moc"
