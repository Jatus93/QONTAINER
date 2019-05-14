#include <QtTest>
#include <model.h>
#include <iotbuilder.h>
#include <iot.h>
#include <container.h>
// add necessary includes here

class test_model : public QObject
{
    Q_OBJECT

public:
    static Model* test;
    test_model();
    ~test_model();
private:
    std::string loadFile();
private slots:
    void test_Construct_Load();
    void test_save();
    void test_deviceStatus();
    void test_setDeviceStatus();
    void test_delete();
    void test_addDevice();
    void test_searchSubset();
    void test_roomAndevices();

};
Model* test_model::test = nullptr;
test_model::test_model()
{

}

test_model::~test_model()
{
    delete test;
}
std::string test_model::loadFile(){
    std::ifstream IoTfile("IoTManager.json");
    std::string devices;
    if(IoTfile.is_open()){
        std::string line;
        while (getline(IoTfile,line)) {
            devices = devices+line;
        }
    }
    return devices;
}
void test_model::test_Construct_Load()
{
    test = new Model();
}
void test_model::test_save(){
    std::string before = loadFile();
    test->save();
    std::string after = loadFile();
    QVERIFY(before == after);
}

void test_model::test_deviceStatus(){
    std::string loaded = test->getDeviceStatus(0);
    QJsonObject js = QJsonDocument::fromJson(loadFile().c_str()).object();
    QJsonDocument* device = new QJsonDocument(js.value("0").toObject().value("status").toObject());
    std::string loaded_file = device->toJson().toStdString();
    QVERIFY(loaded == loaded_file);
}

void test_model::test_setDeviceStatus(){
    std::string n_status = "{ \"class\": \"shutter\",\"name\": \"CCCCCC10\",\"room\": \"room25\",\"serial\": \"CCCCCC10\",\"status\": {\"height\": 100}}";
    QVERIFY(test->setDeviceStatus(n_status));

}

void test_model::test_delete(){
    std::string n_status = "{\"serial\": \"CCCCCC10\"}";
    QVERIFY(test->removeDevice(n_status));
}

void test_model::test_addDevice(){
    std::string n_status = "{ \"class\": \"shutter\",\"name\": \"CCCCCC10\",\"room\": \"room25\",\"serial\": \"CCCCCC10\",\"status\": {\"height\": 100}}";
    QVERIFY(test->addDevice(n_status));
}

void test_model::test_searchSubset(){
    std::string n_status = "{\"serial\":\"CCCCCC10\",\"room\": \"room25\"}";
    std::string r = test->getDeviceFiltered(n_status);
    std::string expeted = "{0:{\"class\": \"shutter\",\"name\": \"CCCCCC10\", \"room\": \"room25\", \"serial\": \"CCCCCC10\",\"status\": {\"height\": 100}}}";
    QVERIFY(QJsonDocument::fromJson(expeted.c_str()) == QJsonDocument::fromJson(r.c_str()));
}
void test_model::test_roomAndevices(){
    std::cout << test->getAllRooms() << '\n';
    std::cout << test->getAllDevicesClass() << '\n';
}
QTEST_APPLESS_MAIN(test_model)

#include "tst_model.moc"
