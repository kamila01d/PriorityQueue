#include <cppunit/TextTestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "pqueue.hpp"

int main()
{
    CppUnit::TextTestRunner runner;

    auto & registry = CppUnit::TestFactoryRegistry::getRegistry();
    runner.addTest(registry.makeTest());

    bool success = runner.run();
    return static_cast<int>(! success);
}


