#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MyTcpSocket;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setSocket(MyTcpSocket *socket);
    void displayImage();
    ~MainWindow();

private slots:
    void setByteArray();

private:
    Ui::MainWindow *ui;
    MyTcpSocket *m_Socket;
    QByteArray m_ByteArray;
};

#endif // MAINWINDOW_H
