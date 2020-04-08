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
				/*
				 * Creates a new Person with a -1 ID and empty strings
				 */
				Person ()
				{
						fName = mName = lName = "";
						id = -1;
				}
				/*
				 * Creates a new Person with data loaded from a string via toPerson ()
				 * @param saveString a custom format string containing Person data
				 */
				Person (std::string saveString)
				{
						this->toPerson (saveString);
				}
				/*
				 * Loads a Person from a string with custom format
				 * @param saveString 
				 */
				void toPerson (std::string);
				/**
				 * Sets the first name of Person ()
				 * @param name a string to be placed in the first name
				 */
				void setFName (std::string);
				/**
				 * Sets the middle name of Person ()
				 * @param name a string to be placed in the middle name
				 */
				void setMName (std::string);
				/**
				 * Sets the last name of Person ()
				 * @param name a string to be placed in the last name
				 */
				void setLName (std::string);
				/**
				 * Sets the ID of a Person () based on the last entry in a file
				 * Searches through a file for ID numbers and places a new ID on the final line
				 * @param file a filename to be searched for Person entries
				 */
				void setID (std::string);
				/*
				 * Outputs a Person with minimal structuring
				 */
				void outPerson ();
				/*
				 * Sets the ID of a Person ()
				 * @param searchID an int to be placed as ID in Person
				 */
				void setID (int);
				/*
				 * Gets the ID from a Person ()
				 * @returns a number holding an ID
				 */
				int getID ()
				{ return id; }
				/*
				 * Gets the first name from a Person ()
				 * @returns a string holding the first name
				 */
				std::string getFName ()
				{ return fName; }
				/*
				 * Gets the middle name from a Person ()
				 * @returns a string holding the middle name
				 */
				std::string getMName ()
				{ return mName; }
				/*
				 * Gets the last name from a Person ()
				 * @returns a string holding the last name
				 */
				std::string getLName ()
				{ return lName; }

};
#endif
