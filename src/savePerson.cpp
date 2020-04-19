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
		int ending, cursor, i, j;
		char character;

		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << human.getID ();
		idString = "#[" + idStream.str () + "]";
		saveString = idString + human.getFName () + ";" + human.getMName () + ";" + human.getLName () + ";\n";

		// My File opening section. There has to be a better way... TODO
		dataFile.open (dor.getFilename (), std::ios::in);
		if (dataFile.fail ())
		{
				dataFile.open (dor.getFilename (), std::ios::out);
				if (dataFile.fail ())
					return -1;
		}
		dataFile.close ();
		dataFile.open (dor.getFilename (), std::ios::in | std::ios::out | std::ios::binary);

		ending = 0;
		dataFile.seekp (0, std::ios::beg);
		cursor = dataFile.tellp ();
		// Figure out size of file
		while (dataFile >> character)
				ending ++;
		// Clear EOF flag and go to the beginning
		dataFile.clear ();
		dataFile.seekp (0, std::ios::beg);
		// If the file is smaller than one line, just go to the beginning and write over
		if (ending < 16)
		{
				dataFile << saveString;
				if (dataFile.fail ())
				{
						dataFile.close ();
						return -1;
				}
				else
				{
						dataFile.close ();
						return 0;
				}
		}
		// Place next line in a buffer
		while (std::getline (dataFile, buffer))
		{
				// If the current line matches the ID inputed
				if (buffer.find (idString) != std::string::npos)
				{
						// If the ID matches the current line. Go to the cursor (which is the end of the previous line)
						// fill a vector with lines after the found line. go to cursor at the end of previous line
						// write into the file from that point the entire vector. delete the vector and close the file
						int shorten = (buffer.length () - saveString.length ()) + 1;
						std::vector<std::string> fileLine;
						fileLine.push_back (saveString);
						for (i = 1; !dataFile.fail (); i++)
						{
								fileLine.push_back ("");
								std::getline (dataFile, fileLine [i]);
								fileLine [i] += "\n";
						}
						dataFile.clear ();
						dataFile.seekp (cursor);
						for (j = 0; j < i; j++)
								dataFile << fileLine [j];

						if (dataFile.fail ())
						{
								dataFile.close ();
								return -1;
						}
						else
						{
								dataFile.close ();
								fileLine.erase (fileLine.begin (), fileLine.end ());
								if (shorten > 0)
										dor.shrinkFile (shorten);
								return 0;
						}
				}
				cursor = dataFile.tellp ();
		}
		dataFile.clear ();
		dataFile.seekp (0, std::ios::end);
		dataFile << saveString;
		if (dataFile.fail ())
		{
				dataFile.close ();
				return -1;
		}
		dataFile.close ();
		return 0;
}

