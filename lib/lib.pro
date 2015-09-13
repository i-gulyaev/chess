TEMPLATE=lib
TARGET=chess

QT += core

CONFIG += staticlib

DESTDIR=$$PWD
QMAKE_CXXFLAGS += -std=c++0x

HEADERS += Board.h Piece.h Move.h Square.h MoveValidator.h GameEngine.h
SOURCES += Board.cpp MoveValidator.cpp Move.cpp GameEngine.cpp


