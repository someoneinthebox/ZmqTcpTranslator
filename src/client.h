#ifndef SOCKET_H
#define SOCKET_H

#include "ip.h"

class QNetworkSession;
class QTcpSocket;
class Client : public Ip
{
    Q_OBJECT

    QByteArray _data;
    QTcpSocket *_tcpSocket = nullptr;
    bool _saveData = false;
    bool _sendSizeInfo = false;    
    QNetworkSession *_networkSession = nullptr;

public:    
    /*!
     * \brief Client
     * IP-Client constructor
     * \param port
     * Port
     * \param host
     * Host
     * \param useForceReconnect
     * Use force reconnect if disconnect detected
     * \param sendSizeInfo
     * Send size info before sending message
     * \param saveData
     * Save the data if disconnect detected
     */
    explicit Client(int port, const QString &host, QObject *parent = 0, bool useForceReconnect = false,
                    bool sendSizeInfo = false, bool saveData = false);
    virtual ~Client(){}

protected slots:
    virtual void connected() { emit success(); }
    // Ip interface
    void processError(QAbstractSocket::SocketError err);

public slots:
    // Transport interface
    void sendMessage(const QByteArray &message = QByteArray());
    bool stop();
    bool start();
};

#endif
