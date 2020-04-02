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
std::string filename = "logfile.txt";

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
		std::cout << chosen.getID () << "\n";

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
		std::fstream dataFile;
		std::stringstream cStream;
		std::stringstream nStream;
		std::regex regexCID;
		std::regex regexNID;
		std::string buffer (10, '\0');
		std::string saveString;
		float currentID, nextID;
		float position, length;
		int cursor;

		currentID = toSave.getID ();
		nextID = currentID + 1;
		cStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << currentID;
		nStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << nextID;
		currentID = nextID = 0;

		// Create a string that contains the Person data
		saveString = "#[" + cStream.str () + "]" + toSave.getFName ();
		saveString = saveString + ";" + toSave.getMName () + ";" + toSave.getLName () + ";\n";

		// Temporary Strings that are RegEx for the first and second
		// ID codes e.g. #[XXXXXX]
		std::string tempCurrent = (R"(#\[)");
		std::string tempNext = (R"(#\[)");
		tempCurrent += (cStream.str ());
		tempNext += (nStream.str ());
		tempCurrent += (R"(\])");
		tempNext += (R"(\])");
		regexCID.assign (tempCurrent);
		regexNID.assign (tempNext);

		dataFile.open (filename, std::ios::binary | std::ios::in | std::ios::out);
		for (cursor = 0; cursor < dataFile.end; cursor ++)
		{
				std::cout << cursor << " ";
				dataFile.seekg (cursor);
				dataFile.read (&buffer[0], 10);
				if (std::regex_search (buffer, regexCID))
				{
						currentID = cursor;
						for (; cursor < dataFile.end; cursor ++)
						{
								std::cout << cursor << " ";
								dataFile.seekg (cursor);
								dataFile.read (&buffer[0], 10);
								if (std::regex_search (buffer, regexNID))
								{				
										length = cursor - currentID;
										cursor = dataFile.end;
								}
						}
				}
				else
				{
						cursor = dataFile.end;
						dataFile.seekg (dataFile.end - 1);
						dataFile << saveString << "\n";
				}
		}
		std::cout << "Stream: " << cStream.str () << "\nComplete String: " << saveString << "\n";
		std::cout << cursor << " - Cursor\nLength - " << length << "\n";

		return 0;
}

