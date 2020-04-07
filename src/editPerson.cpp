#include "Person.h"

int savePerson (Person, std::string);
Person selectPerson ();
bool nameValid (std::string);

// int editPerson (std::string filename) take a valid accessable filename and selects a piece
// of data via selectPerson () and uses the returned Person to show the current data
// in it and shows a prompt for a user to change the data. Finally it loads savePerson () with that data
// and returns a 0 upon success or -1 on failure
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
		if (fName != "-" && nameValid (fName))
				human.setFName (fName);
		std::cout << "Middle Name: " << human.getMName () << std::endl;
		std::cout << "New Middle Name: ";
		std::cin >> mName;
		if (mName != "-" && nameValid (mName))
				human.setMName (mName);
		std::cout << "Last Name: " << human.getLName () << std::endl;
		std::cout << "New Last Name: ";
		std::cin >> lName;
		if (lName != "-" && nameValid (lName))
				human.setLName (lName);

		// Save in file
		savePerson (human, filename);
		return 0;
}
