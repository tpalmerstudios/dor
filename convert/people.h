#include <string>
#include <vector>
#include <iostream>
#ifndef PEOPLE_H
#define PEOPLE_H

class People
{
private:
// ID
		const float id;
// First Name
		string fName;
// Middle Name
		string mName;
// Last Name
		string lName;
// Alternate ID Vector
		vector<float> altID;
// Alias Vecors
		vector<string> alias;
// DOB
		string dob;
// Date Vector
		vector<string> date;
		vector<string> dateNotes;
// Height
		int height;
// Weight
		int weight;
// Race
		int race;
// Complexion
		string complexion;
// Body Markings
		vector<string> markings;
// Eye Color
		char eyeColor;
// Hair Color
		char hairColor;
// Hair Notes
		string hairNotes;
// Relationship Name Vector
// Relationship ID Vector
// Car Vector
// Car Notes Vector
// Home Vector
// Home Notes Vector
// Workplace Vector
// Occupation Vector
// Income Vector
// Job Note Vector
// File Vector
// File Vector Notes

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

