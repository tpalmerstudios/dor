#include "Person.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

Person selectPerson ();
int outPerson (Person);

int deletePerson (std::string filename)
{
		Person human = selectPerson ();
		std::string saveString, line;
		std::stringstream idStream;
		std::fstream dataFile;
		std::vector <std::string> all;
		int id, i, j;
		bool found = false;

		// Create a string that contains the Person data
		id = human.getID ();
		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << id;
		saveString = "#[" + idStream.str () + "]" + human.getFName ();
		saveString += ";" + human.getMName () + ";" + human.getLName ();

		dataFile.open (filename, std::ios::in);
		if (dataFile.fail ())
		{
				dataFile.open (filename, std::ios::out );
				if (dataFile.fail ())
				{
						std::cerr << filename << " could not be opened.\n";
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
		for (i = 0; std::getline (dataFile, line); i++)
		{
				if (line.find (saveString) == std::string::npos && dataFile)
				{
						all.push_back (line);
				}
				else if (dataFile.fail ())
				{
						found = false;
				}
				else
				{
						found = true;
						i --;
				}
		}
		if (!found)
		{
				std::cerr << "Person not found. Nothing Deleted.\n";
				return 3;
		}

		for (j = 0; j < i; j++)
		{
				dataFile.clear ();
				dataFile.seekp (dataFile.beg);
				dataFile << all [j] << "\n";
		}
		all.erase (all.begin (), all.end ());
		dataFile.close ();
		outPerson (human);
		std::cout << "This entry has been deleted...\n";

		return 0;
}

