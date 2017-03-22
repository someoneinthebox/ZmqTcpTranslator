#include "zmqbase.h"

ZmqBase::ZmqBase(nzmqt::ZMQSocket::Type type, nzmqt::ZMQContext &cnt, quint16 port, const QString &host,
                 QObject *parent) : Ip(port, parent, host)
{
    _fullAddress = "tcp://" + QString(host + ":%1").arg(QString::number((int) port));

    QString objName;

    switch(type)
    {
    case nzmqt::ZMQSocket::TYP_SUB: objName = "Subscriber.Socket.socket(SUB)";
        break;
    case nzmqt::ZMQSocket::TYP_PUB: objName = "Publisher.Socket.socket(PUB)";
        break;
    case nzmqt::ZMQSocket::TYP_REP: objName = "Replier.Socket.socket(REP)";
        break;
    case nzmqt::ZMQSocket::TYP_REQ: objName = "Requester.Socket.socket(REQ)";
        break;
    default:{}
    }

    _socket = cnt.createSocket(type, parent);
    _socket->setObjectName(objName);

    if(type != nzmqt::ZMQSocket::TYP_PUB)
        connect(_socket, &nzmqt::ZMQSocket::messageReceived, this, &ZmqBase::availableMsg);
}

bool ZmqBase::start()
{
    try
    {
        startImpl();
    }
    catch (const nzmqt::ZMQException& ex)
    {
        Logger::write("Исключение: " + QString(ex.what()), LoggerType::Debug, true);
        emit failure(ex.what());
        emit finished();
        return false;
    }

    return true;
}

bool ZmqBase::stop()
{
    emit finished();
    return true;
}
