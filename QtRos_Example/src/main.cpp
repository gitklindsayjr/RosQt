#include <QApplication>
#include <ros/ros.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ros::init(argc, argv, "ros_example");
    MainWindow w;
    w.show();
    return a.exec();
}
