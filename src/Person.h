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
				// Gender, DOB, 
				float id;

		public:
				Person ()
				{
						fName = mName = lName = "";
						id = -1;
				}
				Person (std::string saveString)
				{
						this->toPerson (saveString);
				}
				void toPerson (std::string);
				void setFName (std::string);
				void setMName (std::string);
				void setLName (std::string);
				void setID (std::string);
				void outPerson ();
				void setID (int);
				int getID ()
				{ return id; }
				std::string getFName ()
				{ return fName; }
				std::string getMName ()
				{ return mName; }
				std::string getLName ()
				{ return lName; }

};
#endif
