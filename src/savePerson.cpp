#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Person.h"
#include "dorSettings.h"

Person toPerson (std::string);
int savePerson (Person human, dorSettings dor)
{
		if (human.getID () == -1)
				return -1;

		std::stringstream idStream;
		std::string buffer, saveString, idString;
		std::fstream dataFile;
		std::string test;
		int ending, nextLine, cursor, i, j =0;
		char character;

		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << human.getID ();
		idString = "#[" + idStream.str () + "]";
		saveString = idString + human.getFName () + ";" + human.getMName () + ";" + human.getLName () + ";\n";

		dataFile.open (dor.getFilename (), std::ios::in | std::ios::out | std::ios::binary);
		if (dataFile.fail ())
				return -1;

		while (dataFile >> character)
				ending ++;
		if (ending < 9)
		{
				dataFile << saveString;
				dataFile.close ();
				return 0;
		}
		dataFile.clear ();
		dataFile.seekp (0, std::ios::beg);
		while (std::getline (dataFile, buffer))
		{
				nextLine = dataFile.tellp ();
				nextLine --;
				if (buffer.find (idString) != std::string::npos)
				{
						// If the regex matches the current line. Go to the cursor (which is the end of the previous line)
						// fill a vector with lines after the found line. go to cursor at the end of previous line
						// write into the file from that point the entire vector. delete the vector and close the file
						dataFile.seekp (cursor);
						std::vector<std::string> fileLine {""};
						for (i = 0; std::getline (dataFile, fileLine[i]); i++)
								fileLine.push_back ("");
						dataFile.clear ();
						dataFile.seekp (cursor);
						dataFile << saveString;
						for (j = 0; j > i; j++)
								dataFile << fileLine [j];
						fileLine.erase (fileLine.begin (), fileLine.end ());
						dataFile.close ();
						return 0;
				}
				cursor = dataFile.tellp ();
		}
		dataFile.clear ();
		dataFile.seekp (0, std::ios::end);
		dataFile << saveString;
		dataFile.close ();
		return 0;
}

