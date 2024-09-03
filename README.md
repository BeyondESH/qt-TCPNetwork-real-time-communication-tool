# TCP网络实时通讯工具

## 1. 开发流程

![流程图](https://img.beyondesh.top/c/qt.png)

## 2.QTtcp客户端的关键流程

### 2.1流程细节

工程建立，**需要在.pro加入网络权限**

创建一个基于 QTcpSocket 的Qt客户端涉及以下步骤： 

1. 创建 QTcpSocket 实例:
    - 实例化 QTcpSocket 。
2. 连接到服务器:
    - 使用 connectToHost 方法连接到服务器的IP地址和端口。
3. 发送数据到服务器:
    - 使用 write 方法发送数据。
4.  接收来自服务器的数据：
    - 为 readyRead 信号连接一个槽函数来接收数据。
5. 关闭连接:
    - 关闭 QTcpSocket 连接。

### 2.1代码实现

```cpp
class MyClient : public QObject {
    Q_OBJECT
public:
    MyClient() {
        QTcpSocket *socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::readyRead, this, &MyClient::onReadyRead);
        socket->connectToHost("server_address", 1234);
    }

private
    slots :
    void onReadyRead() {
        QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
        QByteArray data = socket->readAll();
// 处理接收到的数据
// ...
    }
}
```

这个客户端尝试连接到指定的服务器地址和端口，然后等待和处理来自服务器的数据。记得根据需要管 理和处理网络错误和异常情况。

## 3.TCP协议

### 3.1特点

QTcpSocket 类底下的API已经做好所有的封装。

 TCP（传输控制协议）是一种广泛使用的网络通信协议，设计用于在网络中的计算机之间可靠地传输数 据。它是互联网协议套件的核心部分，通常与IP（互联网协议）一起使用，合称为TCP/IP。以下是TCP协 议的一些基本特点：

1. **面向连接**：在数据传输之前，TCP 需要在发送方和接收方之间建立一个连接。这包括三次握手过 程，确保两端都准备好进行数据传输。
2. **可靠传输**：TCP 提供可靠的数据传输服务，这意味着它保证数据包准确无误地到达目的地。如果发 生数据丢失或错误，TCP 会重新发送数据包。
3. **顺序控制**：TCP 保证数据包的传输顺序。即使数据包在网络中的传输顺序被打乱，接收方也能按照 正确的顺序重组这些数据。
4. **流量控制**：TCP 使用窗口机制来控制发送方的数据传输速率，以防止网络过载。这有助于防止接收 方被发送方发送的数据所淹没。
5. **拥塞控制**：TCP 还包括拥塞控制机制，用来检测并防止网络拥塞。当网络拥塞发生时，TCP 会减少 其数据传输速率。
6.  **数据分段**：大块的数据在发送前会被分割成更小的段，以便于传输。这些段会被独立发送并在接收 端重新组装。
7. **确认和重传**：接收方对成功接收的数据包发送确认（ACK）信号。如果发送方没有收到确认，它会 重传丢失的数据包。
8. **终止连接**：数据传输完成后，TCP 连接需要被正常关闭，这通常涉及到四次挥手过程。

TCP 适用于需要高可靠性的应用，如网页浏览、文件传输、电子邮件等。然而，由于它的这些特性，TCP 在处理速度上可能不如其他协议（如UDP）那么快速。 

### 3.2三次握手（建立连接）

1. **SYN**：客户端向服务器发送一个SYN（同步序列编号）报文来开始一个新的连接。此时，客户端进 入SYN-SENT状态。
2. **SYN-ACK**：服务器接收到SYN报文后，回复一个SYN-ACK（同步和确认）报文。此时服务器进入 SYN-RECEIVED状态。
3. **ACK**：客户端接收到SYN-ACK后，发送一个ACK（确认）报文作为回应，并进入ESTABLISHED（已 建立）状态。服务器在收到这个ACK报文后，也进入ESTABLISHED状态。这标志着连接已经建立。

![](https://img.beyondesh.top/c/3.png)

### 3.3四次挥手 （断开连接）

四次挥手的目的是终止已经建立的连接。这个过程包括以下步骤：

1. **FIN**：当通信的一方完成数据发送任务后，它会发送一个FIN（结束）报文来关闭连接。发送完FIN 报文后，该方进入FIN-WAIT-1状态。
2. **ACK**：另一方接收到FIN报文后，发送一个ACK报文作为回应，并进入CLOSE-WAIT状态。发送FIN 报文的一方在收到ACK后，进入FIN-WAIT-2状态。 
3. **FIN**：在等待一段时间并完成所有数据的发送后，CLOSE-WAIT状态的一方也发送一个FIN报文来请 求关闭连接。 
4. **ACK**：最初发送FIN报文的一方在收到这个FIN报文后，发送一个ACK报文作为最后的确认，并进入 TIME-WAIT状态。经过一段时间后，确保对方接收到了最后的ACK报文，该方最终关闭连接

## 4. Socket

Socket 不是一个协议，而是一种编程接口（API）或机制，用于在网络中实现通信。Socket 通常在应用 层和传输层之间提供一个端点，使得应用程序可以通过网络发送和接收数据。它支持多种协议，主要是 TCP 和 UDP。

 以下是 Socket 的一些基本特点：

- **类型**：有两种主要类型的 Sockets —— TCP Socket（面向连接，可靠）和 UDP Socket（无连接， 不可靠）。 
- **应用**：在各种网络应用中广泛使用，如网页服务器、聊天应用、在线游戏等。 
- **编程语言支持**：大多数现代编程语言如 Python, Java, C++, 等都提供 Socket 编程的支持。 功能：提供了创建网络连接、监听传入的连接、发送和接收数据等功能。 
- **QT**: 在QT组件中，QTcpSocket用来管理和实现TCP Socket通信，QUdpSocket用来管理和实现 UDP Socket通信。

总之，Socket 是实现网络通信的基础工具之一，它抽象化了网络层的复杂性，为开发者提供了一种相对 简单的方式来建立和管理网络连接。

## 5.网络通讯核心代码

### 5.1 TCP服务端核心代码

主要步骤如下： 

1. **创建 QTcpServer 实例**：启动服务器并开始监听指定端口。 
2. **监听连接请求**：调用 listen() 方法使服务器监听特定的 IP 地址和端口。 
3. **接受连接**：当客户端尝试连接时， QTcpServer 产生一个信号。你需要实现一个槽（slot）来响应 这个信号，并接受连接。 
4. **处理客户端连接**：每个连接的客户端都关联一个 QTcpSocket 对象，用于数据交换。

```cpp
#include <QTcpServer>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTcpServer server;
// 监听端口
    if (!server.listen(QHostAddress::Any, 12345)) {
        qDebug() << "Server could not start";
        return -1;
    }
    qDebug() << "Server started!";
// 当有新连接时，执行相应的操作
    QObject::connect(&server, &QTcpServer::newConnection, [&]() {
        QTcpSocket *client = server.nextPendingConnection();
        QObject::connect(client, &QTcpSocket::readyRead, [client]() {
            QByteArray data = client->readAll();
            qDebug() << "Received data:" << data;
            client->write("Hello, client!");
        });
        QObject::connect(client, &QTcpSocket::disconnected, client,
                         &QTcpSocket::deleteLater);
    });
    return a.exec();
}

```

代码解释:

1. **创建** QTcpServer 对象：在主函数中，直接创建了一个 QTcpServer 对象。
2. **监听端口**：使用 listen() 方法监听所有接口上的 12345 端口.
3. **处理新连接**：通过连接 newConnection 信号，当有新客户端连接时，会调用相应的槽函数。 
4. **读取数据**：为每个连接的客户端创建 QTcpSocket 对象，并连接 readyRead 信号以接收数据。
5. **发送数据**：向客户端发送响应消息。
6. **客户端断开连接时的处理**：使用 disconnected 信号确保客户端在断开连接时被适当地清理。

这个代码示例展示了如何使用 QTcpServer 创建一个基本的 TCP 服务器，而无需通过继承来扩展类。这 种方式通常更简单，适用于不需要复杂处理的基本应用场景。

### 5.2TCP客户端核心代码

为了使客户端代码更具模块化和响应性，可以使用 Qt 的信号与槽机制。这种方法允许客户端以事件驱动 的方式响应网络事件，如连接建立、数据接收等。下面是一个使用信号与槽的 TCP 客户端示例。

```cpp
#include <QTcpSocket>
#include <QCoreApplication>
#include <QDebug>
class TcpClient : public QObject {
    Q_OBJECT
public:
    TcpClient(const QString &host, quint16 port) {
        connect(&socket, &QTcpSocket::connected, this, &TcpClient::onConnected);
        connect(&socket, &QTcpSocket::readyRead, this, &TcpClient::onReadyRead);
        socket.connectToHost(host, port);
    }
private slots:
    void onConnected() {
        qDebug() << "Connected to server!";
        socket.write("Hello, server!");
    }
    void onReadyRead() {
        QByteArray data = socket.readAll();
        qDebug() << "Server said:" << data;
        socket.disconnectFromHost();
    }
private:
    QTcpSocket socket;
};
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    TcpClient client("localhost", 12345);
    return a.exec();
}
#include "main.moc"
```

代码解释:

1. **创建 TcpClient 类**：这个类继承自 QObject ，允许使用信号与槽机制。
2. **连接信号和槽**：在构造函数中，将 QTcpSocket 的 connected 和 readyRead 信号分别连接到 onConnected 和 onReadyRead 槽。
3. **连接到服务器**：使用 connectToHost() 方法开始连接过程。
4. **处理连接建立**：一旦连接建立， onConnected 槽被触发，客户端向服务器发送一条消息.
5.  **接收数据**：当数据可读时， onReadyRead 槽被触发，客户端读取并打印来自服务器的数据。
6. **断开连接**：在接收数据后，客户端断开与服务器的连接。

这个客户端示例展示了如何使用 Qt 的信号与槽机制来处理 TCP 连接。这种方式使得代码更加清晰，易 于维护，并且能更好地处理异步事件。

### 5.3TCP服务端项目开发

```cpp
// 包含主窗口和用户界面定义
#include "mainwindow.h"
#include "ui_mainwindow.h"
// 主窗口构造函数
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{
// 初始化用户界面
    ui->setupUi(this);
// 设置主窗口中心部件的布局
    ui->centralwidget->setLayout(ui->verticalLayout_2);
// 设置主窗口标题
    this->setWindowTitle("网络调试助手服务端-上官QT案例");
    cursor = ui->textBrowserRev->textCursor(); // 获取文本浏览器的文本光标
// 初始时禁用“停止监听”按钮
    ui->pushButtonListenStop->setEnabled(false);
// 创建新的 TCP 服务器实例
    tcpServer = new QTcpServer(this);
// 将新连接信号连接到处理新连接的槽函数
    connect(tcpServer, SIGNAL(newConnection()), this,
            SLOT(mnewConnectionHandler()));
// 获取系统上所有网络接口，并将 IPv4 地址添加到下拉列表中
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for (const QNetworkInterface &interface : interfaces) {
        for (const QNetworkAddressEntry &entry : interface.addressEntries()) {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                ui->comboBoxIpAddr->addItem(entry.ip().toString());
            }
        }
    }
}
// 主窗口析构函数
MainWindow::~MainWindow()
{
// 释放用户界面资源
    delete ui;
}
// “开始监听”按钮的点击事件处理函数
void MainWindow::on_pushButtonListen_clicked()
{
// 侦听指定 IP 地址和端口
    tcpServer->listen(QHostAddress(ui->comboBoxIpAddr->currentText()),
                      ui->lineEditPort->text().toInt());
// 更新按钮状态
    ui->pushButtonListen->setEnabled(false);
    ui->pushButtonListenStop->setEnabled(true);
}
// 新 TCP 连接的处理函数
void MainWindow::mnewConnectionHandler()
{
// 获取下一个待处理的连接
    QTcpSocket *tmpSocket = tcpServer->nextPendingConnection();
// 向文本浏览器中添加客户端信息
    ui->textBrowserRev->append("服务器: 客户端IP地址是："+ tmpSocket-
                               >peerAddress().toString()
                                +" 客户端端口号是： "+QString::number(tmpSocket-
                                                                     >peerPort())+"\n");
// 连接套接字的状态变化和数据接收信号到相应槽函数
    connect(tmpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this, SLOT(mstateChanged(QAbstractSocket::SocketState)));
    connect(tmpSocket, SIGNAL(readyRead()), this, SLOT(mreadData()));
}
// 套接字状态改变时的槽函数
void MainWindow::mstateChanged(QAbstractSocket::SocketState state)
{
// 获取发送信号的套接字对象
    QTcpSocket *tmp = (QTcpSocket *)sender();
// 根据套接字的不同状态进行不同处理
    switch(state){
        case QAbstractSocket::UnconnectedState:
// 客户端断开连接
            ui->textBrowserRev->append("服务器：有客户端断开连接！");
            tmp->deleteLater();
            break;
        case QAbstractSocket::ConnectedState:
// 客户端连接
            ui->textBrowserRev->append("服务器：有新客户端接入！");
            break;
        default:
            break;
    }
}
// “停止监听”按钮的点击事件处理函数
void MainWindow::on_pushButtonListenStop_clicked()
{
// 更新按钮状态
    ui->pushButtonListen->setEnabled(true);
    ui->pushButtonListenStop->setEnabled(true);
// 停止监听端口
    tcpServer->close();
}
// 接收到数据时的槽函数
void MainWindow::mreadData()
{
// 获取发送信号的套接字对象
    QTcpSocket *tmp = (QTcpSocket *)sender();
    setTextColor(0,0,0); // 设置文本颜色为红色
    cursor.insertText("客户端："+ tmp->readAll()+"\n");
}
// “发送”按钮的点击事件处理函数
void MainWindow::on_pushButtonSend_clicked()
{
// 查找所有的子 QTcpSocket 对象
    QList<QTcpSocket*> socketList = tcpServer->findChildren<QTcpSocket*>();
// 向每个连接的客户端发送数据
    foreach(QTcpSocket *tmp, socketList){
        tmp->write(ui->textEditSnd->toPlainText().toUtf8());
        setTextColor(255,0,0); // 设置文本颜色为红色
        cursor.insertText("服务端："+ui->textEditSnd-
                          >toPlainText().toUtf8()+"\n");
    };
}
// 设置文本颜色的函数
void MainWindow::setTextColor(int r, int g, int b)
{
    QTextCharFormat textFormat;
    textFormat.setForeground(QBrush(QColor(r, g, b))); // 根据提供的 RGB 值设置颜色
// 应用格式到光标
    cursor.setCharFormat(textFormat);
}

```

### 5.4TCP客户端项目开发

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
// 主窗口的构造函数
    MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
            , ui(new Ui::MainWindow)
    {
        ui->setupUi(this); // 设置 UI
        ui->centralwidget->setLayout(ui->verticalLayoutGlobal); // 设置中央小部件的布局
        this->setWindowTitle("网络调试助手客户端-上官QT案例"); // 设置窗口标题
        ui->pushButtonDiscon->setEnabled(false); // 初始时禁用断开连接按钮
        cursor = ui->textBrowser->textCursor(); // 获取文本浏览器的文本光标
        tcpSocket = new QTcpSocket(this); // 创建一个新的 QTcpSocket
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(mreadDataFromServer()));
// 连接信号与槽
    }
// 析构函数
    MainWindow::~MainWindow()
    {
        delete ui; // 删除 UI
    }
// 当点击发送按钮时调用
    void MainWindow::on_pushButtonSend_clicked()
    {
        tcpSocket->write(ui->textEditSend->toPlainText().toUtf8()); // 将文本编辑器中的
        文本发送到服务器
                setTextColor(255,0,0); // 设置文本颜色为红色
        cursor.insertText("客户端： "+ui->textEditSend->toPlainText().toUtf8()+"\n");
// 在文本浏览器中插入红色文本
    }
// 从服务器读取数据
    void MainWindow::mreadDataFromServer()
    {
        setTextColor(0,0,0); // 设置文本颜色为黑色
        cursor.insertText("服务端： "+tcpSocket->readAll()+"\n"); // 在文本浏览器中插入黑
        色文本
    }
// 当点击断开连接按钮时调用
    void MainWindow::on_pushButtonDiscon_clicked()
    {
        tcpSocket->close(); // 关闭套接字连接
// 更新 UI 状态
    ui->pushButtonCon->setEnabled(true);
    ui->pushButtonDiscon->setEnabled(false);
    ui->lineEditAddr->setEnabled(true);
    ui->lineEditPort->setEnabled(true);
}
// 当点击连接按钮时调用
void MainWindow::on_pushButtonCon_clicked()
{
    tcpSocket->connectToHost(ui->lineEditAddr->text().toUtf8(),
                             ui->lineEditPort->text().toInt()); // 连接到指定的主机
    和端口
    if(tcpSocket->state() == QTcpSocket::ConnectedState){
        ui->textBrowser->append("客户端：连接服务端成功！");
    }
// 更新 UI 状态
    ui->pushButtonCon->setEnabled(false);
    ui->pushButtonDiscon->setEnabled(true);
    ui->lineEditAddr->setEnabled(false);
    ui->lineEditPort->setEnabled(false);
}
// 设置文本颜色的函数
void MainWindow::setTextColor(int r, int g, int b)
{
    QTextCharFormat textFormat;
    textFormat.setForeground(QBrush(QColor(r, g, b))); // 根据提供的 RGB 值设置颜色
// 应用格式到光标
    cursor.setCharFormat(textFormat);
}

```

