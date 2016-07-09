TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += hwclient.cpp

INCLUDEPATH += D:\Libs\zeromq-4.0.4\include \
    ../../../_Common/Qt/console_main

LIBS += -LD:\Temp\zmq_qmake -lzmq
