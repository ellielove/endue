#include "controller_prime_tests.h"

namespace en{
namespace controllers{

static ControllerPrimeTests instance;

ControllerPrimeTests::ControllerPrimeTests() :
    TestSuite("ControllerPrime Tests")
{}
} // namespace controllers

namespace controllers {
    // these can be removed if we need
    void ControllerPrimeTests::initTestCase(){}
    void ControllerPrimeTests::cleanupTestCase(){}
    void ControllerPrimeTests::init(){}
    void ControllerPrimeTests::cleanup(){}
} // namespace controllers

namespace controllers{
    void ControllerPrimeTests::
    methodIAmTesting__givenSomeScenario__doesCorrectThing()
    {
        QCOMPARE(controller_prime.test_message, QString("Test Message"));
    }

} // namespace controllers
} // namespace en

