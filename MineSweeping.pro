TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    pos.cpp \
    boardprinter.cpp \
    boardgen.cpp \
    boardspanner.cpp \
    statusmatrix.cpp \
    matrixfinder.cpp \
    posinfo.cpp

HEADERS += \
    board.h \
    pos.h \
    posstatus.h \
    boardprinter.h \
    boardgen.h \
    boardspanner.h \
    statusmatrix.h \
    matrixfinder.h \
    posinfo.h

