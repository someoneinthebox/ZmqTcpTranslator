#ifndef ZMQSUB_H
#define ZMQSUB_H

#include "zmqbase.h"

class ZmqSub : public ZmqBase
{
    Q_OBJECT

    nzmqt::ZMQSocket *_socket;
    QString _topic;

protected:
    void startImpl();

public:
    explicit ZmqSub(nzmqt::ZMQContext &cnt, quint16 port, const QString &host = "localhost",
                    const QString &topic = QString(""), QObject *parent = 0);
    virtual ~ZmqSub(){}

public slots:
    void messageReceived(const QList<QByteArray>& message);

};

#endif // ZMQSUB_H
