#include "zmqsub.h"

ZmqSub::ZmqSub(nzmqt::ZMQContext &cnt, quint16 port, const QString &host, const QString &topic,
               QObject *parent)
    : ZmqBase(port, host, parent), _topic{topic}
{
    _socket = cnt.createSocket(nzmqt::ZMQSocket::TYP_SUB, this);
    _socket->setObjectName("Subscriber.Socket.socket(SUB)");
    connect(_socket, SIGNAL(messageReceived(const QList<QByteArray>&)),
            this, SLOT(messageReceived(const QList<QByteArray>&)));
}

void ZmqSub::messageReceived(const QList<QByteArray> &message)
{
    QByteArray arr;
    foreach(QByteArray msg, message)
        arr.append(msg);

    emit recieveMessage(arr);
}

void ZmqSub::startImpl()
{
    QString fullAddress = "tcp://" + QString(host() + ":%1").arg(QString::number((int) port()));
    _socket->subscribeTo(_topic);
    _socket->connectTo(fullAddress);
}
