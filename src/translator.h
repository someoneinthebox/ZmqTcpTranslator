#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "qtservice.h"
#include "zmqsub.h"

class Client;
class QFile;
class Translator : public QtService<QCoreApplication>
{
    enum class ServCommands {
        ZmqServer,
        ZmqPort,
        OutServer,
        OutPort,
        WriteLog,
        Topic,
        IgnoreList,
        UseSendSize
    };

    QStringList _serviceCommands { "-zmqserver", "-zmqport", "-outserver", "-outport", "-uselogs", "-topic",
                                   "-ignore", "-usesendsize" };

    QString _zmqHost = "localhost";
    quint16 _zmqPort = 5007;
    QString _outHost = "localhost";
    quint16 _outPort = 9380;
    QString _topic = "";
    QStringList _ignoreList;
    bool _useSendSizePack = false;

    ZmqSub *_subsriber = nullptr;
    nzmqt::ZMQContext *_cnt;
    Client *_client = nullptr;
    bool _useLogs = false;
    QFile *_logFile = nullptr;
protected:
    void start();
    void stop();
    void createApplication(int &argc, char **argv);
public:
    explicit Translator(int argc, char **argv, const QString &fullName);
    ~Translator(){}
};

#endif // TRANSLATOR_H
