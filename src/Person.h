#include <string>
#include <iostream>
#ifndef PERSON_H
#define PERSON_H
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
				float getID ()
				{ return id; }
				std::string getFName ()
				{ return fName; }
				std::string getMName ()
				{ return mName; }
				std::string getLName ()
				{ return lName; }

};
#endif
