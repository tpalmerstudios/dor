#include "Person.h"
#include <fstream> 		//Normal File Operations
#include <unistd.h> 	//Access to ftrunctat
#include <sys/stat.h> 	//Access to stat (to find file size)
#include <sys/types.h>
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
		int id, i, j, matches = 0;
		bool found = false;
		off_t filesize;
		struct stat fileData;
		const char * fileChar = filename.c_str ();
		size_t stringLength = 0;

		if (stat (fileChar, &fileData))
				return -1;
		filesize = fileData.st_size;

		// Create a string that contains the Person data
		id = human.getID ();
		idStream << std::fixed << std::setprecision (0) << std::setw (6) << std::setfill ('0') << id;
		saveString = "#[" + idStream.str () + "]" + human.getFName ();
		saveString += ";" + human.getMName () + ";" + human.getLName ();

		// Open the file
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

		// Loop through file looking for a match to Person entered
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

		// Truncate the file to the size - anything we removed
		if (truncate (fileChar, filesize - (((stringLength + 1) * matches))) != 0)
		{
				std::cerr << "Failure to truncate. Though data may have been deleted.\n";
				return -1;
		}
		outPerson (human);
		std::cout << "This entry has been deleted...\n";

		return 0;
}

