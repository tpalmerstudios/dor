#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"
#include "dorSettings.h"
#include "Terminal.h"

Person IDtoPerson (int);
bool searchValid (std::string);
bool numValid (std::string);

Person searchPerson (std::string query, dorSettings dor, Terminal out)
{
		std::ifstream dataFile;
		Person human;
		dataFile.open (dor.getFilename (), std::ios::binary);
		if (dataFile.fail ())
				return human;
		if (!searchValid (query))
				return human;

		int results = 0;
		std::string current, selection;
		std::vector <Person> matched;
		bool valid = false;
		while (results == 0)
		{
				while (std::getline (dataFile, current))
				{
						if (current.find (query) != std::string::npos)
						{
								human.toPerson (current);
								matched.push_back (human);
								std::cout << out.bold () << "Result #" << results + 1 << out.boldOff () << std::endl;
								matched [results].outPerson ();
								results ++;
						}
				}
				if (results == 0)
						results --; 
				else
				{
						while (!valid)
						{
								std::cout << "Please select a person using the number above entry: ";
								std::cin >> selection;
								if (numValid (selection) && std::stoi (selection) < results + 1 && std::stoi (selection) > 0)
										valid = true;
						}
						human = matched [(std::stoi (selection)) - 1];
				}
				matched.erase (matched.begin (), matched.end ());
		}
		return human;
}
