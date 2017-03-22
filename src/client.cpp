#include <QTcpSocket>
#include <QTimer>
#include "logger.h"
#include "client.h"

Client::Client(int port, const QString &host, QObject *parent, bool useForceReconnect, bool sendSizeInfo,
               bool saveData) : Ip(port, parent, host, useForceReconnect),
    _sendSizeInfo{sendSizeInfo}, _saveData{saveData}, _networkSession(0)
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
    setHandStop(false);
    _tcpSocket->disconnectFromHost();
    int p = port();
    if (p > 0 && p <= std::numeric_limits<quint16>::max())
    {
        _tcpSocket->connectToHost(host(), p);
        return _tcpSocket->waitForConnected();
    } else
        return false;
}

void Client::sendMessage(const QByteArray &message)
{
    if(!message.isEmpty())
        _data = message;

    if (_tcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        if(_sendSizeInfo && _data.size() > 0)
        {
            QByteArray sizeData = QString::number(_data.size()).toUtf8() + "\r\n";
            _tcpSocket->write(sizeData);
        }
        _tcpSocket->write(_data);
    }

    if(!_saveData)
        _data.clear();
}

void Client::processError(QAbstractSocket::SocketError err)
{
    QString s;
    switch (err)
    {
    case QAbstractSocket::RemoteHostClosedError:
        s += tr("Сервер закрыл соединение.");
        break;
    case QAbstractSocket::HostNotFoundError:
        s += tr("Хост не найден. Проверьте параметры подключения.");
        break;
    case QAbstractSocket::ConnectionRefusedError:
        s += tr("Соединение было разорвано другим узлом. Убедитесь, что сервер запущен, и проверьте " \
                "параметры подключения.");
        break;
    default: s += _tcpSocket->errorString();
    }
    catchError(s);

    emit connectionError();

    if(useForceReconnect() && !handStop())
    {
        QTimer *timer = new QTimer(this);
        timer->setSingleShot(true);
        connect(timer, &QTimer::timeout, [=] {
            connect(_tcpSocket, &QTcpSocket::connected, [=] {
                disconnect(_tcpSocket, SIGNAL(connected()));
                _tcpSocket->flush();
                sendMessage();
            });
            if(!handStop())
                start();
            timer->deleteLater();
        });
        timer->start(1000);
    }
}

bool Client::stop()
{
    setHandStop(true);
    _tcpSocket->disconnectFromHost();
    emit stopped();
    return true;
}
