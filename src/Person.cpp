#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <algorithm>
#include "Person.h"

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
void Person::setID (int searchID)
{
		id = searchID;
}

void Person::setID (std::string file)
{
		std::string buffer (10,'\0');
		std::string filename = ".logfile.txt";
		std::regex idReg (R"(#\[[0-9]{6}\])");
		std::ifstream dataFile;
		int position;

		dataFile.open (file, std::ios::ate | std::ios::binary | std::ios::in);
		if (!dataFile)
		{
				id = 0;
				return;
		}
		dataFile.seekg (0, dataFile.end);
		int ending = dataFile.tellg ();
		if (ending <= 9)
		{
				id = 0;
				dataFile.close ();
				return;
		}
		position = ending - 10;
		while (!std::regex_search (buffer, idReg) && position >= 0)
		{
				dataFile.seekg (position);
				dataFile.read (&buffer[0], 10);
				position -= 1;
		}
		dataFile.close ();
		id = std::stoi (buffer.substr (2, 6 )) + 1;
}
void Person::toPerson (std::string saveString)
{
		std::size_t tempLoc, delimLoc;
		id = stoi (saveString.substr (2,6));

		delimLoc = saveString.find (";");
		if (delimLoc == std::string::npos)
				return;
		fName = saveString.substr (9, (delimLoc - 9));

		tempLoc = delimLoc + 1;
		delimLoc = saveString.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return;
		mName = saveString.substr (tempLoc, (delimLoc - tempLoc));

		tempLoc = delimLoc + 1;
		delimLoc = saveString.find (";", tempLoc);
		if (delimLoc == std::string::npos)
				return;
		lName = saveString.substr (tempLoc, (delimLoc - tempLoc));
}

void Person::outPerson ()
{
		std::cout << "ID:			" << id << std::endl;
		std::cout << "First Name:	" << fName << std::endl;
		std::cout << "Middle Name:	" << mName << std::endl;
		std::cout << "Last Name:	" << lName << std::endl;
}

