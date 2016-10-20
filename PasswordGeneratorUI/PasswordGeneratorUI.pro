#-------------------------------------------------
#
# Project created by QtCreator 2016-09-09T14:02:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PasswordGeneratorUI
TEMPLATE = app

INCLUDEPATH  = ../../PasswordGenerator/

SOURCES += main.cpp\
        mainwindow.cpp \
    evaluatorchance.cpp \
    passwordgenerator.cpp


HEADERS  += mainwindow.h \
    evaluatorchance.h \
    passwordgenerator.h


FORMS    += mainwindow.ui
