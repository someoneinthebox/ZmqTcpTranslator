#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QObject>
#include "logger.h"

class Transport : public QObject
{
    Q_OBJECT

    bool _useForceReconnect = false;
protected:
    bool useForceReconnect() { return _useForceReconnect; }
    void catchError(const QString &errorString, bool isDebugging = false)
    { Logger::write(errorString, LoggerType::Error, isDebugging, true); }
public:
    explicit Transport(QObject *parent = 0, bool useForceReconnect = false)
        : QObject(parent), _useForceReconnect{useForceReconnect} {}
    ~Transport(){}

signals:
    void recieveMessage(const QByteArray &message);
    void connectionError();
    void disconnected();

public slots:
    virtual void sendMessage(const QByteArray &message) { Q_UNUSED(message) }
    virtual bool start()=0;
    virtual bool stop(){ return false; }
};

#endif // TRANSPORT_H
