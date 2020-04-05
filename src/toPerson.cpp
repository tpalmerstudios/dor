#include <string>
#include "Person.h"

Person toPerson (std::string saveString)
{
		Person inputPerson;
		std::string fName, mName, lName;
		int id;
		std::size_t tempLoc, delimLoc;
		
		id = stoi (saveString.substr (2,6));
		inputPerson.setID (id);

		delimLoc = saveString.find (";");
		if (delimLoc == std::string::npos)
				return inputPerson;
		fName = saveString.substr (9, (delimLoc - 9));
		inputPerson.setFName (fName);

		tempLoc = delimLoc + 1;
		delimLoc = saveString.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return inputPerson;
		mName = saveString.substr (tempLoc, (delimLoc - tempLoc));
		inputPerson.setMName (mName);

		tempLoc = delimLoc + 1;
		delimLoc = saveString.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return inputPerson;
		lName = saveString.substr (tempLoc, (delimLoc - tempLoc));
		inputPerson.setLName (lName);

		return inputPerson;
}
