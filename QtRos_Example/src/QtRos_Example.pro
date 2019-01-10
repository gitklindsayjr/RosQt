#-------------------------------------------------
#
# Project created by QtCreator 2018-11-30T13:42:50
#
#-------------------------------------------------

QT      += core gui
CONFIG  += c++11
DEFINES += DEBUG
DEFINES += ROSRUN_JOYSTICK
DEFINES += ROSRUN_SERIAL_IO

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtRos_Example
TEMPLATE = app

RESOURCES += resources.qrc


SOURCES += main.cpp\
    mainwindow.cpp \
    qt_ros_interface.cpp \
    rosjoy_stick.cpp \
    ros_serial_io.cpp

HEADERS  += mainwindow.h \
    ui_mainwindow.h \
    qt_ros_interface.h \
    ros_serial_io.h \
    rosjoy_stick.h \
    cmd_status.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../../../../../opt/ros/kinetic/include
DEPENDPATH += $$PWD/../../../../../opt/ros/kinetic/include

unix: LIBS += -L$$PWD/../../../../../opt/ros/kinetic/lib/ -lroscpp_serialization
unix: LIBS += -L$$PWD/../../../../../opt/ros/kinetic/lib/ -lroscpp
unix: LIBS += -L$$PWD/../../../../../opt/ros/kinetic/lib/ -lrostime
unix: LIBS += -L$$PWD/../../../../../opt/ros/kinetic/lib/ -lrosconsole

DISTFILES += \
    setup.txt
