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
		int prevLine, results;
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
						prevLine = dataFile.tellg ();
						if (current.find (searchPhrase) != std::string::npos)
						{
								matched.push_back (toPerson (current));
								std::cout << "Result #" << results + 1 << std::endl;
								outPerson (matched [results]);
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

Person selectPerson ()
{
		Person human;
		std::string selection = "";
		std::string idString;
		bool valid = false;
		while (selection == "")
		{
				std::cout << "Enter ID or Search for a person? ";
				std::cin >> selection;
				if (selection == "id" || selection == "ID")
				{
						while (!valid)
						{
								std::cout << "Enter ID: ";
								std::cin >> idString;
								// Great little snippet from stack overflow to test if all digits are numeric
								// Save this gem! https://stackoverflow.com/a/33532715
								if (std::all_of (idString.begin (), idString.end (), [](unsigned char c) {return std::isdigit(c);}))
								{
										valid = true;
										std::cout << "Does it work up to here?\n";
										human = IDtoPerson (std::stoi (idString));
								}
								else
								{
										valid = false;
								}
						}
				}
				else if (selection == "search" || selection == "search")
				{
						human = searchPerson (".logfile.txt");
						std::cout << human.getFName();
				}
				else
				{
						selection = "";
				}
		}
		return human;
}
