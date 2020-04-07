#include <algorithm>
#include <string>

// Takes a std::string and tests if every character is a letter a space or hyphen
bool nameValid (std::string check)
{
		bool valid = false;
		if (all_of (check.begin (), check.end (), [](char c) {return (std::isalpha (c) || c == ' ' || c == '-');}))
				valid = true;
		return valid;
}
// Takes a std::string and tests if every charater is a letter, a number or one of the following: ' ', '-', '#', or ':'.
bool searchValid (std::string check)
{
		bool valid = false;
		if (all_of (check.begin (), check.end (), [](char c) {return (std::isalpha (c) || std::isdigit (c) || c == ' ' || c == '-' || c == '#' || c == ':' );}))
				valid = true;
		return valid;
}
// Takes a std::string and tests if every character is a digit. NOTE: This does not allow for decimals or negative numbers.
bool numValid (std::string check)
{
		bool valid = false;
		if (all_of (check.begin (), check.end (), [](char c) {return (std::isdigit (c));}))
				valid = true;
		return valid;
}
// Takes a std:: string and tests if it consists of up to 6 numbers.
bool idValid (std::string check)
{
		return (check.size () <= 6 && numValid (check)) ? true : false;
}

