/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QGroupBox *groupBox_msp432;
    QLineEdit *lineEdit_float;
    QPushButton *pushButton_integer;
    QPushButton *pushButton_string;
    QLineEdit *lineEdit_integer;
    QLineEdit *lineEdit_string;
    QPushButton *pushButton_float;
    QGroupBox *groupBox_leds;
    QRadioButton *radioButton_ledOn;
    QRadioButton *radioButton_ledOff;
    QPushButton *pushButton_ledToggle;
    QGroupBox *groupBox_joyStick;
    QGroupBox *groupBox_buttons;
    QRadioButton *radioButton_red;
    QRadioButton *radioButton_LR;
    QRadioButton *radioButton_RR;
    QRadioButton *radioButton_orange;
    QRadioButton *radioButton_green;
    QRadioButton *radioButton_blue;
    QRadioButton *radioButton_back;
    QRadioButton *radioButton_start;
    QGroupBox *groupBox_axis;
    QLabel *label_RT;
    QLineEdit *lineEdit_hatY;
    QLineEdit *lineEdit_RT;
    QLabel *label_rightX;
    QLineEdit *lineEdit_rightY;
    QLabel *label_rightY;
    QLabel *label_leftY;
    QLabel *label_hatX;
    QLineEdit *lineEdit_leftX;
    QLineEdit *lineEdit_leftY;
    QLabel *label_hatY;
    QLabel *label_leftX;
    QLineEdit *lineEdit_LT;
    QLineEdit *lineEdit_rightX;
    QLabel *label_LT;
    QLineEdit *lineEdit_hatX;
    QLineEdit *lineEdit_nanosec;
    QLabel *label;
    QLineEdit *lineEdit_seconds;
    QLabel *label_seconds;
    QLabel *label_nanosec;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(593, 450);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 230, 561, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_msp432 = new QGroupBox(centralWidget);
        groupBox_msp432->setObjectName(QStringLiteral("groupBox_msp432"));
        groupBox_msp432->setGeometry(QRect(20, 249, 551, 161));
        QFont font;
        font.setItalic(true);
        font.setUnderline(true);
        groupBox_msp432->setFont(font);
        lineEdit_float = new QLineEdit(groupBox_msp432);
        lineEdit_float->setObjectName(QStringLiteral("lineEdit_float"));
        lineEdit_float->setGeometry(QRect(120, 70, 151, 30));
        QFont font1;
        font1.setItalic(false);
        font1.setUnderline(false);
        lineEdit_float->setFont(font1);
        lineEdit_float->setFocusPolicy(Qt::ClickFocus);
        pushButton_integer = new QPushButton(groupBox_msp432);
        pushButton_integer->setObjectName(QStringLiteral("pushButton_integer"));
        pushButton_integer->setGeometry(QRect(10, 110, 99, 30));
        pushButton_integer->setFont(font1);
        pushButton_integer->setFocusPolicy(Qt::ClickFocus);
        pushButton_string = new QPushButton(groupBox_msp432);
        pushButton_string->setObjectName(QStringLiteral("pushButton_string"));
        pushButton_string->setGeometry(QRect(10, 30, 99, 30));
        pushButton_string->setFont(font1);
        pushButton_string->setFocusPolicy(Qt::ClickFocus);
        lineEdit_integer = new QLineEdit(groupBox_msp432);
        lineEdit_integer->setObjectName(QStringLiteral("lineEdit_integer"));
        lineEdit_integer->setGeometry(QRect(120, 110, 151, 30));
        lineEdit_integer->setFont(font1);
        lineEdit_integer->setFocusPolicy(Qt::ClickFocus);
        lineEdit_string = new QLineEdit(groupBox_msp432);
        lineEdit_string->setObjectName(QStringLiteral("lineEdit_string"));
        lineEdit_string->setGeometry(QRect(120, 30, 291, 30));
        lineEdit_string->setFont(font1);
        lineEdit_string->setFocusPolicy(Qt::ClickFocus);
        pushButton_float = new QPushButton(groupBox_msp432);
        pushButton_float->setObjectName(QStringLiteral("pushButton_float"));
        pushButton_float->setGeometry(QRect(10, 70, 99, 30));
        pushButton_float->setFont(font1);
        pushButton_float->setFocusPolicy(Qt::ClickFocus);
        groupBox_leds = new QGroupBox(groupBox_msp432);
        groupBox_leds->setObjectName(QStringLiteral("groupBox_leds"));
        groupBox_leds->setGeometry(QRect(410, 20, 131, 141));
        groupBox_leds->setFont(font1);
        radioButton_ledOn = new QRadioButton(groupBox_leds);
        radioButton_ledOn->setObjectName(QStringLiteral("radioButton_ledOn"));
        radioButton_ledOn->setGeometry(QRect(10, 10, 121, 30));
        radioButton_ledOn->setFont(font1);
        radioButton_ledOn->setFocusPolicy(Qt::ClickFocus);
        radioButton_ledOff = new QRadioButton(groupBox_leds);
        radioButton_ledOff->setObjectName(QStringLiteral("radioButton_ledOff"));
        radioButton_ledOff->setGeometry(QRect(10, 50, 121, 30));
        radioButton_ledOff->setFont(font1);
        radioButton_ledOff->setFocusPolicy(Qt::ClickFocus);
        pushButton_ledToggle = new QPushButton(groupBox_leds);
        pushButton_ledToggle->setObjectName(QStringLiteral("pushButton_ledToggle"));
        pushButton_ledToggle->setGeometry(QRect(10, 90, 120, 30));
        pushButton_ledToggle->setFont(font1);
        pushButton_ledToggle->setFocusPolicy(Qt::ClickFocus);
        groupBox_joyStick = new QGroupBox(centralWidget);
        groupBox_joyStick->setObjectName(QStringLiteral("groupBox_joyStick"));
        groupBox_joyStick->setGeometry(QRect(20, 10, 581, 221));
        QFont font2;
        font2.setPointSize(12);
        font2.setItalic(true);
        font2.setUnderline(true);
        groupBox_joyStick->setFont(font2);
        groupBox_buttons = new QGroupBox(groupBox_joyStick);
        groupBox_buttons->setObjectName(QStringLiteral("groupBox_buttons"));
        groupBox_buttons->setGeometry(QRect(0, 30, 571, 51));
        groupBox_buttons->setFont(font1);
        radioButton_red = new QRadioButton(groupBox_buttons);
        radioButton_red->setObjectName(QStringLiteral("radioButton_red"));
        radioButton_red->setGeometry(QRect(80, 20, 70, 30));
        radioButton_red->setFocusPolicy(Qt::ClickFocus);
        radioButton_red->setAutoExclusive(false);
        radioButton_LR = new QRadioButton(groupBox_buttons);
        radioButton_LR->setObjectName(QStringLiteral("radioButton_LR"));
        radioButton_LR->setGeometry(QRect(310, 20, 51, 30));
        radioButton_LR->setFocusPolicy(Qt::ClickFocus);
        radioButton_LR->setAutoExclusive(false);
        radioButton_RR = new QRadioButton(groupBox_buttons);
        radioButton_RR->setObjectName(QStringLiteral("radioButton_RR"));
        radioButton_RR->setGeometry(QRect(370, 20, 51, 30));
        radioButton_RR->setFocusPolicy(Qt::ClickFocus);
        radioButton_RR->setAutoExclusive(false);
        radioButton_orange = new QRadioButton(groupBox_buttons);
        radioButton_orange->setObjectName(QStringLiteral("radioButton_orange"));
        radioButton_orange->setGeometry(QRect(220, 20, 80, 30));
        radioButton_orange->setFocusPolicy(Qt::ClickFocus);
        radioButton_orange->setAutoExclusive(false);
        radioButton_green = new QRadioButton(groupBox_buttons);
        radioButton_green->setObjectName(QStringLiteral("radioButton_green"));
        radioButton_green->setGeometry(QRect(0, 20, 70, 30));
        radioButton_green->setFocusPolicy(Qt::ClickFocus);
        radioButton_green->setAutoExclusive(false);
        radioButton_blue = new QRadioButton(groupBox_buttons);
        radioButton_blue->setObjectName(QStringLiteral("radioButton_blue"));
        radioButton_blue->setGeometry(QRect(150, 20, 61, 30));
        radioButton_blue->setFocusPolicy(Qt::ClickFocus);
        radioButton_blue->setAutoExclusive(false);
        radioButton_back = new QRadioButton(groupBox_buttons);
        radioButton_back->setObjectName(QStringLiteral("radioButton_back"));
        radioButton_back->setGeometry(QRect(430, 20, 70, 30));
        radioButton_back->setFocusPolicy(Qt::ClickFocus);
        radioButton_back->setAutoExclusive(false);
        radioButton_start = new QRadioButton(groupBox_buttons);
        radioButton_start->setObjectName(QStringLiteral("radioButton_start"));
        radioButton_start->setGeometry(QRect(500, 20, 61, 30));
        radioButton_start->setFocusPolicy(Qt::ClickFocus);
        radioButton_start->setAutoExclusive(false);
        groupBox_axis = new QGroupBox(groupBox_joyStick);
        groupBox_axis->setObjectName(QStringLiteral("groupBox_axis"));
        groupBox_axis->setGeometry(QRect(0, 80, 571, 141));
        groupBox_axis->setFont(font1);
        label_RT = new QLabel(groupBox_axis);
        label_RT->setObjectName(QStringLiteral("label_RT"));
        label_RT->setGeometry(QRect(360, 20, 61, 20));
        label_RT->setAlignment(Qt::AlignCenter);
        lineEdit_hatY = new QLineEdit(groupBox_axis);
        lineEdit_hatY->setObjectName(QStringLiteral("lineEdit_hatY"));
        lineEdit_hatY->setGeometry(QRect(500, 40, 60, 30));
        lineEdit_hatY->setFocusPolicy(Qt::NoFocus);
        lineEdit_hatY->setAlignment(Qt::AlignCenter);
        lineEdit_RT = new QLineEdit(groupBox_axis);
        lineEdit_RT->setObjectName(QStringLiteral("lineEdit_RT"));
        lineEdit_RT->setGeometry(QRect(360, 40, 60, 30));
        lineEdit_RT->setFocusPolicy(Qt::NoFocus);
        lineEdit_RT->setAlignment(Qt::AlignCenter);
        label_rightX = new QLabel(groupBox_axis);
        label_rightX->setObjectName(QStringLiteral("label_rightX"));
        label_rightX->setGeometry(QRect(150, 20, 61, 20));
        label_rightX->setAlignment(Qt::AlignCenter);
        lineEdit_rightY = new QLineEdit(groupBox_axis);
        lineEdit_rightY->setObjectName(QStringLiteral("lineEdit_rightY"));
        lineEdit_rightY->setGeometry(QRect(220, 40, 60, 30));
        lineEdit_rightY->setFocusPolicy(Qt::NoFocus);
        lineEdit_rightY->setAlignment(Qt::AlignCenter);
        label_rightY = new QLabel(groupBox_axis);
        label_rightY->setObjectName(QStringLiteral("label_rightY"));
        label_rightY->setGeometry(QRect(220, 20, 61, 20));
        label_rightY->setAlignment(Qt::AlignCenter);
        label_leftY = new QLabel(groupBox_axis);
        label_leftY->setObjectName(QStringLiteral("label_leftY"));
        label_leftY->setGeometry(QRect(80, 20, 61, 20));
        label_leftY->setAlignment(Qt::AlignCenter);
        label_hatX = new QLabel(groupBox_axis);
        label_hatX->setObjectName(QStringLiteral("label_hatX"));
        label_hatX->setGeometry(QRect(430, 20, 61, 20));
        label_hatX->setAlignment(Qt::AlignCenter);
        lineEdit_leftX = new QLineEdit(groupBox_axis);
        lineEdit_leftX->setObjectName(QStringLiteral("lineEdit_leftX"));
        lineEdit_leftX->setGeometry(QRect(10, 40, 60, 30));
        lineEdit_leftX->setFocusPolicy(Qt::NoFocus);
        lineEdit_leftX->setAlignment(Qt::AlignCenter);
        lineEdit_leftY = new QLineEdit(groupBox_axis);
        lineEdit_leftY->setObjectName(QStringLiteral("lineEdit_leftY"));
        lineEdit_leftY->setGeometry(QRect(80, 40, 60, 30));
        lineEdit_leftY->setFocusPolicy(Qt::NoFocus);
        lineEdit_leftY->setAlignment(Qt::AlignCenter);
        label_hatY = new QLabel(groupBox_axis);
        label_hatY->setObjectName(QStringLiteral("label_hatY"));
        label_hatY->setGeometry(QRect(500, 20, 61, 20));
        label_hatY->setAlignment(Qt::AlignCenter);
        label_leftX = new QLabel(groupBox_axis);
        label_leftX->setObjectName(QStringLiteral("label_leftX"));
        label_leftX->setGeometry(QRect(10, 20, 61, 20));
        label_leftX->setAlignment(Qt::AlignCenter);
        lineEdit_LT = new QLineEdit(groupBox_axis);
        lineEdit_LT->setObjectName(QStringLiteral("lineEdit_LT"));
        lineEdit_LT->setGeometry(QRect(290, 40, 60, 30));
        lineEdit_LT->setFocusPolicy(Qt::NoFocus);
        lineEdit_LT->setAlignment(Qt::AlignCenter);
        lineEdit_rightX = new QLineEdit(groupBox_axis);
        lineEdit_rightX->setObjectName(QStringLiteral("lineEdit_rightX"));
        lineEdit_rightX->setGeometry(QRect(150, 40, 60, 30));
        lineEdit_rightX->setFocusPolicy(Qt::NoFocus);
        lineEdit_rightX->setAlignment(Qt::AlignCenter);
        label_LT = new QLabel(groupBox_axis);
        label_LT->setObjectName(QStringLiteral("label_LT"));
        label_LT->setGeometry(QRect(290, 20, 61, 20));
        label_LT->setAlignment(Qt::AlignCenter);
        lineEdit_hatX = new QLineEdit(groupBox_axis);
        lineEdit_hatX->setObjectName(QStringLiteral("lineEdit_hatX"));
        lineEdit_hatX->setGeometry(QRect(430, 40, 60, 30));
        lineEdit_hatX->setFocusPolicy(Qt::NoFocus);
        lineEdit_hatX->setAlignment(Qt::AlignCenter);
        lineEdit_nanosec = new QLineEdit(groupBox_axis);
        lineEdit_nanosec->setObjectName(QStringLiteral("lineEdit_nanosec"));
        lineEdit_nanosec->setGeometry(QRect(230, 100, 110, 30));
        lineEdit_nanosec->setFocusPolicy(Qt::NoFocus);
        lineEdit_nanosec->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox_axis);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 100, 91, 30));
        lineEdit_seconds = new QLineEdit(groupBox_axis);
        lineEdit_seconds->setObjectName(QStringLiteral("lineEdit_seconds"));
        lineEdit_seconds->setGeometry(QRect(110, 100, 110, 30));
        lineEdit_seconds->setFocusPolicy(Qt::NoFocus);
        lineEdit_seconds->setAlignment(Qt::AlignCenter);
        label_seconds = new QLabel(groupBox_axis);
        label_seconds->setObjectName(QStringLiteral("label_seconds"));
        label_seconds->setGeometry(QRect(110, 80, 110, 20));
        QFont font3;
        font3.setUnderline(true);
        label_seconds->setFont(font3);
        label_seconds->setAlignment(Qt::AlignCenter);
        label_nanosec = new QLabel(groupBox_axis);
        label_nanosec->setObjectName(QStringLiteral("label_nanosec"));
        label_nanosec->setGeometry(QRect(230, 80, 110, 20));
        label_nanosec->setFont(font3);
        label_nanosec->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(radioButton_green, radioButton_red);
        QWidget::setTabOrder(radioButton_red, radioButton_blue);
        QWidget::setTabOrder(radioButton_blue, radioButton_orange);
        QWidget::setTabOrder(radioButton_orange, radioButton_LR);
        QWidget::setTabOrder(radioButton_LR, radioButton_RR);
        QWidget::setTabOrder(radioButton_RR, radioButton_back);
        QWidget::setTabOrder(radioButton_back, radioButton_start);
        QWidget::setTabOrder(radioButton_start, radioButton_ledOn);
        QWidget::setTabOrder(radioButton_ledOn, radioButton_ledOff);
        QWidget::setTabOrder(radioButton_ledOff, pushButton_ledToggle);
        QWidget::setTabOrder(pushButton_ledToggle, pushButton_string);
        QWidget::setTabOrder(pushButton_string, pushButton_float);
        QWidget::setTabOrder(pushButton_float, pushButton_integer);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ros Qt Example", 0));
        groupBox_msp432->setTitle(QApplication::translate("MainWindow", "MSP 432 Interface", 0));
        pushButton_integer->setText(QApplication::translate("MainWindow", "Get Integer", 0));
        pushButton_string->setText(QApplication::translate("MainWindow", "Get String", 0));
        pushButton_float->setText(QApplication::translate("MainWindow", "Get Float", 0));
        groupBox_leds->setTitle(QString());
        radioButton_ledOn->setText(QApplication::translate("MainWindow", "Red LED On", 0));
        radioButton_ledOff->setText(QApplication::translate("MainWindow", "Red LED Off", 0));
        pushButton_ledToggle->setText(QApplication::translate("MainWindow", "Toggle Red LED", 0));
        groupBox_joyStick->setTitle(QApplication::translate("MainWindow", "Joy Stick", 0));
        groupBox_buttons->setTitle(QApplication::translate("MainWindow", "Buttons", 0));
        radioButton_red->setText(QApplication::translate("MainWindow", "Red", 0));
        radioButton_LR->setText(QApplication::translate("MainWindow", "LR", 0));
        radioButton_RR->setText(QApplication::translate("MainWindow", "RR", 0));
        radioButton_orange->setText(QApplication::translate("MainWindow", "Orange", 0));
        radioButton_green->setText(QApplication::translate("MainWindow", "Green", 0));
        radioButton_blue->setText(QApplication::translate("MainWindow", "Blue", 0));
        radioButton_back->setText(QApplication::translate("MainWindow", "Back", 0));
        radioButton_start->setText(QApplication::translate("MainWindow", "Start", 0));
        groupBox_axis->setTitle(QApplication::translate("MainWindow", "Axis", 0));
        label_RT->setText(QApplication::translate("MainWindow", "RT", 0));
        label_rightX->setText(QApplication::translate("MainWindow", "Right X", 0));
        label_rightY->setText(QApplication::translate("MainWindow", "Right Y", 0));
        label_leftY->setText(QApplication::translate("MainWindow", "Left Y", 0));
        label_hatX->setText(QApplication::translate("MainWindow", "Hat X", 0));
        label_hatY->setText(QApplication::translate("MainWindow", "Hat Y", 0));
        label_leftX->setText(QApplication::translate("MainWindow", "Left X", 0));
        label_LT->setText(QApplication::translate("MainWindow", "LT", 0));
        label->setText(QApplication::translate("MainWindow", "Time stamp:", 0));
        label_seconds->setText(QApplication::translate("MainWindow", "Seconds", 0));
        label_nanosec->setText(QApplication::translate("MainWindow", "Nano Seconds", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
