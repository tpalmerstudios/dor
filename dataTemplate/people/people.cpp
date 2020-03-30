#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Structures
// Names, ID #, (DOB, DOD, Anniversaries), (Height, Weight, Race, Hair Color, Hair Notes, Eye Color, Distinguishing Marks), Family, Cars, Home, (Occupations, Wages), (Images, Associated Files), (Associates Names, IDs, Relations), 
struct person
{
	string name; // Add other names?
	double id;
	double dob;
	double dod; // Add other dates?
	double height; // In cm, convert from other formats
	double weight; // In kg, convert from other formats
	string race; // Go with char instead but need a conversion list
	string hairColor; // Go with char instead but need a conversion list
	string hairNotes;
	string eyeColor; // Go with char instead but need a conversion list
	string bodyMarks; // Use an array and a selection of type for multiple
	// Array of numbers to link to with people
	// Array of numbers to link to with car
	// Array of numbers to link to with home
	// Create a structure for businesses
};
// License Plate, VIN, Make, Model, Year, Color, KBB Value, Notes
struct car
{};
// Parents, ID, Note, S.Os, ID, Note, Siblings, ID, Nite, Children, ID, Note, Notes
struct home
{};

// Functions
// Save/Edit File Details
int savePerson (struct person);
int saveCar (struct car);
int saveFamily (struct family);
int saveHome (struct home);
// View File Details in a concise way
int viewPerson (struct person);
int viewCar (struct car);
int viewFamily (struct family);
int viewHome (struct home);
int search ();
int menu ();

int main ()
{
	return 0;
}
