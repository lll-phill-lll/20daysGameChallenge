TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    character.cpp

QMAKE_CXXFLAGS += -lcurses
LIBS += -lncurses

HEADERS += \
    character.h
