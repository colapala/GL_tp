TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    lexer.cpp \
    symbole.cpp \
    etat.cpp \
    automate.cpp

HEADERS += \
    lexer.h \
    symbole.h \
    etat.h \
    automate.h
