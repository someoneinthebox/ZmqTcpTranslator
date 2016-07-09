#include <QTcpSocket>
#include <QTimer>
#include "logger.h"
#include "client.h"

Client::Client(int port, const QString &host, QObject *parent, bool useForceReconnect)
    : Ip(port, parent, host, useForceReconnect), _networkSession(0)
{
    _tcpSocket = new QTcpSocket(this);
    connect(_tcpSocket, &QTcpSocket::readyRead, [=] { emit recieveMessage(_tcpSocket->readAll()); });
    connect(_tcpSocket, &QTcpSocket::connected, this, &Client::connected);
    connect(_tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(processError(QAbstractSocket::SocketError)));
    connect(_tcpSocket, &QTcpSocket::disconnected, this, &Client::disconnected);
}

bool Client::start()
{
    _tcpSocket->abort();
    int p = port();
    if (p > 0 && p <= std::numeric_limits<quint16>::max()) {
        _tcpSocket->connectToHost(host(), p);
        return true;
    } else
        return false;
}

void Client::sendMessage(const QByteArray &message)
{
    if(!message.isEmpty())
        _data = message;

    if (_tcpSocket->state() == QAbstractSocket::ConnectedState)
        _tcpSocket->write(_data);
}


void Client::processError(QAbstractSocket::SocketError err)
{
    QString s;
    switch (err) {
    case QAbstractSocket::RemoteHostClosedError:
        s += tr("Server has closed connection.");
        break;
    case QAbstractSocket::HostNotFoundError:
        s += tr("Host not found.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        s += tr("Connection refused.");
        break;
    default: s += _tcpSocket->errorString();
    }
    catchError(s);

    emit connectionError();

    if(useForceReconnect()) {
        QTimer *timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=] {
            connect(_tcpSocket, &QTcpSocket::connected, [=] {
                disconnect(SIGNAL(connected()));
                _tcpSocket->flush();
                sendMessage();
            });
            start();
            timer->deleteLater();
        });
        timer->start(1000);
    }
}

bool Client::stop()
{
    _tcpSocket->abort();
    return true;
}
