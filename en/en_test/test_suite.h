#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <QDebug>

#include <QObject>
#include <QString>
#include <QTest>

#include <vector>

namespace en{

class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite(const QString & _test_name = "");
    virtual ~TestSuite();

    QString test_name;
    static std::vector<TestSuite *> & test_list();
};


} // namespace en
#endif // TEST_SUITE_H
