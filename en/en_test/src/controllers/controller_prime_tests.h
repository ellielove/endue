#ifndef CONTROLLER_PRIME_TESTS_H
#define CONTROLLER_PRIME_TESTS_H

#include <QTest>
#include <test_suite.h>

#include <../en_lib/src/controllers/controller_prime.h>

namespace en{
namespace controllers{

class ControllerPrimeTests : public TestSuite
{
    Q_OBJECT
public:
    ControllerPrimeTests();

private slots:
    // these four methods can be removed without consequence if unused
    void initTestCase();    // called before first test
    void cleanupTestCase(); // called after last test
    void init();            // called before each test
    void cleanup();         // called after each test

private slots:
    void methodIAmTesting__givenSomeScenario__doesCorrectThing();

private:
    ControllerPrime controller_prime;

};

} // namespace controllers
} // namespace en


#endif // CONTROLLER_PRIME_TESTS_H
