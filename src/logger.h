#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QStringList>

enum class LoggerType {
    Info,
    Warning,
    Error,
    Debug
};

static QStringList messageTypes { "INF", "WAR", "ERR", "DBG" };

class Logger
{
    static void _write(const QString &str, LoggerType type, bool duplicateToStdOut);
    static void writeLn(const QString &str, bool duplicateToStdOut);
public:
    static void write(const QString &str, LoggerType type = LoggerType::Info, bool debugOnly = false,
                      bool duplicateToStdOut = false);
    static void writeNoTime(const QString &str, bool duplicateToStdOut = false);
    static void writeNoTime(const QStringList &list, bool duplicateToStdOut = false);
};

#endif // LOGGER_H
