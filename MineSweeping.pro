TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    pos.cpp \
    boardgen.cpp \
    boardspanner.cpp \
    matrixfinder.cpp \
    posinfo.cpp \
    humanplayer.cpp \
    matrixiter.cpp \
    doubleclicksolver.cpp \
    matrix.cpp \
    slicer.cpp

HEADERS += \
    board.h \
    pos.h \
    boardgen.h \
    boardspanner.h \
    matrixfinder.h \
    posinfo.h \
    humanplayer.h \
    matrixiter.h \
    doubleclicksolver.h \
    matrix.h \
    status.h \
    slicer.h

