QT += testlib

SOURCES += GameEngineTest.cpp

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += "../../lib"

TARGET=GameEngineTest

include(../../lib/lib.pri)
