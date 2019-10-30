#include "test_suite.h"

namespace en
{
    TestSuite::TestSuite(const QString &_test_name) :
        QObject(),
        test_name(_test_name)
    {
        qDebug() << "Creating test: " << test_name;
        test_list().push_back(this);
        qDebug() << test_list().size() << " tests collected";
    }

    TestSuite::~TestSuite()
    {
        qDebug() << "Destroying test: " << test_name;
    }

    std::vector<TestSuite *> & TestSuite::test_list()
    {
           static std::vector<TestSuite *> instance = std::vector<TestSuite *>();
           return instance;
    }
}

