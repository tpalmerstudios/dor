#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "Person.h"

#ifndef DOR_SETTINGS
#define DOR_SETTINGS
class dorSettings
{
private:
		std::string filename;
		short int fg, bg, hiFG, hiBG;
		bool basicMode;
		off_t filesize;
		struct stat filedata;
		const char *fileChar = filename.c_str ();
public:
		bool getBasicMode ()
		{ return basicMode; }
		void setBasicMode (bool mode)
		{ basicMode = mode; }
		std::string getFilename ()
		{ return filename; }
		void setFilename (std::string fileString)
		{ filename = fileString; }
		int getFG ()
		{ return fg; }
		int getBG ()
		{ return bg; }
		int getHiFG ()
		{ return hiFG; }
		int getHiBG ()
		{ return hiBG; }
		void setFG (short int colorCode)
		{ fg = colorCode; }
		void setBG (short int colorCode)
		{ bg = colorCode; }
		void setHiFG (short int colorCode)
		{ hiFG = colorCode; }
		void setHiBG (short int colorCode)
		{ hiBG = colorCode; }
		int shrinkFile (int stringSize)
		{
				if (truncate (fileChar, filesize - stringSize) != 0)
						return -1;
				return 0;
		}
};
#endif
