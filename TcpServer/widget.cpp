#include "widget.h"
#include "ui_widget.h"
#include <QList>
#include <QTcpSocket>
#include <QNetworkInterface>
#include <QDateTime>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    tcpServer= new QTcpServer(this);
    connect(ui->comboBoxClients,&ClientsCombox::comboBoxClients_clicked,this,&Widget::clientsComBox_refresh);
    ui->btnClientSuspend->setEnabled(false);
    ui->btnStopListen->setEnabled(true);
    ui->textEditRev->setEnabled(true);
    QList<QHostAddress> hostAddress=QNetworkInterface::allAddresses();
    for(QHostAddress i:hostAddress){
        if(i.protocol()==QAbstractSocket::IPv4Protocol){
            ui->comboBoxAddress->addItem(i.toString());
        }
    }
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(on_newclient_connect()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startBtnState()
{
    ui->btnListen->setText("正在监听");
    ui->btnListen->setEnabled(false);
    ui->btnClientSuspend->setEnabled(true);
    ui->btnStopListen->setEnabled(true);
    ui->comboBoxAddress->setEnabled(false);
    ui->lineEditPort->setEnabled(false);
    ui->comboBoxProtocol->setEnabled(false);
}

void Widget::stopBtnState()
{
    ui->btnListen->setText("监听");
    ui->btnListen->setEnabled(true);
    ui->btnClientSuspend->setEnabled(false);
    ui->btnStopListen->setEnabled(false);
    ui->comboBoxAddress->setEnabled(true);
    ui->lineEditPort->setEnabled(true);
    ui->comboBoxProtocol->setEnabled(true);
    ui->comboBoxClients->setEnabled(true);
}

QString Widget::getTime()
{
    qint64 timesTamp = QDateTime::currentDateTime().toSecsSinceEpoch();
    QDateTime dateTime = QDateTime::fromSecsSinceEpoch(timesTamp);
    QString tmpTime=dateTime.toString("yyyy-MM-dd hh:mm:ss");
    return tmpTime;
}

void Widget::clientsComBox_refresh()
{
    ui->comboBoxClients->clear();
    clients=tcpServer->findChildren<QTcpSocket *>();
    ui->comboBoxClients->addItem("全部客户端");
    for(QTcpSocket *i:clients){
        if(i->peerPort()!=0)
        {
            QString text="客户端: "+i->peerAddress().toString()+" 端口: "+QString::number(i->peerPort());
            ui->comboBoxClients->addItem("客户端: "+i->peerAddress().toString()+" 端口: "+QString::number(i->peerPort()));
        }
    }
}

void Widget::on_newclient_connect()
{
    if(tcpServer->hasPendingConnections())
    {
        socket=tcpServer->nextPendingConnection();
        isConnected=true;
        qDebug()<<"Client Address:"<<socket->peerAddress().toString() <<"Port:"<<socket->peerPort();
        ui->textEditRev->insertPlainText("\n连接成功 客户端IP地址:"+socket->peerAddress().toString()+" 端口:"+QString::number(socket->peerPort())+"\n");
        ui->comboBoxClients->setCurrentText(socket->peerAddress().toString());
        connect(socket,SIGNAL(readyRead()),this,SLOT(on_readyRead_handler()));
       // connect(socket,SIGNAL(disconnected()),this,SLOT(on_disconnected_handler()));
        connect(socket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),this,SLOT(mstateChanged(QAbstractSocket::SocketState)));
    }
}

void Widget::mstateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState==QAbstractSocket::SocketState::ClosingState)
    {
        QMessageBox mes;
        mes.setWindowTitle("连接状态");
        mes.setText("已断开");
        mes.exec();
    }
}

void Widget::on_btnListen_clicked()
{
    int port=ui->lineEditPort->text().toInt();
    if(!tcpServer->listen(QHostAddress(ui->comboBoxAddress->currentText()),port)||port=='\0')
    {
        qDebug()<<"监听失败";
        QMessageBox msgBox;
        msgBox.setWindowTitle("监听失败");
        if(port=='\0'){
            msgBox.setText("端口为空");
            tcpServer->close();
        }else{
            msgBox.setText("端口被占用");
            tcpServer->close();
        }
        msgBox.exec();
        return;
    }else{
        startBtnState();
    }
}


void Widget::on_btnStopListen_clicked()
{
    for(QTcpSocket *i:clients){
        i->close();
    }
    tcpServer->close();
    isConnected=false;
    ui->textEditRev->insertPlainText("\n监听结束");
    stopBtnState();
}

void Widget::on_readyRead_handler()
{
    clients = tcpServer->findChildren<QTcpSocket *>();
    for(QTcpSocket *i:clients){
        QString tmpText=QString(i->readAll());
        if(tmpText!=nullptr){
            ui->textEditRev->insertPlainText("\n ["+getTime()+"]");
            ui->textEditRev->insertPlainText("\n 对方: "+tmpText+"\n");
            ui->textEditRev->moveCursor(QTextCursor::End);
            ui->textEditRev->ensureCursorVisible();
        }
    }
}


void Widget::on_btnClientSuspend_clicked()
{
    for(QTcpSocket *i:clients){
        i->close();
    }
}

void Widget::on_btnSent_clicked()
{
    if(isConnected){
        const char *text=ui->textEditSent->toPlainText().toStdString().c_str();
        if(text[0]=='\0'){
            QMessageBox mes;
            mes.setWindowTitle("错误");
            mes.setText("内容不能为空");
            mes.exec();
            return;
        }
        if(ui->comboBoxClients->currentText().isEmpty()){
            QMessageBox mes;
            mes.setWindowTitle("错误");
            mes.setText("请选择客户端!");
            mes.exec();
        }
        else if(clientsIndex==0){
            for(QTcpSocket * i:clients){
                i->write(text);
                ui->textEditRev->insertPlainText("\n["+getTime()+"]\n我: "+text+"\n");
                ui->textEditRev->moveCursor(QTextCursor::End);
                ui->textEditRev->ensureCursorVisible();
            }
        }else{
            clients[clientsIndex-1]->write(text);
            ui->textEditRev->insertPlainText("\n["+getTime()+"]\n我: "+text+"\n");
            ui->textEditRev->moveCursor(QTextCursor::End);
            ui->textEditRev->ensureCursorVisible();
        }
    }else{
        QMessageBox mes;
        mes.setWindowTitle("错误");
        mes.setText("无连接");
        mes.exec();
    }
}
void Widget::on_comboBoxClients_activated(int index)
{
    clientsIndex=index;
    qDebug()<<index;
}

