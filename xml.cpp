#include <iostream>
#include <fstream>
#include <vector>
#include "libs/rapidxml.hpp"

int main ()
{
		std::ifstream dataFile ("logfile.xml");
		rapidxml::xml_document <> doc;

		std::vector<char> buffer ((std::istreambuf_iterator<char> (dataFile)), std::istreambuf_iterator<char> ( ));
		//buffer.push_back ('\0');
		std::cout << &buffer [0] << std::endl;
		dataFile.close ();
		doc.parse<0>(&buffer [0]);
		std::cout << "First node name: " << doc.first_node () -> name () << "\n";
		return 0;

}
