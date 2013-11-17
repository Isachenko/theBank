TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bank.cpp \
    account.cpp

HEADERS += \
    bank.h \
    account.h

QMAKE_CXXFLAGS += -std=c++0x

