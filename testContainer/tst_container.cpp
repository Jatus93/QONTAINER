#include <QtTest>
#include <container.h>
// add necessary includes here

class test_Container : public QObject
{
    Q_OBJECT
    static Container<int> cTest;
    static Iterator<int> it;
    static int values[10];
    static int mid;
    static int last;
    static int another;
    static int test_value;
public:
    test_Container();
    ~test_Container();
    void outputTest();
private slots:
    void test_size();
    void test_pushFront();
    void test_subscription();
    void test_pushBack();
    void test_insertion();
    void test_insertionSecond();
    void test_iteratorConstructor();
    void test_iteratorIncrement();
    void test_endOfData();
    void test_Chain();
    void test_insert();
    void test_Assignment();
};

Container<int> test_Container::cTest;
Iterator<int> test_Container::it;
int test_Container::values[] = {1,2,3,4,5,6,7,8,9,0};
int test_Container::mid = 2;
int test_Container::last = 4;
int test_Container::another = 3;
int test_Container::test_value = 1;

test_Container::test_Container()
{
}

test_Container::~test_Container()
{
}

void test_Container::outputTest(){
    for(int i=0;i<cTest.size();i++)
        std::cout<<"Risultati "<<i<<" "<<cTest[i]<<' '<<&cTest[i]<<'\n';
}
void test_Container::test_size(){
    QVERIFY(cTest.size()==0);
}
void test_Container::test_pushFront()
{
    for(int i=0; i<10;i++)
        cTest.pushFront(values[i]);
    QVERIFY(cTest.size()>0);
}

void test_Container::test_subscription(){
    QVERIFY(cTest[0]==0);
}

void test_Container::test_pushBack(){
    cTest.pushBack(last);
    QVERIFY(cTest[cTest.size()-1] == last);
}

void test_Container::test_insertion(){
    cTest.insert(5,mid);
    QVERIFY(cTest[5] == mid);
}
void test_Container::test_insertionSecond(){
    cTest.insert(8,another);
    QVERIFY(cTest[8] == another);
}

void test_Container::test_iteratorConstructor(){
    it = cTest.getIterator();
    QVERIFY(*it == 0);
}

void test_Container::test_iteratorIncrement(){
    for (int i=0;i<13;i++) {
        QVERIFY(cTest[i] == *it);
        it++;
    }

}

void test_Container::test_endOfData(){
    QVERIFY(it == nullptr);
}

void test_Container::test_Chain(){
    it++;
    QVERIFY(*it == cTest[0]);
    it--;
    QVERIFY(it == nullptr);
    it--;
    QVERIFY(*it == cTest[12]);

}

void test_Container::test_insert(){
    it.insertAfter(test_value);
    it.insertBefore(test_value);
    std::cout<<cTest.size()<<'\n';
    outputTest();
    QVERIFY(cTest[14]==test_value);
    QVERIFY(cTest[12]==test_value);
}

void test_Container::test_Assignment(){
    it = &test_value;
    QVERIFY(cTest[13] == test_value);
}
QTEST_APPLESS_MAIN(test_Container)

#include "tst_container.moc"
