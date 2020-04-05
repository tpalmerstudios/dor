#include "Person.h"

int outPerson (Person outPerson)
{
		std::cout << "ID:			" << outPerson.getID () << std::endl;
		std::cout << "First Name:	" << outPerson.getFName () << std::endl;
		std::cout << "Middle Name:	" << outPerson.getMName () << std::endl;
		std::cout << "Last Name:	" << outPerson.getLName () << std::endl;
		return 0;
}

