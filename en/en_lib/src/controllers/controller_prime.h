#ifndef CONTROLLER_PRIME_H
#define CONTROLLER_PRIME_H

#include <../../en_lib/src/en_lib_global.h>
#include <QObject>

namespace en {
namespace controllers {

class EN_LIBSHARED_EXPORT ControllerPrime : public QObject
{
    Q_OBJECT

public:
    explicit ControllerPrime(QObject * parent = nullptr);

    const QString test_message = QString("Test Message");
};




} // namespace controllers
} // namespace en
#endif // CONTROLLER_PRIME_H
