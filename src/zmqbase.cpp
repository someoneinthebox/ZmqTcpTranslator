#include "zmqbase.h"

bool ZmqBase::start()
{
    try
    {
        startImpl();
    }
    catch (const nzmqt::ZMQException& ex)
    {
        Logger::write("Exception: " + QString(ex.what()), LoggerType::Warning, true, true);
        emit failure(ex.what());
        emit finished();
        return false;
    }

    return true;
}

bool ZmqBase::stop() {
    emit finished();
    return true;
}
