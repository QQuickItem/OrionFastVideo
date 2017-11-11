#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpsocket.h"
#include <QLabel>
#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

void MainWindow::setSocket(MyTcpSocket *socket)
{
    m_Socket = socket;
//    connect(m_Socket, SIGNAL(endConnect()), this, SLOT(setByteArray));
    connect(m_Socket, &MyTcpSocket::endConnect, this, &MainWindow::setByteArray);
}

void MainWindow::displayImage()
{
//    QPixmap pix;
//    pix.load("satellite.jpg");
//    QByteArray bArray;
//    QBuffer buffer(&bArray);
//    buffer.open(QIODevice::WriteOnly);
//    pix.save(&buffer, "JPG");

//    QPixmap pix;
//    pix.load("satellite.jpg");
//    QByteArray bArray;
//    QBuffer buffer(&bArray);
//    buffer.open(QIODevice::WriteOnly);
//    pix.save(&buffer, "JPG");

    QPixmap pix2;
    pix2.loadFromData(m_ByteArray, "JPG");
    ui->imageLabel->setPixmap(pix2);


//    QImage image;
////    image.loadFromData(m_ByteArray, "JPG");
//    image.loadFromData("satellite.jpg", "JPG");


//    ui->imageLabel->setPixmap(QPixmap::fromImage(image));
//    ui->imageLabel->setText("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
}

void MainWindow::setByteArray()
{
    m_ByteArray = m_Socket->getByteArray();
    qDebug()<<m_ByteArray.size();
    displayImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}
