#include <QtTest>
#include <iotdevices.h>
// add necessary includes here

class test_IoT_builder : public QObject
{
    static std::string serial;
    static std::string room;
    Q_OBJECT
public:
    test_IoT_builder();
    ~test_IoT_builder();

private slots:
    void test_case1();
    void test_jsonBuilder();
    void test_Cleaner();

};

std::string test_IoT_builder::serial = "CCCCCC10";
std::string test_IoT_builder::room = "room25";

test_IoT_builder::test_IoT_builder()
{

}

test_IoT_builder::~test_IoT_builder()
{

}

void test_IoT_builder::test_case1()
{
    std::list<std::string> keys = IoTBuilder::getKeys();
    std::string key;
    QList<IoT*> dev;
    foreach (key, keys) {
        dev.push_back(IoTBuilder::build(serial,key,room));
    }
    IoT* button;
    foreach(button,dev){
        QJsonDocument s = button->JsonSerialize();
        std::cout<<QString(s.toJson()).toStdString()<<'\n';
    }
}

void test_IoT_builder::test_jsonBuilder(){
    QJsonDocument conf = QJsonDocument::fromJson("{\"class\": \"shutter\",\"name\": \"CCCCCC10\",\"room\": \"room25\",\"serial\": \"CCCCCC10\",\"status\": {\"height\": 0}}");
    IoT* dev = IoTBuilder::build(conf);
    QJsonDocument s = dev->JsonSerialize();
    std::cout<<QString(s.toJson()).toStdString()<<'\n';
    QVERIFY(QString::fromLocal8Bit(conf.toJson()) == QString::fromLocal8Bit(s.toJson()));
}

void test_IoT_builder::test_Cleaner(){
    IoTBuilder::builderCleaner();
}

QTEST_APPLESS_MAIN(test_IoT_builder)

#include "tst_test_iot_builder.moc"
