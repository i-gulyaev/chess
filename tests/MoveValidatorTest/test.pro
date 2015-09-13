QT += testlib

SOURCES += MoveValidatorTest.cpp

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += "../../lib"

TARGET=MoveValidatorTest

include(../../lib/lib.pri)
