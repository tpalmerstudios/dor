#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <regex>
#include "Person.h"

Person toPerson (std::string);
int outPeron (Person);
int savePerson (Person toSave, std::string filename)
{
		// Variable declarations
		std::stringstream cStream;
		std::regex regexCID;
		std::string buffer, saveString, tempCurrent;
		std::fstream dataFile;
		int currentID, ending, nextLine, cursor, i, j;
		char character;

		// Set up stringstreams with 000000 then add in the ids
		currentID = toSave.getID ();
		cStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << currentID;

		// Create a string that contains the Person data
		saveString = "#[" + cStream.str () + "]" + toSave.getFName ();
		saveString += ";" + toSave.getMName () + ";" + toSave.getLName () + ";\n";

		// ID codes e.g. #[XXXXXX]
		tempCurrent = (R"(#\[)") + (cStream.str ()) + (R"(\])");
		regexCID.assign (tempCurrent);

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
		ending = cursor = 0;
		while (dataFile >> character)
				ending ++;

		// If the file is way too short
		if (ending < 9)
		{
				dataFile.clear ();
				dataFile.seekp (0, std::ios::beg);
				dataFile << saveString;
				dataFile.close ();
				return 0;
		}

		dataFile.clear ();
		dataFile.seekg (0, std::ios::beg);
		// If the ID is found in the file
		while (std::getline (dataFile, buffer))
		{
				nextLine = dataFile.tellp ();
				nextLine --;
				if (std::regex_search (buffer, regexCID))
				{
						dataFile.clear ();
						dataFile.seekp (cursor);
						std::vector<std::string> fileLine {""};
						for (i = 0; std::getline (dataFile, fileLine[i]); i++)
						{
								fileLine.push_back ("");
						}
						dataFile.clear ();
						dataFile.seekp (cursor);
						dataFile << saveString;
						for (j = 0; j > i; j++)
						{
								dataFile << fileLine [j];
						}
						fileLine.erase (fileLine.begin (), fileLine.end ());
						dataFile.close ();
						return 0;
				}
				cursor = dataFile.tellp ();
		}
		// Go to the end of the file and add data there
		dataFile.clear ();
		dataFile.seekp (0, std::ios::end);
		dataFile << saveString;
		dataFile.close ();
		return 0;
}

