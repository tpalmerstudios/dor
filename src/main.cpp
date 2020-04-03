#include <iostream>			// Input output
#include <string>
#include <fstream>
#include <iomanip>			// More complex I/O
#include <sstream>			// For precision
#include <regex>			// Search specific strings
#include "Person.h" 		// Person class

// Function Declarations
int newPerson ();
int openPerson (float);
int editPerson (Person, std::string);
int deletePerson (int);
int savePerson (Person, std::string);
int callsSet ();

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
		std::string filename = ".logfile.txt";
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
		bool failure = savePerson (chosen, filename);
		return !failure;
}

int openPerson (float openID)
{
		Person search;
		std::string buffer, tempReg;
		std::string filename = ".logfile.txt";
		std::regex regID;
		std::stringstream idStream;
		std::ifstream dataFile;

		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << openID;
		tempReg = (R"(#\[)") + (idStream.str ()) + (R"(\])");
		regID.assign (tempReg);
		dataFile.open (filename, std::ios::in | std::ios::binary);
		while (std::getline (dataFile, buffer) && !std::regex_search (buffer, regID))
		{
				//
		}

		// Look through file
		// retrieve data
		// place in class
		return editPerson (search, filename);
}

int editPerson (Person chosen, std::string filename)
{
		// Load a piece of data
		// Get input to change or skip
		// Remove all from start of this data to start of next
		//Place cursor in file correctly
		// Save entire Person to file at once
		bool failure = savePerson (chosen, filename);
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

