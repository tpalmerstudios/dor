#include <string>
#include <algorithm>
#include <iostream>
#include "Person.h"
#include "Terminal.h"
#include "dorSettings.h"

Person searchPerson (std::string, dorSettings, Terminal);
Person IDtoPerson (int, dorSettings, Terminal);
bool idValid (std::string);
bool searchValid (std::string);

Person selectPerson (dorSettings dor, Terminal out)
{
		Person human;
		std::string selection, query = "";
		bool valid = false;
		while (selection == "")
		{
				std::cout << out.color (dor.getFG (), dor.getBG ()) << out.clearscr () << "DOR - DATA ORGANIZER\n\n";
				std::cout << "Enter ID or Search for a person? ";
				std::cin >> selection;
				if (selection == "id" || selection == "ID")
				{
						while (!valid)
						{
								std::cout << out.clearscr () << "DOR - DATA ORGANIZER\n\n";
								std::cout << "Enter ID or Search for a person? ID\n";
								std::cout << "Enter ID: ";
								std::cin >> query;
								// Great little snippet from stack overflow to test if all digits are numeric
								// Save this gem! https://stackoverflow.com/a/33532715
								// I am setting valid to true on purpose!
								if (idValid (query) && (valid = true))
										human = IDtoPerson (std::stoi (query), dor, out);
						}
				}
				else if (selection == "search" || selection == "search")
				{
						while (!valid)
						{
								std::cout << "Enter a search term: ";
								std::cin >> query;
								if (searchValid (query) && (valid = true))
										human = searchPerson (query, dor, out);
						}
				}
				else
						selection = "";
		}
		return human;
}
