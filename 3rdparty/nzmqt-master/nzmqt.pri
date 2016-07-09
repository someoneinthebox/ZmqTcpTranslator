# Include this file into your project to build and link
# the nzmqt library into you application

# This define will "move" nzmqt class method
# implementations to nzmqt.cpp file.
INCLUDEPATH += \
    $$PWD/include \
    $$PWD/include/nzmqt \
    $$PWD/../zeromq-4.0.4/include

HEADERS += $$PWD/include/nzmqt/nzmqt.hpp

win32:LIBS += -L$$PWD/../nzmqt/zmq_qmake -lzmq
