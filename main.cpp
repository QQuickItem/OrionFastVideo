#include "mainwindow.h"
#include <QApplication>
#include "mytcpsocket.h"
#include <QByteArray>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MyTcpSocket s;
    s.doConnect();
    MainWindow w;

    w.setSocket(&s);

    w.show();

    return a.exec();
}
