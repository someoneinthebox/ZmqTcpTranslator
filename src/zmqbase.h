#ifndef TENSO_ZMQ_H
#define TENSO_ZMQ_H

#include <QThread>
#include "nzmqt/nzmqt.hpp"
#include "logger.h"
#include "ip.h"

class ZmqBase : public Ip
{
    Q_OBJECT

    nzmqt::ZMQSocket *_socket;
    QString _fullAddress;

protected:
    explicit ZmqBase(nzmqt::ZMQSocket::Type type, nzmqt::ZMQContext &cnt, quint16 port, const QString &host,
                     QObject *parent = 0);
    virtual ~ZmqBase(){}
    virtual void startImpl() = 0;
    QString fullAddress() const { return _fullAddress; }
    nzmqt::ZMQSocket *socket() { return _socket; }

signals:
    void finished();
    void failure(const QString &what);

protected slots:
    virtual void availableMsg(const QList<QByteArray> &message)=0;

public slots:
    bool start();
    bool stop();
};

#endif
