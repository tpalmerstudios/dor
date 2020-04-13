#include <string>
#include <iostream>
#ifndef PERSON_H
#define PERSON_H
/*
 * @class Person is a class that holds details about a human
 * and allows a developer to access and edit information held
 * within the class. It is one of several similar classes in DOR
 * including: Vehicle (), Residence (), and Organization ().
 */
class Person
{
		private:
				std::string fName; /// A Persons first name (or common name)
				std::string mName; /// A Persons middle name
				std::string lName; /// A Persons last name (or surname)
				// Gender, DOB, 
				float id;

		public:
				/*
				 * @brief This is a default constructor of the Person class.
				 *
				 * The default Person constoctor initializes `fName`, `mName`, `lName` to empty strings.
				 * `id` is set to `-1`. Checking for a -1 ID is the recommended way to test if a Person is valid
				 */
				Person ()
				{
						fName = mName = lName = "";
						id = -1;
				}
				/*
				 * @brief Creates a new Person with data loaded from a string using Person::toPerson ()
				 *
				 * This Person constructor initializes variables based on a std::string passed to the function.
				 * It uses Person::toPerson () to do so.
				 * The string should be in the format `"#[XXXXXX]NameOne;Namer Two;Name-Three"`.
				 * Where `XXXXXX` are 6 base-10 digits without any decimals or negative signs.
				 * `NameOne`, `Name Two`, and `Name-Three` are alphabetic strings that may include hyphens and spaces
				 * These will be placed in `fName`, `mName`, and `lName` respectively.
				 *
				 * @param saveString a custom format string containing Person data
				 */
				Person (std::string saveString)
				{
						this->toPerson (saveString);
				}
				/*
				 * @brief Changes data in selected Person with data loaded from a string
				 *
				 * This function adjusts variables based on a std::string passed to the function.
				 * The string should be in the format `"#[XXXXXX]NameOne;Namer Two;Name-Three"`.
				 * Where `XXXXXX` are 6 base-10 digits without any decimals or negative signs.
				 * `NameOne`, `Name Two`, and `Name-Three` are alphabetic strings that may include hyphens and spaces
				 * These will be placed in `fName`, `mName`, and `lName` respectively.
				 *
				 * @param saveString a custom format string containing Person data
				 */
				void toPerson (std::string);
				/**
				 * Sets the first name of Person ()
				 *
				 * @param name a string to be placed in the first name
				 */
				void setFName (std::string);
				/**
				 * Sets the middle name of Person ()
				 *
				 * @param name a string to be placed in the middle name
				 */
				void setMName (std::string);
				/**
				 * Sets the last name of Person ()
				 *
				 * @param name a string to be placed in the last name
				 */
				void setLName (std::string);
				/**
				 * @brief Sets the ID of a Person () based on the last entry in a file
				 *
				 * Opens a file and uses regular expressions std::regex to find the final Person entry in the file
				 * and takes the ID of that entry and adds one and places that in the `id` variable.
				 * 
				 * @param file a filename to be searched for Person entries
				 */
				void setID (std::string);
				/*
				 * @Outputs a Person with minimal structuring
				 *
				 * Outputs each set of labels and variables in the class to stdout.
				 * *Output:* `First Name: John`
				 */
				void outPerson ();
				/*
				 * Sets the ID of a Person ()
				 * @param searchID an int to be placed as ID in Person
				 */
				void setID (int);
				/*
				 * Gets the ID from a Person ()
				 * @returns id a Person ID number
				 */
				int getID ()
				{ return id; }
				/*
				 * Gets the first name from a Person ()
				 * @returns fName a string holding the first name
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
