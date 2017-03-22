#include "src/translator.h"
#include <QTextCodec>
#include <QTextStream>

int processArgs(int argc, char *argv[])
{
    if(argc == 2) {
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM866"));
        QTextStream out(stdout);
#if defined(Q_WS_WIN)
        out.setCodec("IBM866");
#endif
        if(QString(argv[1]) == "-h" || QString(argv[1]) == "-help") {
            out << QObject::tr("\n\t-zmqserver <ip>\t: server ZMQ."
                               "\n\t\t\t  Default, localhost;\n");
            out << QObject::tr("\t-zmqport <port>\t: server's port ZMQ."
                               "\n\t\t\t  Default, 5007;\n");
            out << QObject::tr("\t-outserver <ip>\t: server-catcher host."
                               "\n\t\t\t  Default, localhost;\n");
            out << QObject::tr("\t-outport <port>\t: server-catcher port."
                               "\n\t\t\t  Default, 9380;\n");
            out << QObject::tr("\t-topic <topic>\t: filter topic."
                               "\n\t\t\t  Default is empty;\n");
            out << QObject::tr("\t-ignore <key1,key2,...,keyN>\t: ignore some keys;\n");
            out << QObject::tr("\t-uselogs 1\t: write log;\n");
            out << QObject::tr("\t-usesendsize\t: send a package size at the start;\n\n");
            out << QObject::tr("\n%s -[i|u|e|s|v|h]\n"
                               "\t-i(nstall) [account] [password]\t: Install the service, optionally using given account and password\n"
                               "\t-u(ninstall)\t: Uninstall the service.\n"
                               "\t-e(xec)\t\t: Run as a regular application. Useful for debugging.\n"
                               "\t-t(erminate)\t: Stop the service.\n"
                               "\t-c(ommand) num\t: Send command code num to the service.\n"
                               "\t-v(ersion)\t: Print version and status information.\n"
                               "\t-h(elp)   \t: Show this help\n"
                               "\tNo arguments\t: Start the service.\n");
            return 0;
        }
        else if(QString(argv[1]) == "-v" || QString(argv[1]) == "-version") {
            QString fullVer = QString(QString::number(NVER1) + "."
                                      + QString::number(NVER2) + "."
                                      + QString::number(NVER3) + "."
                                      + QString::number(NVER4));
            out << QObject::tr("Version is - ") + fullVer + "\n\n";
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int result = processArgs(argc, argv);
    if(result > 0) {
        QString fullVer = QString(QString::number(NVER1) + "."
                + QString::number(NVER2) + "."
                + QString::number(NVER3) + "."
                + QString::number(NVER4));
        Translator a(argc, argv, "ZmqTcpTranslator_ver." + fullVer);
        return a.exec();
    }

    return result;
}
