/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QPushButton *btn_p1_to_p4;
    QPushButton *btn_p1_to_p5;
    QPushButton *btn_p1_to_p3;
    QLabel *gh;
    QPushButton *btn_p1_to_p2;
    QWidget *page2;
    QLabel *menuLabel_5;
    QScrollArea *employee_scroll_area;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *btn_p2_to_p1;
    QWidget *page3;
    QLabel *menuLabel_2;
    QPushButton *btn_p3_to_p1;
    QScrollArea *employee_clock_scroll_area;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_5;
    QTextEdit *textEdit_5;
    QPushButton *submit_clock_btn;
    QWidget *page4;
    QLabel *menuLabel_3;
    QPushButton *btn_p4_to_p1;
    QLabel *label;
    QTextEdit *textEdit_1;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QPushButton *submit_registration_btn;
    QWidget *page5;
    QLabel *menuLabel_4;
    QPushButton *btn_p5_to_p1;
    QTextEdit *textEdit_4;
    QLabel *label_4;
    QPushButton *submit_deletion_btn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(686, 429);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(57, 57, 57);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-90, -40, 801, 491));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        btn_p1_to_p4 = new QPushButton(page1);
        btn_p1_to_p4->setObjectName(QString::fromUtf8("btn_p1_to_p4"));
        btn_p1_to_p4->setGeometry(QRect(170, 280, 511, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setStrikeOut(false);
        btn_p1_to_p4->setFont(font);
        btn_p1_to_p4->setCursor(QCursor(Qt::ArrowCursor));
        btn_p1_to_p4->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        btn_p1_to_p5 = new QPushButton(page1);
        btn_p1_to_p5->setObjectName(QString::fromUtf8("btn_p1_to_p5"));
        btn_p1_to_p5->setGeometry(QRect(170, 330, 511, 31));
        btn_p1_to_p5->setFont(font);
        btn_p1_to_p5->setCursor(QCursor(Qt::ArrowCursor));
        btn_p1_to_p5->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        btn_p1_to_p3 = new QPushButton(page1);
        btn_p1_to_p3->setObjectName(QString::fromUtf8("btn_p1_to_p3"));
        btn_p1_to_p3->setGeometry(QRect(170, 230, 511, 31));
        btn_p1_to_p3->setFont(font);
        btn_p1_to_p3->setCursor(QCursor(Qt::ArrowCursor));
        btn_p1_to_p3->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        gh = new QLabel(page1);
        gh->setObjectName(QString::fromUtf8("gh"));
        gh->setGeometry(QRect(80, 70, 701, 51));
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        gh->setFont(font1);
        gh->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"    color: rgb(189, 189, 189);"));
        btn_p1_to_p2 = new QPushButton(page1);
        btn_p1_to_p2->setObjectName(QString::fromUtf8("btn_p1_to_p2"));
        btn_p1_to_p2->setGeometry(QRect(170, 180, 511, 31));
        btn_p1_to_p2->setFont(font);
        btn_p1_to_p2->setCursor(QCursor(Qt::ArrowCursor));
        btn_p1_to_p2->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        menuLabel_5 = new QLabel(page2);
        menuLabel_5->setObjectName(QString::fromUtf8("menuLabel_5"));
        menuLabel_5->setGeometry(QRect(80, 70, 701, 51));
        menuLabel_5->setFont(font1);
        menuLabel_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"    color: rgb(189, 189, 189);"));
        employee_scroll_area = new QScrollArea(page2);
        employee_scroll_area->setObjectName(QString::fromUtf8("employee_scroll_area"));
        employee_scroll_area->setGeometry(QRect(170, 140, 511, 221));
        employee_scroll_area->setStyleSheet(QString::fromUtf8("background-color:rgb(47, 47, 47);\n"
"color:rgb(202, 202, 202);\n"
"border-color: rgb(255, 0, 0);"));
        employee_scroll_area->setFrameShape(QFrame::NoFrame);
        employee_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 511, 221));
        employee_scroll_area->setWidget(scrollAreaWidgetContents_3);
        btn_p2_to_p1 = new QPushButton(page2);
        btn_p2_to_p1->setObjectName(QString::fromUtf8("btn_p2_to_p1"));
        btn_p2_to_p1->setGeometry(QRect(170, 400, 511, 31));
        btn_p2_to_p1->setFont(font);
        btn_p2_to_p1->setCursor(QCursor(Qt::ArrowCursor));
        btn_p2_to_p1->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        menuLabel_2 = new QLabel(page3);
        menuLabel_2->setObjectName(QString::fromUtf8("menuLabel_2"));
        menuLabel_2->setGeometry(QRect(80, 70, 701, 51));
        menuLabel_2->setFont(font1);
        menuLabel_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"    color: rgb(189, 189, 189);"));
        btn_p3_to_p1 = new QPushButton(page3);
        btn_p3_to_p1->setObjectName(QString::fromUtf8("btn_p3_to_p1"));
        btn_p3_to_p1->setGeometry(QRect(170, 410, 511, 31));
        btn_p3_to_p1->setFont(font);
        btn_p3_to_p1->setCursor(QCursor(Qt::ArrowCursor));
        btn_p3_to_p1->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        employee_clock_scroll_area = new QScrollArea(page3);
        employee_clock_scroll_area->setObjectName(QString::fromUtf8("employee_clock_scroll_area"));
        employee_clock_scroll_area->setGeometry(QRect(170, 170, 511, 181));
        employee_clock_scroll_area->setStyleSheet(QString::fromUtf8("background-color:rgb(47, 47, 47);\n"
"color:rgb(202, 202, 202)"));
        employee_clock_scroll_area->setFrameShape(QFrame::NoFrame);
        employee_clock_scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 511, 181));
        employee_clock_scroll_area->setWidget(scrollAreaWidgetContents_2);
        label_5 = new QLabel(page3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 130, 81, 31));
        label_5->setStyleSheet(QString::fromUtf8("    color: rgb(189, 189, 189);"));
        textEdit_5 = new QTextEdit(page3);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(240, 130, 441, 31));
        textEdit_5->setStyleSheet(QString::fromUtf8(" color: rgb(189, 189, 189);"));
        submit_clock_btn = new QPushButton(page3);
        submit_clock_btn->setObjectName(QString::fromUtf8("submit_clock_btn"));
        submit_clock_btn->setGeometry(QRect(170, 360, 511, 31));
        submit_clock_btn->setFont(font);
        submit_clock_btn->setCursor(QCursor(Qt::ArrowCursor));
        submit_clock_btn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(95, 0, 0);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        menuLabel_3 = new QLabel(page4);
        menuLabel_3->setObjectName(QString::fromUtf8("menuLabel_3"));
        menuLabel_3->setGeometry(QRect(80, 60, 701, 51));
        menuLabel_3->setFont(font1);
        menuLabel_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"    color: rgb(189, 189, 189);"));
        btn_p4_to_p1 = new QPushButton(page4);
        btn_p4_to_p1->setObjectName(QString::fromUtf8("btn_p4_to_p1"));
        btn_p4_to_p1->setGeometry(QRect(190, 400, 511, 31));
        btn_p4_to_p1->setFont(font);
        btn_p4_to_p1->setCursor(QCursor(Qt::ArrowCursor));
        btn_p4_to_p1->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        label = new QLabel(page4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 160, 91, 31));
        label->setStyleSheet(QString::fromUtf8("    color: rgb(189, 189, 189);"));
        textEdit_1 = new QTextEdit(page4);
        textEdit_1->setObjectName(QString::fromUtf8("textEdit_1"));
        textEdit_1->setGeometry(QRect(280, 160, 451, 31));
        textEdit_1->setStyleSheet(QString::fromUtf8(" color: rgb(189, 189, 189);"));
        label_2 = new QLabel(page4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 220, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("    color: rgb(189, 189, 189);"));
        label_3 = new QLabel(page4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 280, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("    color: rgb(189, 189, 189);"));
        textEdit_2 = new QTextEdit(page4);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(280, 220, 451, 31));
        textEdit_2->setStyleSheet(QString::fromUtf8(" color: rgb(189, 189, 189);"));
        textEdit_3 = new QTextEdit(page4);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(280, 280, 451, 31));
        textEdit_3->setStyleSheet(QString::fromUtf8(" color: rgb(189, 189, 189);"));
        submit_registration_btn = new QPushButton(page4);
        submit_registration_btn->setObjectName(QString::fromUtf8("submit_registration_btn"));
        submit_registration_btn->setGeometry(QRect(190, 350, 511, 31));
        submit_registration_btn->setFont(font);
        submit_registration_btn->setCursor(QCursor(Qt::ArrowCursor));
        submit_registration_btn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(95, 0, 0);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        stackedWidget->addWidget(page4);
        page5 = new QWidget();
        page5->setObjectName(QString::fromUtf8("page5"));
        menuLabel_4 = new QLabel(page5);
        menuLabel_4->setObjectName(QString::fromUtf8("menuLabel_4"));
        menuLabel_4->setGeometry(QRect(80, 60, 701, 51));
        menuLabel_4->setFont(font1);
        menuLabel_4->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 0);\n"
