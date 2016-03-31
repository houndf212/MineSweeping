TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    pos.cpp \
    posmatrix.cpp \
    boardprinter.cpp \
    boardgen.cpp \
    boardspanner.cpp

HEADERS += \
    board.h \
    pos.h \
    posstatus.h \
    posmatrix.h \
    boardprinter.h \
    boardgen.h \
    boardspanner.h

