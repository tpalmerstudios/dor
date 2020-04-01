#include <string>
#include <iostream>
#ifndef PEOPLE_H
#define PEOPLE_H

class People
{
private:
		// Birth Detais
		string fName;
		string mName;
		string lName;
		// Need vector to link alt names string

		int dob, dod, myID;
		// Need 2 vector to link a date int with an event string

		// Physical desciption
		int height, weight;
		char hairColor, eyeColor;
		string hairNotes; // Cut and dye
		// Relationships
		int humanID [5];
		string humanNote [5];
		// Possessions
		int carID;
		int homeID;
		// Documents
		// Pictures
		// Work & Income

public:
		// accessor templates
};
#endif

