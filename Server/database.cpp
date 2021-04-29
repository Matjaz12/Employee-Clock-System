#include "DataBase.hpp"

// Setup

void db::openDataBase(const char* path, sqlite3* dbPointer)
{
    /*
    Function tries to open database
    */
    int exit = 0;
    exit = sqlite3_open(path, &dbPointer);
    if (exit) {
        std::cerr << "Error opening Database! " << sqlite3_errmsg(dbPointer) << std::endl;
    }
    else
        std::cout << "Opened Database Successfully!" << std::endl;

    sqlite3_close(dbPointer);
}

void db::createEmployeeTable(const char* path, sqlite3* dbPointer)
{
    /*
    Function creates EMLOYEE table
    */
    std::string sql = "CREATE TABLE EMPLOYEE("
        "TAGID STRING   TEXT    PRIMARY KEY NOT NULL,"
        "NAME           TEXT    NOT NULL, "
        "LASTNAME       TEXT    NOT NULL);";

    int exit = sqlite3_open(path, &dbPointer);
    char* errorMassagge;
    exit = sqlite3_exec(dbPointer, sql.c_str(), NULL, 0, &errorMassagge);

    if (exit != SQLITE_OK)
    {
        std::cout << "Table Already Exists\n";
        sqlite3_free(errorMassagge);
    }
    else
        std::cout << "Table Created Successfully\n";

    sqlite3_close(dbPointer);
}

void db::createClockTable(const char* path, sqlite3* dbPointer)
{
    /*
    Function create a Clock table
    */
    std::string sql = "CREATE TABLE CLOCK("
        "TAGID          STRING        KEY NOT NULL,"
        "DATE           STRING        NOT NULL,"
        "TIMEIN         STRING           NULL,"
        "TIMEOUT        STRING           NULL,"
        "FOREIGN KEY(TAGID) REFERENCES EMPLOYEE(TAGID)"
        "ON DELETE CASCADE);";

    int exit = sqlite3_open(path, &dbPointer);
    char* errorMassagge;
    exit = sqlite3_exec(dbPointer, sql.c_str(), NULL, 0, &errorMassagge);

    if (exit != SQLITE_OK)
    {
        std::cout << "Table Already Exists\n";
        sqlite3_free(errorMassagge);
    }
    else
        std::cout << "Table Created Successfully\n";

    sqlite3_close(dbPointer);

}


// Write

void db::insert(const char* path, sqlite3* dbPointer, const std::string& table, const std::vector<std::string>& parameters)
{
    /*
    Function takes in parameters in string form, it forms an insert query and tries to update the data base
    */
    int exit = sqlite3_open(path, &dbPointer);

    std::string insertQuery = "INSERT INTO " + table + " VALUES(";
    for (unsigned int i{ 0 }; i < parameters.size(); i++)
    {
        if (i < parameters.size() - 1)
            insertQuery += parameters.at(i) + ", ";
        else
            insertQuery += parameters.at(i);
    }
    insertQuery += ");";
    std::cout << insertQuery << "\n";
    char* errorMassagge;
    exit = sqlite3_exec(dbPointer, insertQuery.c_str(), NULL, 0, &errorMassagge); // try to execute a query

    if (exit != SQLITE_OK)
    {
        std::cerr << "Insertion to: " + table + " Failed, check if provided Parameters Match the Parameters of the Table\n";
        sqlite3_free(errorMassagge);
    }
    else
        std::cout << "Record Successfully Inserted\n";

    sqlite3_close(dbPointer); // close the database
}

void db::deleteInstance(const char* path, sqlite3* dbPointer, const std::string& table, const std::string& primaryKey, const std::string& value)
{
    /*
    Function forms a delete query and deletes instance that matches the primaryKey
    */

    int exit = sqlite3_open(path, &dbPointer);
    std::string deleteQuery = "DELETE FROM " + table + " WHERE " + primaryKey + " = " + value;

    char* errorMassagge;
    exit = sqlite3_exec(dbPointer, deleteQuery.c_str(), NULL, 0, &errorMassagge);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Deleting " << primaryKey << " = " << value << " from Table " << table << " Failed\n";
        sqlite3_free(errorMassagge);
    }
    else
        std::cout << "Record deleted Successfully!\n";

    sqlite3_close(dbPointer); // close the database
}

void db::updateClockOut(const char* path, sqlite3* dbPointer, const std::string& tagID, const std::string& date, const std::string& updateCol, const std::string& newValue)
{
    /*
    Function updates clockIn/clockOut time
    */
    std::string updateQuery = "UPDATE CLOCK SET " + updateCol + " = " + newValue + " WHERE TAGID = " + tagID + " AND DATE = " + date;
    int exit = sqlite3_open(path, &dbPointer);

    char* errorMassagge;
    std::cout << updateQuery << "\n";
    exit = sqlite3_exec(dbPointer, updateQuery.c_str(), NULL, NULL, &errorMassagge);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Update Failed\n";
        sqlite3_free(errorMassagge);
    }
    else
        std::cout << "Record Successfully Updated\n";

    sqlite3_close(dbPointer); // close the database
}



// Read

static int appendToVector(void* ptr, int count, char** data, char** columns)
{
    std::vector<std::string>* vectorPointer = static_cast<std::vector<std::string>*>(ptr);

    for (int idx = 0; idx < count; idx++)
    {
        std::string row = static_cast<std::string>(columns[idx])  +  "[" + static_cast<std::string>(data[idx]) + "]";
        vectorPointer->push_back(row);
    }
    return 0;
}

std::vector<std::string> db::getInstances(const char* path, sqlite3* dbPointer, const std::string& table, const std::string& parameter, const std::string& value)
{
    /*
    Function returns all instances that match the given value in vector form
    */
    std::vector<std::string> vector;
    std::vector<std::string>* vectorPointer = &vector;

    int exit = sqlite3_open(path, &dbPointer);
    std::string selectQuery;
    if (!parameter.empty() && !value.empty())
        selectQuery = "SELECT * FROM " + table + " WHERE " + parameter + " = " + value;

    else
        selectQuery = "SELECT * FROM " + table;
    exit = sqlite3_exec(dbPointer, selectQuery.c_str(), appendToVector, vectorPointer, NULL);
    if (exit != SQLITE_OK)
    {
        std::cerr << "SELECT FAILED\n";
    }
    sqlite3_close(dbPointer);
    return vector;
}


static int upTheCounter(void* ptr, int count, char** data, char** columns)
{
    unsigned int* counterPointer = static_cast<unsigned int*>(ptr);
    *counterPointer = *counterPointer + 1;

    return 0;
}

bool db::hasClockedInToday(const char* path, sqlite3* dbPointer, const std::string& tagID, const std::string& date)
{
    /*
    Function checks if employee has already clocked in today
    */
    unsigned int counter = 0;
    unsigned int* counterPointer = &counter;

    int exit = sqlite3_open(path, &dbPointer);
    std::string selectQuery = "SELECT * FROM CLOCK WHERE TAGID = " + tagID + " AND DATE = " + date;

    exit = sqlite3_exec(dbPointer, selectQuery.c_str(), upTheCounter, counterPointer, NULL);
    if (exit != SQLITE_OK)
    {
        std::cerr << "SELECT FAILED\n";
        sqlite3_close(dbPointer);
    }

    sqlite3_close(dbPointer);
    if (*counterPointer > 0)
        return true;
    return false;

}

