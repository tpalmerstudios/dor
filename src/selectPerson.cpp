#include <string>
#include <algorithm>
#include <iostream>
#include "Person.h"

Person searchPerson (std::string);
Person IDtoPerson (int);

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
										human = IDtoPerson (std::stoi (idString));
								}
						}
				}
				else if (selection == "search" || selection == "search")
				{
						human = searchPerson (".logfile.txt");
				}
				else
				{
						selection = "";
				}
		}
		return human;
}
