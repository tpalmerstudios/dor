#include "Person.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

void Person::setFName (std::string name)
{
		fName = name;
}
void Person::setMName (std::string name)
{
		mName = name;
}
void Person::setLName (std::string name)
{
		lName = name;
}
void Person::setID (std::string filename)
{
		std::cout << "In setID\n";
		float fileID;
		std::string buffer (9, '\0');
		std::string sID;
		int position;
		char current;
		std::cout << "In setID";
		std::ifstream dataFile;
		std::cout << "In setID";
		std::regex idReg ("#\[[0-9]{6}\]");

		dataFile.open (filename, std::ios::ate | std::ios::binary);
		position = dataFile.tellg ();
		position -= 9;
		while (!regex_match (sID, idReg))
		{
				dataFile.seekg (position);
				dataFile.read (&buffer[0], 9);
				position -= 10;
		}
		dataFile.close ();
		id = std::stoi (sID.substr (2, 6));
}
float Person::getID () const
{
		return id;
}

