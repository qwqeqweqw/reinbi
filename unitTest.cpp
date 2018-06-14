#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "mainClass.hpp"

using namespace CppUnit;
using namespace std;

class TestClass : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestClass);
    CPPUNIT_TEST(testInsertion);
    CPPUNIT_TEST(testMedian);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testInsertion(void);
    void testMedian(void);

private:

    mainClass *mTestObj;
};


void
TestClass::testInsertion(void)
{
    mTestObj->insertValue(1);
    mTestObj->insertValue(2);
    mTestObj->insertValue(3);
    mTestObj->insertValue(4);
    mTestObj->insertValue(5);
    mTestObj->insertValue(6);
    mTestObj->insertValue(7);
    mTestObj->insertValue(8);
}

void
TestClass::testMedian(void)
{
    CPPUNIT_ASSERT(4.5 == mTestObj->getMedian());
}

void TestClass::setUp(void)
{
    mTestObj = new mainClass();
}

void TestClass::tearDown(void)
{
    delete mTestObj;
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestClass );

int main(int argc, char* argv[])
{
    CPPUNIT_NS::TestResult testresult;

    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    ofstream xmlFileOut("cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}

