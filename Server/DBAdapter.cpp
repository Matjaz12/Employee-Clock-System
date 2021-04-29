#include "DBAdapter.h"

DBAdapter::DBAdapter(const char* _dataBasePath)
    :
    dataBasePath{ _dataBasePath }
{
    connectToDatabase();
}

DBAdapter::~DBAdapter()
{

}

// Intialize

void DBAdapter::connectToDatabase()
{
	db::openDataBase(dataBasePath, dataBasePtr);
}

void DBAdapter::createDataBase()
{
	db::openDataBase(dataBasePath, dataBasePtr);
	db::createEmployeeTable(dataBasePath, dataBasePtr);
	db::createClockTable(dataBasePath, dataBasePtr);
}

std::vector<std::string> DBAdapter::processMsgFromServer(std::string rawMessage)
{
	/*
	Function receives raw Massage from a server, it splits a Message in two parts: Action and Data part.
	It tries to match a Procedure defined in the Database with provided Action Message,
	Action message can be of two types: Write or Read Action.
		If Action is Write Action (either register employee or delete employe ), the function calls a procedure to update the
		database and returns an empty vector.
		If Action is Read Action ,the function calls a procedure that returns data from the database and returns the data in vector form
	*/
	std::vector<std::string> vector = splitMessage(rawMessage);
	if (vector.size() < 1)
	{
		return vector;
	}
	std::string action = vector[0];
	std::string data = vector[1];

	if (action == "CLOCKIN")
	{
		clockIn(data);
	}
	else if (action == "REGISTER")
	{
		std::vector<std::string> parameters = splitData(data);
		std::string tagID = parameters[0];
		std::string name = parameters[1];
		std::string lastName = parameters[2];

		return registerEmployee(tagID, name, lastName);
	}
	else if (action == "DELETE")
	{
		return deleteEmployee(data);
	}
	else if (action == "GETALL")
	{
		return getAllEmployees();
	}
	else if (action == "GETCLOCK")
	{
		//std::cout << "Sending back: " << getEmployeeClock(data)[0] << "\n";
		return getEmployeeClock(data);
	}
}



// Prepare Data

std::vector<std::string> DBAdapter::splitData(std::string data)
{
	/*
	Function receives data separated by comma, it splits the data and returns a vector of it
		Example in: "tagID, name, lastName"
		Example out: [tagID,name,lastName]
	*/
	std::vector<std::string> vector;

	std::string subString = "";
	for (unsigned int i{ 0 }; i < data.length(); i++)
	{
		if (data[i] == ' ') // ignore spaces
			continue;
		else if (data[i] != ',')
		{
			subString += data[i];
		}
		else
		{
			vector.push_back(subString); // push subString without spaces
			subString = "";
		}
	}
	vector.push_back(subString);
	return vector;
}

std::vector<std::string> DBAdapter::splitMessage(std::string message)
{
	/*
	Function splits message into action and data message
	it expects message in form:
	ACTION[DATA1,DATA2,...,DATAN]
	*/
	std::vector<std::string> vector;
	std::string::size_type position = message.find('[');
	if (position != std::string::npos)
	{
		vector.push_back(message.substr(0, position));
		vector.push_back(message.substr(position + 1, message.length() - position - 2));
	}
	return vector;
}

// Read Data

std::vector<std::string> DBAdapter::getAllEmployees()
{
	/*
	Function returns all instances in Emplyoee table in vector form
	*/
	return db::getInstances(dataBasePath, dataBasePtr, "EMPLOYEE");
}

std::vector<std::string> DBAdapter::getEmployeeClock(std::string tagID)
{
	/*
	Function returns all instances that match with provided tagID in Emplyoee table in vector form
	*/
	tagID = "'" + tagID + "'";
	return db::getInstances(dataBasePath, dataBasePtr, "CLOCK", "TAGID", tagID);
}

// Write Data

void DBAdapter::clockIn(std::string tagID)
{
	/*
	Function clocks in an Employee
	*/
	tagID = "'" + tagID + "'";
	std::string date = getCurrentDate();
	std::string timeIn = getCurrentTime();
	date = "'" + date + "'";
	timeIn = "'" + timeIn + "'";

	if (!db::hasClockedInToday(dataBasePath, dataBasePtr, tagID, date))
	{
		/*
		If Employee hasn't clocked in today yet, we insert a new clockIn instance to Database
		*/
		db::insert(dataBasePath, dataBasePtr, "CLOCK", { tagID, date , timeIn , "'NULL'" });
	}
	else
	{
		/*
		If employee has already logged in today -> employee is leaving so we save his clock Out
		*/
		std::cout << "Updating timeOut\n";
		std::string timeOut = getCurrentTime();
		timeOut = "'" + timeOut + "'";
		db::updateClockOut(dataBasePath, dataBasePtr, tagID, date, "TIMEOUT", timeOut);
	}
}

std::vector<std::string> DBAdapter::registerEmployee(std::string tagID, std::string name, std::string lastName)
{
	/*
	Function puts raw data in correct form and inserts a new instance to the database
	*/
	
	std::vector<std::string> feedBackVector;

	tagID = "'" + tagID + "'";
	name = "'" + name + "'";
	lastName = "'" + lastName + "'";
	db::insert(dataBasePath, dataBasePtr, "EMPLOYEE", { tagID , name , lastName });
	
	//	TODO: RETURNS EITHER OK OR ERROR!
	feedBackVector.push_back("[Succesfully Registered Employee]");

	return feedBackVector;
}

std::vector<std::string> DBAdapter::deleteEmployee(std::string tagID)
{
	std::vector<std::string> feedBackVector;

	tagID = "'" + tagID + "'";
	db::deleteInstance(dataBasePath, dataBasePtr, "EMPLOYEE", "TAGID", tagID);
	db::deleteInstance(dataBasePath, dataBasePtr, "CLOCK", "TAGID", tagID);

	//	TODO: RETURNS EITHER OK OR ERROR!
	feedBackVector.push_back("[Succesfully Deleted Employee]");

	return feedBackVector;
}

// Helpers

std::string DBAdapter::getCurrentDate()
{
	/*
	Function returns current date in string form
	*/
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);
	std::string str(buffer);
	return str;
}

std::string DBAdapter::getCurrentTime()
{
	/*
	Function returns current time in string form
	*/
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%H:%M:%S", timeinfo);
	std::string str(buffer);
	return str;
}

