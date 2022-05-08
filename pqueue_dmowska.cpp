#include <cppunit/extensions/HelperMacros.h>
#include "pqueue.hpp"
#include <string>

class Dmowska02 : public CppUnit::TestFixture
{
CPPUNIT_TEST_SUITE(Dmowska02);
        CPPUNIT_TEST(testPierwszy);
        CPPUNIT_TEST(testDrugi);
        CPPUNIT_TEST(testTrzeci);
        CPPUNIT_TEST(testCzwarty);
    CPPUNIT_TEST_SUITE_END();

public:

    void testPierwszy()
    {
        PQueue<int> pQueue;
        int i;
        for (i = 0; i < 10; i += 2)
            pQueue.enqueue( 2*i,i);

        CPPUNIT_ASSERT( pQueue.front() == 16 );

    }

    void testDrugi()
    {
        PQueue<std::string> pQueue;
        pQueue.enqueue("foo",23);
        pQueue.enqueue("bar",0);
        pQueue.enqueue("aaa",6);
        pQueue.enqueue("bee",4);

        CPPUNIT_ASSERT( pQueue.front() == "foo" );

        pQueue.dequeue();

        CPPUNIT_ASSERT(pQueue.front() == "aaa");

    }
    void testTrzeci()
    {
        PQueue<int> pQueue;
        pQueue.enqueue(23, 0);
        pQueue.enqueue(4, 1);
        pQueue.enqueue(7, 4);
        pQueue.enqueue(56, 40);
        pQueue.enqueue(5, 7);

        PQueue<int> pQueue1;
        pQueue1.enqueue(45, 0);
        pQueue1.enqueue(89, 2);
        pQueue1.enqueue(8, 40);
        pQueue1.enqueue(6, 12);
        pQueue1.enqueue(5, 10);

        CPPUNIT_ASSERT(pQueue1.front() < pQueue.front());

    }
    void testCzwarty()
    {
        PQueue<int> pQueue;
        pQueue.enqueue(1,2);
        pQueue.enqueue(4,6);
        pQueue.enqueue(7,5);

        pQueue.dequeue();
        CPPUNIT_ASSERT(pQueue.front() == 7);
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(Dmowska02);

