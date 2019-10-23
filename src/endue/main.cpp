
#include "testing_switch.h"
#ifdef RUN_TESTS
    // this define MUST be done before including catch.hpp
    #define CATCH_CONFIG_RUNNER
    #include "catch.hpp"
#endif

#include <QApplication>
#include "endue_main_window.h"


#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    Catch::Session testing_session;
    int testFailures = testing_session.run();


    QApplication a(argc, argv);

    EndueMainWindow w;
    w.setWindowTitle(EndueMainWindow::tr("Endue"));
    w.show();

    return a.exec();
}
