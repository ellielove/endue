#include <QTest>
#include <test_suite.h>

using namespace en;

int main(int argc, char * argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "Starting test suite...";
    qDebug() << "Accessing tests from " << &TestSuite::test_list();
    qDebug() << TestSuite::test_list().size() << " tests detected";

    int failedTestsCout = 0;

    for(TestSuite * i : TestSuite::test_list())
    {
        qDebug() << "Executing test: " << i->test_name;
        QString filename(i->test_name + ".xml");
        int result = QTest::qExec(i, QStringList() << " " << "-o" << filename << "-xunitxml");
        qDebug() << "Test result " << result;
        if (result != 0)
        {
            failedTestsCout++;
        }
    }

    qDebug() << "Test suite complete - " << QString::number(failedTestsCout) << "failures detected";
    return failedTestsCout;
}
