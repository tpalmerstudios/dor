#include <iostream>			// Input output
#include <iomanip>			// More complex I/O
#include <sstream>			// For precision
#include <string>			// For normal c++ strings
#include <regex>			// Search specific strings
#include <fstream>			// Access files
#include "Person.h" 		// Person class

// Function Declarations
int newPerson ();
int openPerson (int);
int editPerson (Person, int);
int deletePerson (int);
int savePerson (Person);
int callsSet ();

// Global Variables
std::string filename = ".logfile.txt";

int main ()
{
		char input;
		while (1)
		{
				// Menu Output
				std::cout << "Main Menu\n\n";
				std::cout << "1) New Person\n";
				std::cout << "2) View Person\n";
				std::cout << "3) Delete Person\n";
				std::cout << "4) Search Person\n";
				std::cin >> input;
				switch (input)
				{
						case '1':
								newPerson ();
								break;
						// Exits Program on any other response
						//default:
						//		return 0;
				}
		}
		return 0;
}
int newPerson ()
{
		Person chosen;
		// Temporary strings
		std::string fName;
		std::string mName;
		std::string lName;
		chosen.setID (filename);

		// Get data from user and put it in class
		std::cout << "First Name: ";
		std::cin >> fName;
		chosen.setFName (fName);
		std::cout << "Middle Name: ";
		std::cin >> mName;
		chosen.setMName (mName);
		std::cout << "Last Name: ";
		std::cin >> lName;
		chosen.setLName (lName);

		// Save in file
		std::cout << "Saving...\n";
		bool failure = savePerson (chosen);
		return !failure;
}

int openPerson (int openID)
{
		Person search;
		int cursor= 0;
		// Look through file
		// retrieve data
		// place in class
		bool failure = editPerson (search, cursor);
		return !failure;
}

int editPerson (Person chosen, int cursor)
{
		// Load a piece of data
		// Get input to change or skip
		// Remove all from start of this data to start of next
		//Place cursor in file correctly
		// Save entire Person to file at once
		bool failure = savePerson (chosen);
		return !failure;
}

int deletePerson (int deleteID)
{
		// open file
		// find id in file
		// find next id as ending point
		// delete all between those cursors
		return 0;
}

int savePerson (Person toSave)
{
		// Variable declarations
		std::fstream dataFile;
		std::stringstream cStream, nStream;
		std::regex regexCID, regexNID;
		std::string buffer (10, '\0');
		std::string saveString;
		float currentID, nextID, position, length;
		int cursor;

		// Set up stringstreams with 000000 then add in the ids
		// This works! Don't fuck with it
		currentID = toSave.getID ();
		nextID = currentID + 1;
		cStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << currentID;
		nStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << nextID;

		// Create a string that contains the Person data
		// This works! Don't fuck with it
		saveString = "#[" + cStream.str () + "]" + toSave.getFName ();
		saveString += ";" + toSave.getMName () + ";" + toSave.getLName () + ";\n";

		// Temporary Strings that are RegEx for the first and second
		// ID codes e.g. #[XXXXXX]
		// These Work! Don't fuck with it
		std::string tempCurrent = (R"(#\[)") + (cStream.str ()) + (R"(\])");
		std::string tempNext = (R"(#\[)") + (nStream.str ()) + (R"(\])");
		regexCID.assign (tempCurrent);
		regexNID.assign (tempNext);

		// Open a file in binary mode. Input and output
		dataFile.open ("logfile.txt", std::ios::binary);
		if (!dataFile)
		{
				std::cerr << "logfile.txt" << " could not be opened.\n";
				return 1;
		}

		// If the file is too short, write over it with new data
		if (dataFile.end < 9 )
		{
				dataFile.seekg (1);
				dataFile << saveString;
				dataFile.close ();
				std::cout << "Written via < 9 test\n";
				return 0;
		}

		for (cursor = 0; cursor < dataFile.end; cursor ++)
		{
				dataFile.seekg (cursor);
				dataFile.read (&buffer[0], 10);
				if (std::regex_search (buffer, regexCID))
				{
						position = cursor;
						for (; cursor < dataFile.end; cursor ++)
						{
								dataFile.seekg (cursor);
								dataFile.read (&buffer[0], 10);
								if (std::regex_search (buffer, regexNID))
								{				
										length = cursor - position;
										cursor = dataFile.end;
								}
						}
				}
				else
				{
						cursor = dataFile.end;
						dataFile.seekg (cursor);
						dataFile << saveString << "\n";
						std::cout << "Written via no regex_search ()\n";
				}
		}
		return 0;
}

