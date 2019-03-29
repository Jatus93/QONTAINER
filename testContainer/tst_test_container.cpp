#include <QtTest>
#include <container.h>
// add necessary includes here

class test_container : public QObject
{
    Q_OBJECT
    static container::Container<int>* list;
public:
    test_container();
    ~test_container();

private slots:
    void test_push_back();

};

container::Container<int>* test_container::list = nullptr;

test_container::test_container()
{
    list = new container::Container<int>();
}

test_container::~test_container()
{

}

void test_container::test_push_back()
{
    list->push_back(1);
    list->push_back(2);
    container::Container<int>::ContainerIterator last = list->getLast();
    container::Container<int>::ContainerIterator first = list->getFirst();
    QCOMPARE(*last,2);
    QCOMPARE(*first,1);
}

QTEST_APPLESS_MAIN(test_container)

#include "tst_test_container.moc"
