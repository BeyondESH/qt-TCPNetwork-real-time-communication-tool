#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    ui->textEditRev->setEnabled(true);
    socket=new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(mreadyRead_revData_fromServer()));
    connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(readyConnected(QAbstractSocket::SocketState)));
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::getTime()
{
    qint64 timesTamp = QDateTime::currentDateTime().toSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timesTamp);
    QString tmpTime=dateTime.toString("yyyy-MM-dd hh:mm:ss");
    return tmpTime;
}

void Widget::btnStartState()
{
    ui->btnStop->setEnabled(true);
    ui->btnSend->setEnabled(true);
    ui->btnConnect->setEnabled(false);
}

void Widget::btnStopState()
{
    ui->btnConnect->setText("连接");
    ui->btnSend->setEnabled(false);
    ui->btnStop->setEnabled(false);
    ui->btnConnect->setEnabled(true);
}

void Widget::on_btnConnect_clicked()
{
    QHostAddress address=QHostAddress(ui->lineEditAddress->text());
    quint16 port=ui->lineEditPort->text().toInt();
    socket->connectToHost(address,port);
}

void Widget::mreadyRead_revData_fromServer()
{
    qDebug()<<1;
    QString tmpText=QString(socket->readAll());
    if(tmpText!=nullptr){
        ui->textEditRev->insertPlainText("\n");
        ui->textEditRev->insertPlainText("["+getTime()+"]"+"\n服务器 :"+tmpText);
        ui->textEditRev->moveCursor(QTextCursor::End);
        ui->textEditRev->ensureCursorVisible();
    }
}


void Widget::on_btnSend_clicked()
{
    QString sendText=ui->textEditSend->toPlainText();
    if(sendText.isEmpty()){
        QMessageBox mes;
        mes.setWindowTitle("错误");
        mes.setText("发送内容为空");
        mes.exec();
        return;
    }else{
        socket->write(sendText.toStdString().c_str());
        ui->textEditRev->insertPlainText("\n");
        ui->textEditRev->insertPlainText("["+getTime()+"]\n我: "+sendText.toStdString().c_str());
        ui->textEditRev->moveCursor(QTextCursor::End);
        ui->textEditRev->ensureCursorVisible();
    }
}

void Widget::readyConnected(QAbstractSocket::SocketState SocketState)
{
    if(SocketState==QAbstractSocket::ConnectingState){
        ui->btnConnect->setText("正在连接");
        btnStartState();
    }
    else if(SocketState==QAbstractSocket::ConnectedState){
        ui->textEditRev->insertPlainText("\n连接成功 服务器IP地址: "+socket->peerAddress().toString()+" 端口: "+QString::number(socket->peerPort()));
        ui->btnConnect->setText("已连接");
    }else if(SocketState==QAbstractSocket::UnconnectedState){
        btnStopState();
    }
}


void Widget::on_btnStop_clicked()
{

    if(socket->state()==QAbstractSocket::ConnectedState){
        socket->close();
        QMessageBox mes;
        mes.setWindowTitle("状态");
        mes.setText("连接已断开");
        mes.exec();
        btnStopState();
    }
}