"    color: rgb(189, 189, 189);"));
        btn_p5_to_p1 = new QPushButton(page5);
        btn_p5_to_p1->setObjectName(QString::fromUtf8("btn_p5_to_p1"));
        btn_p5_to_p1->setGeometry(QRect(180, 370, 511, 31));
        btn_p5_to_p1->setFont(font);
        btn_p5_to_p1->setCursor(QCursor(Qt::ArrowCursor));
        btn_p5_to_p1->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(61, 61, 61);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        textEdit_4 = new QTextEdit(page5);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(280, 160, 451, 31));
        textEdit_4->setStyleSheet(QString::fromUtf8(" color: rgb(189, 189, 189);"));
        label_4 = new QLabel(page5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 160, 91, 31));
        label_4->setStyleSheet(QString::fromUtf8("    color: rgb(189, 189, 189);"));
        submit_deletion_btn = new QPushButton(page5);
        submit_deletion_btn->setObjectName(QString::fromUtf8("submit_deletion_btn"));
        submit_deletion_btn->setGeometry(QRect(180, 310, 511, 31));
        submit_deletion_btn->setFont(font);
        submit_deletion_btn->setCursor(QCursor(Qt::ArrowCursor));
        submit_deletion_btn->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton\n"
"{\n"
"	background-color:rgb(95, 0, 0);\n"
"    color: rgb(189, 189, 189);\n"
"}"));
        stackedWidget->addWidget(page5);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn_p1_to_p4->setText(QCoreApplication::translate("MainWindow", "Register New Employee", nullptr));
        btn_p1_to_p5->setText(QCoreApplication::translate("MainWindow", "Delete Employee", nullptr));
        btn_p1_to_p3->setText(QCoreApplication::translate("MainWindow", "Get Employee Clock", nullptr));
        gh->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">                                                                          MENU</p></body></html>", nullptr));
        btn_p1_to_p2->setText(QCoreApplication::translate("MainWindow", "Get Employees", nullptr));
        menuLabel_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">EMPLOYEES</p></body></html>", nullptr));
        btn_p2_to_p1->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuLabel_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">EMPLOYEE CLOCK</p></body></html>", nullptr));
        btn_p3_to_p1->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Tag ID:</span></p></body></html>", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        submit_clock_btn->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        menuLabel_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">REGISTER EMPLOYEE</p></body></html>", nullptr));
        btn_p4_to_p1->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Tag ID:</span></p></body></html>", nullptr));
        textEdit_1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Name: </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Last Name:</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        submit_registration_btn->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        menuLabel_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">DELETE EMPLOYEE</p></body></html>", nullptr));
        btn_p5_to_p1->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt; font-weight:600;\">Tag ID:</span></p></body></html>", nullptr));
        submit_deletion_btn->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
