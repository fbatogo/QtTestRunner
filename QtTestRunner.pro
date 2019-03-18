TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += testlib

include (QtTestRunner.pri)

SOURCES += \
        main.cpp
