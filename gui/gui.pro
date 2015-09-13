TEMPLATE=app
TARGET=chess

QT += quick core

DESTDIR=$$PWD

QMAKE_CXXFLAGS += -std=c++0x -Wall -pedantic

include(../lib/lib.pri)

INCLUDEPATH += ../lib

LIBS += -lchess -L../lib

HEADERS += GameState.h GameEngineProxy.h ChessTypes.h
SOURCES += main.cpp GameEngineProxy.cpp
