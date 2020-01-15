#-------------------------------------------------
#
# Project created by QtCreator 2019-07-16T14:25:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLCDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        vlcdialog.cpp \
    zndkvideostream.cpp \
    zndkvlcwidget.cpp \
    zndkvlcdialog.cpp

HEADERS  += vlcdialog.h \
    zndkvideostream.h \
    zndkvlcwidget.h \
    zndkvlcdialog.h

LIBS       += -LD:/VLC-Qt_1.1.0_win32_mingw/bin -lVLCQtCore -lVLCQtWidgets
INCLUDEPATH += D:/VLC-Qt_1.1.0_win32_mingw/include

win32 {
INCLUDEPATH += D:\OpenCVMinGW3.4.1\include
LIBS += D:\OpenCVMinGW3.4.1\bin\libopencv_*.dll
}
