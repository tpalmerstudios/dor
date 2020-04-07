#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"

Person IDtoPerson (int);
bool searchValid (std::string);
bool numValid (std::string);

Person searchPerson (std::string filename)
{
		// Declare Variables
		std::string searchPhrase, current, selection;
		std::ifstream dataFile;
		Person search;
		std::vector <Person> matched;
		bool valid = false;
		int results = 0;

		dataFile.open (filename, std::ios::binary);
		if (dataFile.fail ())
		{
				std::cerr << filename << " could not be opened.\n";
				return search;
		}

		while (results == 0)
		{
				std::cout << "Enter an ID or any name: ";
				std::cin >> searchPhrase;
				while (searchValid (searchPhrase) && std::getline (dataFile, current))
				{
						if (current.find (searchPhrase) != std::string::npos)
						{
								search.toPerson (current);
								matched.push_back (search);
								std::cout << "Result #" << results + 1 << std::endl;
								matched [results].outPerson ();
								results ++;
						}
				}

				if (results == 0)
				{
						std::cerr << "No matches found. Try another search term.\n";
						results --; 
						searchPerson (filename);
				}
				else
				{
						while (!valid)
						{
								std::cout << "Please select a person using the number above entry: ";
								std::cin >> selection;
								if (numValid (selection) && std::stoi (selection) < results + 1 && std::stoi (selection) > 0)
								{
										valid = true;
								}
						}
						// Have issue with sometimes dissapearing search matches
						// Possibly due to having multiple search terms...
						search = matched [(std::stoi (selection)) - 1];
				}
				matched.erase (matched.begin (), matched.end ());
		}
		return search;
}
