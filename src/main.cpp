#include <iostream>			// Input output
#include <string>
#include <fstream>
#include <iomanip>			// More complex I/O
#include <sstream>			// For precision
#include <regex>			// Search specific strings
#include "Person.h" 		// Person class

// Function Declarations
int newPerson ();
int editPerson (std::string);
int deletePerson (int);
int savePerson (Person, std::string);
int callsSet ();
Person searchPerson (std::string);				// Returns a person after searching through file and allowing selection
Person toPerson (std::string);					// Makes a person from a saveString
int IDtoPerson (int);								// Makes a person from ID #
int outPerson (Person);							// Displays a person from a class Person	
Person selectPerson ();

int main ()
{
		char input;
		while (1)
		{
				// Menu Output
				std::cout << "Main Menu\n\n";
				std::cout << "1) New Person\n";
				std::cout << "2) Edit Person\n";
				std::cout << "3) View Person\n";
				std::cout << "4) Search Person\n";
				std::cout << "5) Delete Person\n";
				std::cin >> input;
				switch (input)
				{
						case '1':
								newPerson ();
								break;
						case '2':
								editPerson (".logfile.txt");
								break;
						case '3':
								break;
						case '4':
								break;
						case '5':
								break;
						default:
								return 0;
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

int IDtoPerson (int openID)
{
		Person human;
		std::string buffer, tempReg;
		std::string filename = ".logfile.txt";
		std::regex regID;
		std::stringstream idStream;
		std::ifstream dataFile;

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
		dataFile.close ();

		human = toPerson (buffer);
		return 0;
}

int editPerson (std::string filename)
{
		Person human = selectPerson ();
		std::string fName, mName, lName;
		std::cout << "Edit a Person\n" << std::endl;
		std::cout << "First Name: " << human.getFName ();
		std::cout << "\nNew First Name: ";
		std::cin >> fName;
		std::cout << "Middle Name: " << human.getMName ();
		std::cout << "\nNew Middle Name: ";
		std::cin >> mName;
		std::cout << "Last Name: " << human.getLName ();
		std::cout << "\nNew Last Name: ";
		std::cin >> lName;
		if (fName != "-")
				human.setFName (fName);
		if (mName != "-")
				human.setMName (mName);
		if (lName != "-")
				human.setLName (lName);
		return savePerson (human, filename);
}

int deletePerson (int deleteID)
{
		// open file
		// find id in file
		// find next id as ending point
		// delete all between those cursors
		return 0;
}

