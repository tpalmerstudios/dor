#include <iostream>			// Input output
#include <string>
#include <fstream>
#include <iomanip>			// More complex I/O
#include <sstream>			// For precision
#include <regex>			// Search specific strings
#include "Person.h" 		// Person class

// Function Declarations
int deletePerson (std::string);
int savePerson (Person, std::string);
int editPerson (std::string);
int outPerson (Person);							// Displays a person from a class Person	
int newPerson ();
int callsSet ();
Person searchPerson (std::string);				// Returns a person after searching through file and allowing selection
Person toPerson (std::string);					// Makes a person from a saveString
Person IDtoPerson (int);								// Makes a person from ID #
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
				std::cout << "4) Delete Person\n";
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
								outPerson (selectPerson ());
								break;
						case '4':
								deletePerson (".logfile.txt");
								break;
						default:
								return 0;
				}
		}
		return 0;
}

Person IDtoPerson (int openID)
{
		Person human;
		std::string buffer, tempReg;
		std::string filename = ".logfile.txt";
		std::regex regID;
		std::stringstream idStream;
		std::ifstream dataFile;
		bool found = false;

		dataFile.open (filename, std::ios::binary);
		if (dataFile.fail ())
		{
				std::cerr << filename << " could not be opened!\n";
				return human;
		}

		// Create a stringstream to hold ID
		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << openID;
		tempReg = (R"(#\[)") + idStream.str () + (R"(\])");
		regID.assign (tempReg);
		while (!found && std::getline (dataFile, buffer))
		{
				if (std::regex_search (buffer, regID))
				{
						found = true;
				}
		}
		dataFile.close ();

		if (found)
		{
				human = toPerson (buffer);
		}
		return human;
}

