#include "timermainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerMainWindow w;
    w.show();

    return a.exec();
}
