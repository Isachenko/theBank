TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    bank.cpp \
    account.cpp \
    saveAccount.cpp \
    timedMaturityAccaount.cpp \
    checkingAccount.cpp \
    overdraftAccount.cpp

HEADERS += \
    bank.h \
    account.h

QMAKE_CXXFLAGS += -std=c++0x

