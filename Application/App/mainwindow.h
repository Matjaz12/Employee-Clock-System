#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QFormLayout>
#include <QGroupBox>
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include "client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define SWITCH_WIDGET_BTNS_NUM 8


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Client* _clientPtr,QWidget *parent = nullptr);
    ~MainWindow();

private:

    Client* clientPtr = nullptr;
    Ui::MainWindow *ui;

    // Components
    QPushButton* switchWidgetButtons[SWITCH_WIDGET_BTNS_NUM];
    QFormLayout* employeeScrollAreaLayout = nullptr;
    QLabel* employeeInfoRow = nullptr;
    QFormLayout* employeeScrollClockAreaLayout = nullptr;
    QLabel* employeeClockInfoRow;
    QMessageBox* msgbox = nullptr;

private slots:

    // Intialize UI Components
    void intialize_employee_scroll_area();
    void intialize_employee_clock_scroll_area();
    void create_switch_widget_buttons();
    void set_up_widget(const unsigned int widgetIndex);
    void append_to_employees_scroll_area(std::vector<std::string>& data);
    void append_to_employee_clock_scroll_area(std::vector<std::string>& data);
    void create_pop_up_msg(std::string msg);

    // On Button Clicked Event Handlers
    void on_switch_widget_button_clicked();
    void on_submit_deletion_btn_clicked();
    void on_submit_registration_btn_clicked();
    void on_submit_clock_btn_clicked();

    // Forward Data
    std::vector<std::string> getAllEmployees();
    std::vector<std::string> getEmployeeClock(std::string data);
    std::vector<std::string> registerEmployee(std::string data);
    std::vector<std::string> deleteEmployee(std::string data);

    // Helper Functions
    std::string extractDataFromMsg(std::string rawMsg);
    void clear_employee_scroll_area();
    void clear_employee_clock_scroll_area();
};
#endif // MAINWINDOW_H
