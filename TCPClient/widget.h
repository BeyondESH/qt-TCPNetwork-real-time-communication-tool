#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QDateTime>

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
    QString getTime();
    void btnStartState();
    void btnStopState();
private slots:
    void on_btnConnect_clicked();

    void mreadyRead_revData_fromServer();
    void on_btnSend_clicked();
    void readyConnected(QAbstractSocket::SocketState SocketState);

    void on_btnStop_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* socket;

};
#endif // WIDGET_H
