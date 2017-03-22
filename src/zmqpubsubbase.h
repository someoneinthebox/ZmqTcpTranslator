#ifndef ZMQPUBSUBBASE_H
#define ZMQPUBSUBBASE_H

#include "zmqbase.h"

/*!
 * \brief The ZmqPubSubBase class
 * Базовый класс подписчика/паблишера
 */
class ZmqPubSubBase : public ZmqBase
{
    Q_OBJECT

    QString _topic;

protected:
    QString topic() const { return _topic; }

public:
    explicit ZmqPubSubBase(nzmqt::ZMQSocket::Type type, nzmqt::ZMQContext &cnt, quint16 port,
                           const QString &host, const QString &topic,  QObject *parent = 0)
        : ZmqBase(type, cnt, port, host, parent), _topic{topic}{}
    virtual ~ZmqPubSubBase(){}
};

#endif // ZMQPUBSUBBASE_H
