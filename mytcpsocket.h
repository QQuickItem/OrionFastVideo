#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QtNetwork>


class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);
    void doConnect();
    void show();
    QByteArray getByteArray();

signals:
    void endConnect();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();


private:
    QTcpSocket *socket;
    QNetworkSession *networkSession;
    QByteArray m_DownloadedData;
};

#endif // MYTCPSOCKET_H
