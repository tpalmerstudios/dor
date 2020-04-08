#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "Terminal.h"

bool numValid (std::string);

int main ()
{
		Terminal out;
		std::string left, query;
		int leftPadding, topPadding;
		leftPadding = (out.getWidth () - 50) / 2;
		topPadding = (out.getHeight () - 11) / 3;
		for (int i = 0; i < leftPadding; i++)
		{
				left += " ";
		}
		while (1)
		{
				std::cout << out.clearscr () << out.color (97,44);
				for (int i = 0; i < out.getWidth (); i ++)
				{
						for (int j =0; j < out.getHeight (); j++)
						{
								std::cout << " ";
						}
						std::cout << std::endl;
				}
				if (out.getHeight () >= 14 && out.getWidth () >= 50)
				{
						std::cout << out.clearscr () << out.down (topPadding);
						std::cout << left << " ____________        ______     ___________\n";
						std::cout << left << " \\           \\     _/       \\_   \\          \\\n";
						std::cout << left << "  \\           \\   /     /     \\  \\    /\\     \\\n";
						std::cout << left << "   |    /\\     | /     /\\      |  |   \\_\\    |\n";
						std::cout << left << "   |   |  |    ||     |  |     |  |      ___/    \n";
						std::cout << left << "   |    \\/     ||     |  |     |  |      \\  ____ \n";
						std::cout << left << "  /           /||     | /     /| /     /\\ \\/    \\\n";
						std::cout << left << " /___________/ ||\\       ____/ | _____/ |\\______|\n";
						std::cout << left << "|           | / | \\_____\\   | / |     | | |     |\n";
						std::cout << left << "|___________|/   \\ |    |___|/  |_____|/ \\|_____|\n";
						std::cout << left <<"                  \\|____|                        \n\n";
						std::cout << left <<"---DATA-ORGANIZER--------------------------------\n";
						std::cout << left <<"|  " + out.color (37, 44) + out.underline () + "                                           " + out.color (97, 44) + out.underlineOff () + "  |\n";
						std::cout << left <<"|" + out.underline () + "                                               " + out.underlineOff () + "|\n";
						std::cout << out.goLoc (out.getWidth (), (leftPadding / 2)) << "1) New Entry";
						std::cout << out.right (leftPadding / 2) << "2) Edit Entry";
						std::cout << out.right (leftPadding / 2) << "3) View Entry";
						std::cout << out.right (leftPadding / 2) << "4) Delete Entry";
						std::cout << out.goLoc (0, 0) << out.down (topPadding + 13) << out.right (leftPadding + 3);
						std::cout << out.color (30, 44) + out.underline ();
						std::cin >> query;
						std::cout << out.underlineOff ();
				}
				else
				{
						std::cout << out.clearscr () << "DOR - DataOrganizer\n";
						std::cout << "1) New Entry\n";
						std::cout << "2) Edit Entry\n";
						std::cout << "3) View Entry\n";
						std::cout << "4) Delete Entry\n";
						std::cin >> query;
				}
				if (numValid (query) && query.length () == 1)
				{
						if (query == "1")
						{
								// New Entry
						}
						else if (query == "2")
						{
								// Edit Entry
						}
						else if (query == "3")
						{
								// View Entry
						}
						else if (query == "4")
						{
								// Delete entry
						}
						else
						{
						}
				}
				else
				{
						if (query == "new" || query == "NEW" || query == "n")
						{
								// New Person Function
						}
						else if (query == "edit" || query == "EDIT" || query == "e")
						{
								// select person to edit person
						}
						else if (query == "view" || query == "VIEW" || query == "v")
						{
								// select person to view person
						}
						else if (query == "delete" || query == "DELETE" || query == "v")
						{
								// select person to delete person
						}
						else
						{
								// search person with string and view
						}
						// Check for different queries
				}
		}
                         
		return 0;
}
