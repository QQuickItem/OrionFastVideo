// mytcpsocket.cpp
#include "mytcpsocket.h"
#include <gtest/gtest.h>

MyTcpSocket::MyTcpSocket(QObject *parent) :
    QObject(parent)
{
}

void MyTcpSocket::doConnect()
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "connecting...";

//    qDebug() <<socket->isOpen();
//    qDebug() <<socket->isReadable();
    // this is not blocking call
    socket->connectToHost("engineersjournal.ie", 80);
//    qDebug() <<socket->isOpen();
//    qDebug() <<socket->isReadable();
//    socket->commitTransaction();
    // we need to wait...
    if(!socket->waitForConnected(5000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}

void MyTcpSocket::show()
{

}

void MyTcpSocket::connected()
{
    QUrl url("http://www.engineersjournal.ie/wp-content/uploads/2017/03/satellite.jpg");
    qDebug() << "connected...";
    socket->write("HEAD " + url.path().toUtf8() + " HTTP/1.1\r\n"
                 "Host: " + url.host().toUtf8() + "\r\n\r\n");
    // Hey server, tell me about you.
//    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
    qDebug()<<"lkdjfgj";
}

void MyTcpSocket::disconnected()
{
    qDebug() << "disconnected...";
    emit endConnect();
}

void MyTcpSocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void MyTcpSocket::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    qDebug() << socket->readAll();

    m_DownloadedData = socket->readAll();
//    qDebug()<<m_DownloadedData.size();

}

QByteArray MyTcpSocket::getByteArray()
{
    return m_DownloadedData;
}
