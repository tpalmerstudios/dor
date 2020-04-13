#include "Person.h"
#include "Terminal.h"
#include "dorSettings.h"
#include <regex>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

Person IDtoPerson (int openID, dorSettings dor, Terminal out)
{
		Person human;
		std::string buffer, tempReg;
		std::regex regID;
		std::stringstream idStream;
		std::ifstream dataFile;
		bool found = false;

		dataFile.open (dor.getFilename (), std::ios::binary);
		if (dataFile.fail ())
				return human;

		// Create a stringstream to hold ID
		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << openID;
		tempReg = (R"(#\[)") + idStream.str () + (R"(\])");
		regID.assign (tempReg);
		while (!found && std::getline (dataFile, buffer))
		{
				if (std::regex_search (buffer, regID))
						found = true;
		}
		dataFile.close ();

		if (found)
				human.toPerson (buffer);
		else
		{}
		return human;
}


