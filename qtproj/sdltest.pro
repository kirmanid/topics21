TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"$$_PRO_FILE_PWD_/lib/" -lSDL2.dll

SOURCES += \
        main.cpp
