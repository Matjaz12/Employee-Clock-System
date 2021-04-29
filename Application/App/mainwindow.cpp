#include "mainwindow.h"

MainWindow::MainWindow(Client* _clientPtr, QWidget *parent)
    :
      QMainWindow(parent),
      clientPtr{_clientPtr},
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setFixedSize(this->size());

    // Intialize UI
    intialize_employee_scroll_area();
    intialize_employee_clock_scroll_area();
    create_switch_widget_buttons();
}

MainWindow::~MainWindow()
{
    delete ui; 

    delete employeeScrollAreaLayout;
    delete employeeInfoRow;

    delete employeeScrollClockAreaLayout;
    delete employeeClockInfoRow;

    delete msgbox;
}

// Intialize UI Components

void MainWindow::intialize_employee_scroll_area()
{
    employeeScrollAreaLayout = new QFormLayout();
    ui->employee_scroll_area->widget()->setLayout(employeeScrollAreaLayout);
    employeeInfoRow = new QLabel("TAGID\t   NAME\t    LASTNAME");
    employeeInfoRow->setStyleSheet("font-weight: bold, font");
    ui->employee_scroll_area->widget()->layout()->addWidget(employeeInfoRow);

}

void MainWindow::intialize_employee_clock_scroll_area()
{
    // Intialize Employee Clock Scroll Area
    employeeScrollClockAreaLayout = new QFormLayout();
    ui->employee_clock_scroll_area->widget()->setLayout(employeeScrollClockAreaLayout);
    employeeClockInfoRow = new QLabel("TAGID    DATE    CLOCKIN    CLOCKOUT");
    employeeClockInfoRow->setStyleSheet("font-weight: bold, font");
    ui->employee_clock_scroll_area->widget()->layout()->addWidget(employeeClockInfoRow);
}

void MainWindow::create_switch_widget_buttons()
{
    /*
    Function creates and binds all switch buttons to on_switch_widget_button_clicked() function
    */

    // Bind Menu Page Buttons To Pages defined in the button Name
    unsigned int btnIndex = 2;
    for(int i = 0; i <4; i++)
    {
        QString buttonName = "btn_p1_to_p" + QString::number(btnIndex); // BtnSwitch_to_p_1
        switchWidgetButtons[i] = MainWindow::findChild<QPushButton*>(buttonName);
        connect(switchWidgetButtons[i], SIGNAL(released()), this, SLOT(on_switch_widget_button_clicked()));
        btnIndex++;
    }

    // Bind The Menu Buttons to Page 1
    unsigned int pageIndex = 2;
    for(int i = 4; i < 8; i++)
    {
        QString buttonName = "btn_p" + QString::number(pageIndex) + "_to_p1";
        switchWidgetButtons[i] = MainWindow::findChild<QPushButton*>(buttonName);
        connect(switchWidgetButtons[i],SIGNAL(released()),this,SLOT(on_switch_widget_button_clicked()));
        pageIndex++;
    }
}

void MainWindow::set_up_widget(const unsigned int widgetIndex)
{
    /*
    In case the widget is required to capture some data before it shows itself
    the function gets the data from the server and appends it to the scroll area
     */
    if(widgetIndex == 1)
    {
        std::vector<std::string> employeeData = getAllEmployees();
        if(!employeeData.empty())
            append_to_employees_scroll_area(employeeData);
    }
}

void MainWindow::append_to_employees_scroll_area(std::vector<std::string>& data)
{
    clear_employee_scroll_area();

    std::string rowString = "";
    const unsigned int numberOfColumns = 3;
    int index = 0;
    for(int i = data.size() - 1; i >= 0; i--)
    {
        if(index % numberOfColumns == 0 && index != 0)
        {
            QLabel* row = new QLabel(rowString.c_str());
            ui->employee_scroll_area->widget()->layout()->addWidget(row);
            rowString = extractDataFromMsg(data[i]) + "  ";
        }
        else
        {
            rowString += extractDataFromMsg(data[i]) + "  ";
        }

        index++;
    }
    QLabel* row = new QLabel(rowString.c_str());
    ui->employee_scroll_area->widget()->layout()->addWidget(row);

}

void MainWindow::append_to_employee_clock_scroll_area(std::vector<std::string>& data)
{
    clear_employee_clock_scroll_area();

    std::string rowString = "";
    const unsigned int numberOfColumns = 4;
    int index = 0;
    for(int i = data.size() - 1; i >= 0; i--)
    {
        if(index % numberOfColumns == 0 && index != 0)
        {
            QLabel* row = new QLabel(rowString.c_str());
            ui->employee_clock_scroll_area->widget()->layout()->addWidget(row);
            rowString = extractDataFromMsg(data[i]) + "     ";
        }
        else
        {
            rowString += extractDataFromMsg(data[i]) + "     ";
        }

        index++;
    }
    QLabel* row = new QLabel(rowString.c_str());
    ui->employee_clock_scroll_area->widget()->layout()->addWidget(row);
}

