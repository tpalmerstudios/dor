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
int newPerson ();
int callsSet ();
Person searchPerson (std::string);				// Returns a person after searching through file and allowing selection
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
								selectPerson ().outPerson ();
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

