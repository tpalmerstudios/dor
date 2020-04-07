#include "Person.h"

int savePerson (Person, std::string);

// int newPerson () outputs promtsfor a user to enter details of a Person and places input into a file. It return 0 on success and -1 on failure
int newPerson ()
{
		Person chosen;
		std::string fName;
		std::string mName;
		std::string lName;
		std::string filename = ".logfile.txt";
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

		std::cout << "Saving...\n";
		savePerson (chosen, filename);
		return 0;
}
