#ifndef IP_H
#define IP_H

#include <QAbstractSocket>
#include "transport.h"

class Ip : public Transport
{
    Q_OBJECT
    QString _host;
    quint16 _port;
public:
    explicit Ip(quint16 port, QObject *parent = 0,
                const QString &host = "localhost", bool useForceReconnect = false)
        : Transport(parent, useForceReconnect), _host{host}, _port{port}{}
    virtual ~Ip(){}
    QString host() const { return _host; }
    quint16 port() { return _port; }
signals:
protected slots:
    virtual void processError(QAbstractSocket::SocketError err) { Q_UNUSED(err) }
};

#endif
