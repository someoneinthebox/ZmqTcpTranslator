#ifndef ZMQSUB_H
#define ZMQSUB_H

#include "zmqpubsubbase.h"

class ZmqSub : public ZmqPubSubBase
{
    Q_OBJECT

    QStringList _ignoreList;

protected:
    void startImpl();

public:
    explicit ZmqSub(nzmqt::ZMQContext &cnt, quint16 port, const QString &host = "localhost",
                    const QString &topic = QString(""), QStringList ignoreList = QStringList(),
                    QObject *parent = 0)
        : ZmqPubSubBase(nzmqt::ZMQSocket::TYP_SUB, cnt, port, host, topic, parent), _ignoreList{ignoreList}{}
    virtual ~ZmqSub(){}

protected slots:
    void availableMsg(const QList<QByteArray> &message);

};

#endif // ZMQSUB_H
