#include "zmqsub.h"
#include <QJsonDocument>
#include <QJsonObject>

void ZmqSub::availableMsg(const QList<QByteArray> &message)
{
    QByteArray arr = message.join();

    if(_ignoreList.size() > 0)
    {
        QJsonObject obj = QJsonDocument::fromJson(arr).object();

        foreach(QString key, _ignoreList)
            obj.remove(key);

        QJsonDocument doc(obj);
        arr = doc.toJson(QJsonDocument::Compact);
    }

    emit recieveMessage(arr);
}

void ZmqSub::startImpl()
{
    socket()->subscribeTo(topic());
    socket()->connectTo(fullAddress());
}
