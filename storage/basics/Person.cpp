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
		std::string buffer (10,'\0');
		std::ifstream dataFile;
		std::regex idReg (R"(#\[[0-9]{6}\])");
		int position;

		dataFile.open (filename, std::ios::ate | std::ios::binary);
		position = dataFile.tellg ();
		position -= 10;
		dataFile.seekg (position);
		dataFile.read (&buffer[0], 10);
		std::cout << "\nPosition: " << position << "\n";

		while ((!std::regex_search (buffer, idReg) && position >= 0))
		{
				std::cout << "\nPosition: " << position << "\n";
				position -= 1;
				dataFile.seekg (position);
				dataFile.read (&buffer[0], 10);
				if (position == 0)
						buffer = "#[000000]";
		}
		dataFile.close ();
		id = std::stof (buffer.substr (2, 6 )) + 1;
}
