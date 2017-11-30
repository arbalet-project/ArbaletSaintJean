TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra
SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../../Animation.h

