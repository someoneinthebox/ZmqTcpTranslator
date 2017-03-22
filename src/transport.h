#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QObject>
#include "logger.h"

class Transport : public QObject
{
    Q_OBJECT

    bool _useForceReconnect = false;
    int _noAnswerTime = 1000;
    bool _handStop = false;
protected:
    bool useForceReconnect(){ return _useForceReconnect; }
    /*!
     * \brief handStop
     * Hand stop is using for force stop the worker
     */
    bool handStop() { return _handStop; }
    void setHandStop(bool stop) { _handStop = stop; }
    void catchError(const QString &errorString){ Logger::write(errorString, LoggerType::Error, true); }
    void setNoAnswerTime(int time){ _noAnswerTime = time; }
    int noAnswerTime(){ return _noAnswerTime; }    
public:
    explicit Transport(QObject *parent = 0, bool useForceReconnect = false)
        : QObject(parent), _useForceReconnect{useForceReconnect} {}
    ~Transport(){}

signals:
    void recieveMessage(const QByteArray &message);
    void connectionError();
    void disconnected();
    void success();
    void noAnswer();
    void stopped();

public slots:
    virtual void sendMessage(const QByteArray &message){ Q_UNUSED(message) }
    virtual bool start()=0;
    virtual bool stop(){ return false; }
};

#endif // TRANSPORT_H
