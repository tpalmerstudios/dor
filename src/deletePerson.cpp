#include "Person.h"
#include "dorSettings.h"
#include "Terminal.h"
#include <fstream> 		//Normal File Operations
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

Person selectPerson ();
/// int deletePerson (std::string filename) takes a string that holdsthe name of a file to open. It opens the file and retrieves a selected Person via selectPerson (). It then deletes the entry from the file and truncates the file to correct length. It returns 0 on success and -1 on failure

int deletePerson (Person human, dorSettings dor, Terminal out)
{
		std::string saveString, line;
		std::stringstream idStream;
		std::fstream dataFile;
		std::vector <std::string> all;
		int id, i, j, matches = 0;
		bool found = false;
		size_t stringLength = 0;

		id = human.getID ();
		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << id;
		saveString = "#[" + idStream.str () + "]" + human.getFName () + ";" + human.getMName () + ";" + human.getLName ();

		dataFile.open (dor.getFilename (), std::ios::out | std::ios::binary | std::ios::in);
		if (dataFile.fail ())
		{
				std::cerr << dor.getFilename () << "could not be opened.\n";
				return -1;
		}

		for (i = 0; std::getline (dataFile, line); i++)
		{
				if (line.find (saveString) == std::string::npos && dataFile)
				{
						all.push_back (line);
				}
				else if (dataFile.fail ())
				{}
				else
				{
						stringLength = line.length ();
						found = true;
						matches ++;
				}
		}
		if (!found)
		{
				std::cerr << "Person not found. Nothing Deleted.\n";
				return -1;
		}

		// Re-enter all data in file from vector
		dataFile.clear ();
		dataFile.seekp (dataFile.beg);
		for (j = 0; j < (i - matches); j++)
		{
				dataFile << all [j] << "\n";
		}
		all.erase (all.begin (), all.end ());
		dataFile.close ();

		dor.shrinkFile ((stringLength + 1) * matches);
		return 0;
}

