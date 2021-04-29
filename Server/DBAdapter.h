#pragma once

#include "database.hpp"

#include "sqlite3.h"
#include <ctime>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <iostream>

class DBAdapter
{
public:
	DBAdapter(const char* _dataBasePath);
	~DBAdapter();

private:
	sqlite3* dataBasePtr;
	const char* dataBasePath;

public:
	// Proccess
	std::vector<std::string> processMsgFromServer(std::string rawMessage);
	void createDataBase();
private:
	// Prepare Data
	std::vector<std::string> splitData(std::string data);
	std::vector<std::string> splitMessage(std::string message);

	// Read Data
	std::vector<std::string> getAllEmployees();
	std::vector<std::string> getEmployeeClock(std::string tagID);


	// Write Data
	void clockIn(std::string tagID);
	std::vector<std::string> registerEmployee(std::string tagID, std::string name, std::string lastName);
	std::vector<std::string> deleteEmployee(std::string tagID);

	// Helpers
	std::string getCurrentDate();
	std::string getCurrentTime();

	// Intialize
	void connectToDatabase();
};

