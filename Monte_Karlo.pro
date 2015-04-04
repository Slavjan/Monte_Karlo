TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    edge.cpp \
    grn.cpp \
    MonteKarloApp.cpp \
    myApp.cpp \
    ParametersReader.cpp \
    pipformat.cpp \
    point.cpp \
    polyangle.cpp \
    status.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    edge.h \
    grn.h \
    MonteKarloApp.h \
    myApp.h \
    ParametersReader.h \
    pipformat.h \
    point.h \
    polyangle.h \
    status.h \
    stdafx.h

