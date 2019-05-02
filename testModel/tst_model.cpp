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

private slots:
    void test_case1();
    void test_serialize();

};
Model* test_model::test = nullptr;
test_model::test_model()
{

}

test_model::~test_model()
{

}

void test_model::test_case1()
{
    test = new Model();
}
void test_model::test_serialize(){

}

QTEST_APPLESS_MAIN(test_model)

#include "tst_model.moc"
