#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include "Terminal.h"
#include "dorSettings.h"
#include "Person.h"

Person searchPerson (std::string, dorSettings, Terminal);
Person selectPerson (dorSettings, Terminal);
int deletePerson (Person, dorSettings, Terminal);
int editPerson (Person, dorSettings, Terminal);
int newPerson (dorSettings);
bool numValid (std::string);

int main ()
{
		Terminal out;
		dorSettings dor;
		dor.setFilename ("logfile.txt");
		dor.setFG (97);
		dor.setBG (44);
		dor.setHiFG (34);
		dor.setHiBG (40);
		dor.setBasicMode (false);
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
				if (dor.getBasicMode ())
				{
						std::cout << out.clearscr () << "DOR - DATA ORGANIZER\n";
						std::cout << "1) New Entry\n";
						std::cout << "2) Edit Entry\n";
						std::cout << "3) View Entry\n";
						std::cout << "4) Delete Entry\n";
						std::cin >> query;
				}
				else
				{
						std::cout << out.clearscr () << out.color (dor.getFG (), dor.getBG ());
						for (int i = 0; i < out.getWidth (); i ++)
						{
								for (int j =0; j < out.getHeight (); j++)
								{
										std::cout << " ";
								}
								std::cout << std::endl;
						}
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
						std::cout << left <<"|  " + out.color (37, dor.getBG ()) + out.underline () + "                                           " + out.color (dor.getFG (), dor.getBG ()) + out.underlineOff () + "  |\n";
						std::cout << left <<"|" + out.underline () + "                                               " + out.underlineOff () + "|\n";
						std::cout << out.goLoc (out.getWidth (), (leftPadding / 2)) << "1) New Entry";
						std::cout << out.right (leftPadding / 2) << "2) Edit Entry";
						std::cout << out.right (leftPadding / 2) << "3) View Entry";
						std::cout << out.right (leftPadding / 2) << "4) Delete Entry";
						std::cout << out.goLoc (0, 0) << out.down (topPadding + 13) << out.right (leftPadding + 3);
						std::cout << out.color (30, dor.getBG ()) + out.underline ();
						std::cin >> query;
						std::cout << out.underlineOff ();
				}
				if (query == "new" || query == "NEW" || query == "n" || query == "1")
				{
						if (newPerson (dor) != 0)
						{
								std::cerr << out.clearscr () << "Unable to create new person.\n";
								return -1;
						}
				}
				else if (query == "edit" || query == "EDIT" || query == "e" || query == "2")
				{
						if (editPerson (selectPerson (dor, out), dor, out) == -1)
						{
								//std::cerr << out.clearscr () << "Unable to view any entries.\n";
								return -1;
						}
				}
				else if (query == "view" || query == "VIEW" || query == "v" || query == "3")
						selectPerson (dor, out).outPerson ();
				else if (query == "delete" || query == "DELETE" || query == "v" || query == "4")
				{
						if (deletePerson (selectPerson (dor, out), dor, out) == -1)
						{
								std::cerr << out.clearscr () << "Unable to delete any entries.\n";
								return -1;
						}
				}
				else
				{
						if (searchPerson (query, dor, out).getID () == -1)
						{
								std::cerr << out.clearscr () << "Unable to find a result.\n";
								return -1;
						}
				}
		}
		return 0;
}

