#-------------------------------------------------
#
# Project created by QtCreator 2013-05-18T11:18:51
#
#-------------------------------------------------

QT       += core opengl
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hilbert
TEMPLATE = app

LIBS += `pkg-config --libs glu`
CFLAGS += `pkg-config --cflags glu`

SOURCES += main.cpp \
    myGLWidget.cpp \
    mainwindow.cpp \
    turtle.cpp \
    state.cpp

HEADERS  += \
    myGLWidget.h \
    mainwindow.h \
    turtle.h \
    state.h
