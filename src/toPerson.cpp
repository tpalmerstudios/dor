#include <algorithm>
#include <string>
#include "Person.h"

int outPerson (Person);
Person toPerson (std::string saveString)
{
		Person human;
		std::string fName, mName, lName;
		int id;
		std::size_t tempLoc, delimLoc;
		// Great little snippet from stack overflow to test if all digits are numeric
		// Save this gem! https://stackoverflow.com/a/33532715
		//if (!std::all_of (saveString.begin (), saveString.end (), [](unsigned char c) {return std::isdigit(c);}))
		//{
		//		return human;
		//}
		id = stoi (saveString.substr (2,6));
		human.setID (id);

		delimLoc = saveString.find (";");
		if (delimLoc == std::string::npos)
				return human;
		fName = saveString.substr (9, (delimLoc - 9));
		human.setFName (fName);

		tempLoc = delimLoc + 1;
		delimLoc = saveString.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return human;
		mName = saveString.substr (tempLoc, (delimLoc - tempLoc));
		human.setMName (mName);

		tempLoc = delimLoc + 1;
		delimLoc = saveString.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return human;
		lName = saveString.substr (tempLoc, (delimLoc - tempLoc));
		human.setLName (lName);

		return human;
}
