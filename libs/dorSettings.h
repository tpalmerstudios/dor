#include <string>
#include <filesystem>
#include "Person.h"

#ifndef DOR_SETTINGS
#define DOR_SETTINGS
class dorSettings
{
private:
		std::string filename;
		short int fg, bg, hiFG, hiBG;
		bool basicMode;
		int filesize;
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
		int getFilesize ()
		{
				std::filesystem::path filePath = std::filesystem::current_path () / filename;
				filesize = std::filesystem::file_size (filePath);
				return filesize;
		}
		void shrinkFile (int shrinkSize)
		{
				std::filesystem::path filePath = std::filesystem::current_path () / filename;
				std::filesystem::resize_file (filePath, (getFilesize () - shrinkSize));
		}
};
#endif
