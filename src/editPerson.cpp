#include "Person.h"

int savePerson (Person, std::string);
Person selectPerson ();

int editPerson (std::string filename)
{
		Person human = selectPerson ();
		std::string fName;
		std::string mName;
		std::string lName;

		// Get data from user and put it in class
		std::cout << "First Name: " << human.getFName () << std::endl;
		std::cout << "New First Name: ";
		std::cin >> fName;
		if (fName != "-")
				human.setFName (fName);
		std::cout << "Middle Name: " << human.getMName () << std::endl;
		std::cout << "New Middle Name: ";
		std::cin >> mName;
		if (mName != "-")
				human.setMName (mName);
		std::cout << "Last Name: " << human.getLName () << std::endl;
		std::cout << "New Last Name: ";
		std::cin >> lName;
		if (lName != "-")
				human.setLName (lName);

		// Save in file
		savePerson (human, filename);
		return 0;
}
