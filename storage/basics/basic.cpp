#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "Person.h"

int newPerson ();
int openPerson (int);
int editPerson (Person, int);
int deletePerson (int);
int savePerson (Person);
int callsSet ();

std::string filename = "logfile.txt";

int main ()
{
		char input;
		while (1)
		{
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
				}
		}
		return 0;
}
int newPerson ()
{
		Person chosen;
		std::string fName;
		std::string mName;
		std::string lName;
		int cursor = 0;
		chosen.setID (filename);
		std::cout << "First Name: ";
		std::cin >> fName;
		chosen.setFName (fName);
		std::cout << "Middle Name: ";
		std::cin >> mName;
		chosen.setMName (mName);
		std::cout << "Last Name: ";
		std::cin >> lName;
		chosen.setLName (lName);
		// Place cursor at end
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
		std::string sID = std::to_string (toSave.getID ());
		sID = sID.substr (0, 6);
		int cursor;

		std::string regID = (R"(#\[)");
		regID.append (sID);
		regID.append (R"(\])");
		// std::regex currentID = regID;

		dataFile.open (filename, std::ios::binary);
		dataFile.seekg (cursor);
		dataFile << "#[" << toSave.getID () << "]" << toSave.getFName() 
				<< ";" << toSave.getMName() << ";" << toSave.getLName() << ";\n";

		return 0;
}

