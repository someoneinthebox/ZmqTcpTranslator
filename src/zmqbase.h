#ifndef TENSO_ZMQ_H
#define TENSO_ZMQ_H

#include "nzmqt/nzmqt.hpp"
#include "logger.h"
#include "ip.h"

class ZmqBase : public Ip
{
    Q_OBJECT

protected:
    explicit ZmqBase(quint16 port, const QString &host = "localhost", QObject *parent = 0)
        : Ip(port, parent, host){}
    virtual ~ZmqBase(){}
    virtual void startImpl() = 0;

signals:
    void finished();
    void failure(const QString &what);

public slots:
    bool start();
    bool stop();
};

#endif
