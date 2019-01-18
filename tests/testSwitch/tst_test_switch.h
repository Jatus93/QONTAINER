#ifndef TST_TEST_SWITCH_H
#define TST_TEST_SWITCH_H
#include <QtTest>
#include "../../IoT/switch.h"

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

#endif // TST_TEST_SWITCH_H
