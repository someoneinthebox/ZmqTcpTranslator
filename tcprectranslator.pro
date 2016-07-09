DEFINES += NVER1=1
DEFINES += NVER2=0
DEFINES += NVER3=0
DEFINES += NVER4=0
DEFINES += NVER=NVER1.NVER2.NVER3.NVER4

# ZMQ
include($$PWD/3rdparty/nzmqt-master/nzmqt.pri)
# QtService
include($$PWD/3rdparty/qt-solutions-master/qtservice/src/qtservice.pri)

QT += core network

TARGET = tcprectranslator
CONFIG += console qt c++11

TEMPLATE = app

SOURCES += src/main.cpp \
    src/translator.cpp \
    src/transport.cpp \
    src/ip.cpp \
    src/client.cpp \
    src/logger.cpp \
    src/zmqbase.cpp \
    src/zmqsub.cpp

HEADERS += \
    src/translator.h \
    src/transport.h \
    src/ip.h \
    src/client.h \
    src/logger.h \
    src/zmqbase.h \
    src/zmqsub.h
