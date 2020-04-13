#include <string>
#include "Person.h"
#include "dorSettings.h"
#include "Terminal.h"

int savePerson (Person, dorSettings);

int newPerson (dorSettings dor)
{
		Person human;
		Terminal out;
		std::string fName, mName, lName;

		if (dor.getBasicMode ())
		{
				std::cout << "First Name: ";
				std::cin >> fName;
				std::cout << "Middle Name: ";
				std::cin >> mName;
				std::cout << "Last Name: ";
				std::cin >> lName;
		}
		else
		{
				std::cout << out.color (dor.getFG (), dor.getBG ()) << out.clearscr () <<  "DOR - DATA ORGANIZER\n\n";
				std::cout << out.color (dor.getHiFG (), dor.getHiBG ()) + "First Name:                        \n";
				std::cout << out.color (dor.getFG (), dor.getBG ()) + "Middle Name:\nLast Name:";
				std::cout << out.goLoc (3, 13) + out.color (dor.getHiFG (), dor.getHiBG ());
				std::cin >> fName;
				std::cout << out.color (dor.getFG (), dor.getBG ()) << out.clearscr () <<  "DOR - DATA ORGANIZER\n\n";
				std::cout << "First Name: " << fName << "\n" <<  out.color (dor.getHiFG (), dor.getHiBG ());
				std::cout << "Middle Name:                       \n" << out.color (dor.getFG (), dor.getBG ());
				std::cout << "Last Name:" << out.goLoc (4, 14) << out.color (dor.getHiFG (), dor.getHiBG ());
				std::cin >> mName;
				std::cout << out.color (dor.getFG (), dor.getBG ()) << out.clearscr () <<  "DOR - DATA ORGANIZER\n\n";
				std::cout << "First Name: " << fName << "\nMiddle Name: " << mName << "\n";
				std::cout << out.color (dor.getHiFG (), dor.getHiBG ()) << "Last Name:                         \n";
				std::cout << out.goLoc (5, 12);
				std::cin >> lName;
		}
		human.setID (dor.getFilename ());
		human.setFName (fName);
		human.setMName (mName);
		human.setLName (lName);

		savePerson (human, dor);
		return 0;
}
