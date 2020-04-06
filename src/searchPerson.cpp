#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "Person.h"

Person toPerson (std::string);
Person IDtoPerson (int);
int outPerson (Person);
Person searchPerson (std::string filename)
{
		// Declare Variables
		std::string searchPhrase, current;
		std::ifstream dataFile;
		int results;
		Person search;
		std::vector <Person> matched;
		std::string selection = "0";
		bool valid = false;

		// Initialize variables
		results = 0;
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
				while (std::getline (dataFile, current))
				{
						if (current.find (searchPhrase) != std::string::npos)
						{
								matched.push_back (toPerson (current));
								std::cout << "Result #" << results + 1 << std::endl;
								outPerson (matched [results]);
								results ++;
						}
				}

				// Check results it appears this part below works correctly
				// However the partabove does not load in the data
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
								if (std::all_of (selection.begin (), selection.end (), [](unsigned char c) {return std::isdigit(c);}) && std::stoi (selection) < results + 1 && std::stoi (selection) > 0)
								{
										valid = true;
								}
						}
						search = matched [std::stoi (selection) - 1];
				}
				matched.erase (matched.begin (), matched.end ());
		}
		return search;
}

