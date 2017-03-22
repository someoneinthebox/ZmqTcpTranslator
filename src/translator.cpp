#include <QObject>
#include <QFile>
#include <QDateTime>
#include "src/Translator.h"
#include "client.h"

void Translator::start()
{
    _logFile = new QFile(QString("logWork-%1.log")
                         .arg(QDateTime::currentDateTime().toString("dd.MM.yyyy")));
    if(_useLogs)
        if(_logFile->open(QIODevice::Append)) {
            _logFile->write(QString("Start service with params:\r\n"
                             "\tZMQ-port\t: %1\r\n"
                             "\tZMQ-host\t: %2\r\n"
                             "\tServer port\t: %3\r\n"
                             "\tServer host\t: %4\r\n\n")
                     .arg(QString::number(_zmqPort), _zmqHost, QString::number(_outPort), _outHost).toUtf8());
            _logFile->close();
        }

    QCoreApplication *app = application();
    _cnt = nzmqt::createDefaultContext();
    _cnt->start();
    _client = new Client(_outPort, _outHost, app, true, _useSendSizePack);
    _subsriber = new ZmqSub(*_cnt, _zmqPort, _zmqHost, _topic, _ignoreList, app);
    if(_useLogs)
    {
        QObject::connect(_client, &Client::connectionError, [=]
        {
            if(_logFile->open(QIODevice::Append)) {
                _logFile->write(QString("Server connection error.\r\n").toUtf8());
                _logFile->close();
            }
        });
        QObject::connect(_subsriber, &ZmqSub::failure, [=] (const QString &what)
        {
            if(_logFile->open(QIODevice::Append)) {
                _logFile->write(QString("ZMQ Service error:\t%1\r\n").arg(what).toUtf8());
                _logFile->close();
            }
        });
        QObject::connect(_subsriber, &ZmqSub::success, [=]
        {
            if(_logFile->open(QIODevice::Append)) {
                _logFile->write(QString("ZMQ success").toUtf8());
                _logFile->close();
            }
        });
        QObject::connect(_subsriber, &ZmqSub::recieveMessage, [=] (const QByteArray &arr)
        {
            if(_logFile->open(QIODevice::Append)) {
                _logFile->write(QString("Package recieved, size: %1\r\n").arg(arr.size()).toUtf8());
                _logFile->close();
            }
        });
    }
    QObject::connect(_subsriber, &ZmqSub::recieveMessage, _client, &Client::sendMessage);
    _client->start();
    _subsriber->start();
}

void Translator::stop()
{
    _client->stop();
    _cnt->stop();
    _cnt->deleteLater();
    _subsriber->stop();
    _subsriber->deleteLater();
    if(_useLogs && _logFile != nullptr)
        if(_logFile->open(QIODevice::Append)) {
            _logFile->write("Stop the service.\r\n");
            _logFile->close();
        }
}

void Translator::createApplication(int &argc, char **argv)
{
    QStringList arguments;
    for(int i = 0; i < argc; i++)
        arguments << QString(argv[i]);

    if(argc > 2) {
        for(int i = 1; i < argc; i += 2) {
            if(argc < i + 1)
                break;

            ServCommands arg = (ServCommands) _serviceCommands.indexOf(arguments.at(i));

            switch(arg) {
            case ServCommands::ZmqServer: _zmqHost = arguments.at(i + 1);
                break;
            case ServCommands::ZmqPort: _zmqPort = QString(arguments.at(i + 1)).toUInt();
                break;
            case ServCommands::OutServer: _outHost = arguments.at(i + 1);
                break;
            case ServCommands::OutPort: _outPort = QString(arguments.at(i + 1)).toUInt();
                break;
            case ServCommands::WriteLog: _useLogs = QString(arguments.at(i + 1)).toInt() == 1;
                break;
            case ServCommands::Topic: _topic = QString(arguments.at(i + 1));
                break;
            case ServCommands::IgnoreList: _ignoreList = QString(arguments.at(i + 1)).split(",");
                break;
            case ServCommands::UseSendSize: _useSendSizePack = true;
                break;
            default:{}
            }
        }
    }
    QtService::createApplication(argc, argv);
}

Translator::Translator(int argc, char **argv, const QString &fullName)
    : QtService<QCoreApplication>(argc, argv, fullName)
{
    setServiceFlags(QtServiceBase::Default);
    setStartupType(QtServiceController::AutoStartup);
    setServiceDescription(QObject::tr("Module for reception and transmission ZMQ packets through TCP/IP"));
}
