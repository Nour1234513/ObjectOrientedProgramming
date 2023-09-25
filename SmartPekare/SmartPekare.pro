TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        provashared.cpp \
        provaunique.cpp \
        stacktest.cpp

HEADERS += \
    data.h \
    lstack.h
