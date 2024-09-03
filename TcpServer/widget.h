#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QDebug>
#include "clientscombox.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QTcpServer *tcpServer;
    QTcpSocket *socket;
    QList<QTcpSocket*> clients;
    int clientsIndex;
    void startBtnState();
    void stopBtnState();
    QString getTime();
    bool isConnected=false;
    void clientsComBox_refresh();
public slots:
    void on_newclient_connect();

    void mstateChanged(QAbstractSocket::SocketState);
private slots:
    void on_btnListen_clicked();

    void on_btnStopListen_clicked();

    void on_readyRead_handler();

    //void on_disconnected_handler();
    void on_btnClientSuspend_clicked();

    void on_btnSent_clicked();

    void on_comboBoxClients_activated(int index);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
