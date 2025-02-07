QT += core gui serialport
CONFIG += c++17
TARGET = IndustrialKeyboard
TEMPLATE = app
SOURCES += src/main.cpp \
           src/industrialbutton.cpp \
           src/keyboardhandler.cpp \
           src/serialinterface.cpp
HEADERS += include/industrialbutton.h \
           include/keyboardhandler.h \
           include/serialinterface.h