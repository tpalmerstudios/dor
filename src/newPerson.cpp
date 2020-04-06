#include "Person.h"

int savePerson (Person, std::string);

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
