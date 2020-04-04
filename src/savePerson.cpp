#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <regex>
#include "Person.h"

int savePerson (Person toSave, std::string filename)
{
		// Variable declarations
		std::stringstream cStream, nStream;
		std::regex regexCID, regexNID;
		std::string buffer;
		std::string saveString;
		std::fstream dataFile;
		int currentID, nextID, ending;
		int cursor;
		char character;

		// Set up stringstreams with 000000 then add in the ids
		currentID = toSave.getID ();
		std::cout << currentID;
		nextID = currentID + 1;
		cStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << currentID;
		nStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << nextID;

		// Create a string that contains the Person data
		saveString = "#[" + cStream.str () + "]" + toSave.getFName ();
		saveString += ";" + toSave.getMName () + ";" + toSave.getLName () + ";\n";

		std::cout << saveString << "Is the issue here?\n";
		// Temporary Strings that are RegEx for the first and second
		// ID codes e.g. #[XXXXXX]
		std::string tempCurrent = (R"(#\[)") + (cStream.str ()) + (R"(\])");
		std::string tempNext = (R"(#\[)") + (nStream.str ()) + (R"(\])");
		regexCID.assign (tempCurrent);
		regexNID.assign (tempNext);

		// Open a file in binary mode. Input and output
		dataFile.open (filename, std::ios::in);
		if (dataFile.fail ())
		{
				dataFile.open (filename, std::ios::out );
				if (dataFile.fail ())
				{
						std::cerr << filename << "could not be opened.\n";
						return 1;
				}
		}
		dataFile.close ();
		dataFile.open (filename, std::ios::out | std::ios::binary | std::ios::in );
		if (dataFile.fail ())
		{
				std::cerr << filename << "could not be opened.\n";
				return 1;
		}
		ending = 0;
		while (dataFile >> character)
				ending ++;
		if (ending < 9)
		{
				dataFile.clear ();
				dataFile.seekp (0, std::ios::beg);
				dataFile << saveString;
				dataFile.close ();
				return 0;
		}
		while (std::getline (dataFile, buffer))
		{
				cursor = dataFile.tellp ();
				if (std::regex_search (buffer, regexCID))
				{
						dataFile.clear ();
						dataFile.seekp (cursor);
						dataFile << saveString;
						dataFile.close ();
						return 0;
				}
		}
		dataFile.clear ();
		dataFile.seekp (0, std::ios::end);
		dataFile << saveString;
		dataFile.close ();
		return 0;
}

