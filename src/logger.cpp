#include <QCoreApplication>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QTextStream>

#include "logger.h"

void Logger::_write(const QString &str, LoggerType type, bool duplicateToStdOut)
{
    writeLn(QString(QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + " "
                    + messageTypes.at((int) type) + " " + str + "\n"), duplicateToStdOut);
}

void Logger::writeLn(const QString &str, bool duplicateToStdOut)
{
#ifdef Q_OS_WIN
    QString s = str + "\r\n";
    QString year = QDateTime::currentDateTime().toString("yyyy");
    QString month = QDateTime::currentDateTime().toString("MM");
    QString day = QDateTime::currentDateTime().toString("dd");
    QString hour = QDateTime::currentDateTime().toString("hh");
    QString pid = QString::number(QCoreApplication::applicationPid());
    QString path = QString("/logs/%1/%2/%3").arg(year, month, day);
    QString executableName = QFileInfo(QCoreApplication::applicationFilePath()).baseName();
    QDir logDir(QStandardPaths::standardLocations(QStandardPaths::DataLocation)[0] + path);
    if(logDir.exists() || logDir.mkpath(logDir.path())) {
        QFile f(logDir.path() + QString("/%1_%2_%3.log").arg(hour, executableName, pid));
        if(f.open(QIODevice::Append))
            f.write(s.toUtf8());
        f.close();
    }
    if (duplicateToStdOut) {
        QTextStream out(stdout);
        out << str << endl;
    }
#elif defined(Q_OS_LINUX)
    QTextStream out(stdout);
    out << str << endl << endl;
#endif
}

void Logger::write(const QString &str, LoggerType type, bool debugOnly, bool duplicateToStdOut)
{
    if(debugOnly) {
#ifdef QT_DEBUG
        _write(str, type, duplicateToStdOut);
#endif
    } else
        _write(str, type, duplicateToStdOut);
}

void Logger::writeNoTime(const QString &str, bool duplicateToStdOut)
{
    writeLn(str, duplicateToStdOut);
}

void Logger::writeNoTime(const QStringList &list, bool duplicateToStdOut)
{
    foreach (QString s, list)
        writeNoTime(s, duplicateToStdOut);
}
