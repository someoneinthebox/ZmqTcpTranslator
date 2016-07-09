#ifndef SOCKET_H
#define SOCKET_H

#include "ip.h"

class QNetworkSession;
class QTcpSocket;
class Client : public Ip
{
    Q_OBJECT

    QByteArray _data;
    QTcpSocket *_tcpSocket = nullptr;
    QNetworkSession *_networkSession = nullptr;
public:
    explicit Client(int port, const QString &host, QObject *parent = 0, bool useForceReconnect = false);
    virtual ~Client(){}
protected slots:
    virtual void connected(){}
    // Ip interface
    void processError(QAbstractSocket::SocketError err);
public slots:
    // Transport interface
    void sendMessage(const QByteArray &message = QByteArray());
    bool stop();
    bool start();
};

#endif
