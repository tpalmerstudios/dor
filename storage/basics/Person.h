#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
class Person
{
		private:
				std::string fName;
				std::string mName;
				std::string lName;
				float id;

		public:
				void setFName (std::string);
				void setMName (std::string);
				void setLName (std::string);
				void setID (std::string);
				float getID ();
};
#endif