void MainWindow::create_pop_up_msg(std::string msg)
{
    msgbox = new QMessageBox(this);
    msgbox->setWindowTitle("Server: ");
    msgbox->setStyleSheet("color: rgb(189, 189, 189)");
    msgbox->setText(QString::fromLocal8Bit(extractDataFromMsg(msg).c_str()));
    msgbox->open();
}

// On Button Clicked Event Handlers

void MainWindow::on_switch_widget_button_clicked()
{
    /*
    Function gets called each time a button is pressed,
    it switches the widget based on the number in button name
    */
    QPushButton* pressedButton = (QPushButton*)sender();
    QString butval = pressedButton->objectName(); // gets button name, that was clicked
    unsigned int widgetIndex = butval[butval.length() -1].digitValue() - 1;

    set_up_widget(widgetIndex);

    ui->stackedWidget->setCurrentIndex(widgetIndex);
}

void MainWindow::on_submit_registration_btn_clicked()
{
    /*
    Function gets called each time a submit registration button is pressed,
    it passes the data from the form to client.
    Function also displays a feedback message if it was received from the server
    */

    QString tagID = ui->textEdit_1->toPlainText();
    QString name = ui->textEdit_2->toPlainText();
    QString lastName = ui->textEdit_3->toPlainText();

    if( (!tagID.isEmpty()) && !(name.isEmpty()) && !(lastName.isEmpty()))
    {
        // If form is filled out
        std::string data = "[" + tagID.toStdString() + "," + name.toStdString() + "," + lastName.toStdString() + "]";
        std::vector<std::string> receivedData = registerEmployee(data);
        if(!receivedData.empty())
            create_pop_up_msg(receivedData[0]);
    }
}

void MainWindow::on_submit_deletion_btn_clicked()
{
    /*
    Function gets called each time a submit deletion button is pressed,
    it passes the data from the form to client.
    Function also displays a feedback message if it was received from the server
    */

    QString tagID = ui->textEdit_4->toPlainText();
    if( !tagID.isEmpty())
    {
        std::string data = "[" + tagID.toStdString() + "]";
        std::vector<std::string> receivedData = deleteEmployee(data);
        if(!receivedData.empty())
            create_pop_up_msg(receivedData[0]);
    }
}

void MainWindow::on_submit_clock_btn_clicked()
{
    /*
    Function gets called each time a submit clock button is pressed,
    it passes the data from the form to client.
    Function appends the data recevied by the server in the scroll area
    */

    QString tagID = ui->textEdit_5->toPlainText();
    if( !tagID.isEmpty())
    {
        std::string data = "[" + tagID.toStdString() + "]";
        std::vector<std::string> returnedData = getEmployeeClock(data);
        if(!returnedData.empty())
        {
            append_to_employee_clock_scroll_area(returnedData);
        }
    }
}

// Forward Data

std::vector<std::string> MainWindow::getAllEmployees()
{
    return clientPtr->sendMsg("GETALL[]");
}

std::vector<std::string> MainWindow::getEmployeeClock(std::string data)
{
    return clientPtr->sendMsg("GETCLOCK" + data);
}

std::vector<std::string> MainWindow::registerEmployee(std::string data)
{
    return clientPtr->sendMsg("REGISTER" + data);
}

std::vector<std::string> MainWindow::deleteEmployee(std::string data)
{
    return clientPtr->sendMsg("DELETE" + data);
}

// Helper Functions

std::string MainWindow::extractDataFromMsg(std::string rawMsg)
{
    /*
    Function extracts the data from raw message and returns it in string form
    */
    std::string data = "";
    std::string::size_type position = rawMsg.find('[');
    data = rawMsg.substr(position + 1, rawMsg.length() - position - 2);
    return data;
}

void MainWindow::clear_employee_scroll_area()
{

    if(employeeScrollAreaLayout->rowCount() > 1)
    {
        QLayoutItem* child;
        while ((child = employeeScrollAreaLayout->takeAt(1)) != 0)
        {
                delete child->widget(); // get rid of widget too
                delete child;
         }
    }

}

void MainWindow::clear_employee_clock_scroll_area()
{

    if(employeeScrollClockAreaLayout->rowCount() > 1)
    {
        QLayoutItem* child;
        while ((child = employeeScrollClockAreaLayout->takeAt(1)) != 0)
        {
                delete child->widget(); // get rid of widget too
                delete child;
         }
    }
}

