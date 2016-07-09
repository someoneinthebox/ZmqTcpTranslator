TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    hwserver.cpp

INCLUDEPATH += D:\Libs\zeromq-4.0.4\include

LIBS += -LD:\Temp\zmq_qmake -lzmq
