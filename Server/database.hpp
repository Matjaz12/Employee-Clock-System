#pragma once

#include "sqlite3.h"
#include "vector"
#include "iostream"

namespace db
{
	// Setup
	void openDataBase(const char* path, sqlite3* dbPointer);
	void createEmployeeTable(const char* path, sqlite3* dbPointer);
	void createClockTable(const char* path, sqlite3* dbPointer);

	// Write
	void insert(const char* path, sqlite3* dbPointer, const std::string& table, const std::vector<std::string>& parameters);
	void deleteInstance(const char* path, sqlite3* dbPointer, const std::string& table, const std::string& primaryKey, const std::string& value);
	void updateClockOut(const char* path, sqlite3* dbPointer, const std::string& tagID, const std::string& date, const std::string& updateCol, const std::string& newValue);

	// Read
	std::vector<std::string> getInstances(const char* path, sqlite3* dbPointer, const std::string& table, const std::string& parameter = "", const std::string& value = "");
	bool hasClockedInToday(const char* path, sqlite3* dbPointer, const std::string& tagID, const std::string& date);
}

