#include <QCoreApplication>
#include <QDebug>
#include "testingclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestingClass testingObject;
    qDebug() << testingObject.toSquare(5);

    return a.exec();
}
