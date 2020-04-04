#include <iostream>			// Input output
#include <string>
#include <fstream>
#include <iomanip>			// More complex I/O
#include <sstream>			// For precision
#include <regex>			// Search specific strings
#include "Person.h" 		// Person class

// Function Declarations
int newPerson ();
int openPerson (int);
int editPerson (Person, std::string);
int deletePerson (int);
int savePerson (Person, std::string);
int callsSet ();

int main ()
{
		char input;
		std::string searchID = "0";
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
						case '2':
								openPerson (0);
								break;
						case '4':
								std::cin >> searchID;
								openPerson (stoi (searchID));
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

int openPerson (int openID)
{
		Person search;
		std::string buffer, tempReg, fName, mName, lName;
		std::string filename = ".logfile.txt";
		std::regex regID;
		std::stringstream idStream;
		std::ifstream dataFile;
		std::size_t delimLoc, tempLoc;

		// Make a regex to find the id entered
		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << openID;
		tempReg = (R"(#\[)") + idStream.str () + (R"(\])");
		regID.assign (tempReg);
		dataFile.open (filename, std::ios::binary);
		if (dataFile.fail ())
		{
				std::cerr << filename << " could not be opened!\n";
				return 1;
		}
		while (std::getline (dataFile, buffer) && !std::regex_search (buffer, regID))
				search.setID (openID);

		// Get location of first ;
		// set fName to 9 (character after ] in ID string)
		// and cut the string to the ;
		delimLoc = buffer.find (";");
		if (delimLoc == std::string::npos)
				return 2;
		fName = buffer.substr (9, (delimLoc - 9));
		search.setFName (fName);

		// Temporary store previous ;
		// fine next ;
		// cut between the two
		tempLoc = delimLoc + 1;
		delimLoc = buffer.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return 2;
		mName = buffer.substr (tempLoc, (delimLoc - tempLoc));
		search.setMName (mName);
		
		// Temporary store previous ;
		// fine next ;
		// cut between the two
		tempLoc = delimLoc + 1;
		delimLoc = buffer.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return 2;
		lName = buffer.substr (tempLoc, (delimLoc - tempLoc));
		search.setLName (lName);
		dataFile.close ();
		return editPerson (search, filename);
}

int editPerson (Person chosen, std::string filename)
{
		std::string fName, mName, lName;
		std::cout << "Edit a Person\n" << std::endl;
		std::cout << "First Name: " << chosen.getFName ();
		std::cout << "\nNew First Name: ";
		std::cin >> fName;
		std::cout << "Middle Name: " << chosen.getMName ();
		std::cout << "\nNew Middle Name: ";
		std::cin >> mName;
		std::cout << "Last Name: " << chosen.getLName ();
		std::cout << "\nNew Last Name: ";
		std::cin >> lName;
		if (fName != "-")
				chosen.setFName (fName);
		if (mName != "-")
				chosen.setMName (mName);
		if (lName != "-")
				chosen.setLName (lName);
		return savePerson (chosen, filename);
}

int deletePerson (int deleteID)
{
		// open file
		// find id in file
		// find next id as ending point
		// delete all between those cursors
		return 0;
}

