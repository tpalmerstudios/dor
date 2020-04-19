#include <algorithm>
#include <chrono>
#include <ctime>
#include <string>

#ifndef DOR_DATE
#define DOR_DATE
class dorDate
{
		private:
				int date;
				int month;
				int year;
				std::string dateName;
		public:
				std::string getDateName ()
				{ return dateName; }
				void setDateName (std::string dName)
				{ dateName = dName; }
				int getDate ()
				{ return date; }
				void setDate (int cDate)
				{ date = (dateValid (cDate) ? cDate : -1); }
				int getMonth ()
				{ return month; }
				void setMonth (int cMonth)
				{ month = (monthValid (cMonth) ? cMonth : -1); }
				int getYear ()
				{ return year; }
				void setYear (int cYear)
				{ year = (yearValid (cYear) ? cYear : -1); }
				bool dateValid (int cDate)
				{ return (cDate > 0 && cDate < 32) ? true : false; }
				bool monthValid (int cMonth)
				{ return (cMonth > 0 && cMonth < 13) ? true : false; }
				bool yearValid (int cYear)
				{ return (cYear > 1920 && cYear < 2200) ? true : false; }
				bool numValid () (std::string check)
				{ return (all_of (check.begin (), check.end (), [](char c) {return (std::isdigit (c));})); }
				std::string getDMY ()
				{ return (toString (date) + toString (month) + toString (year)); }
				void setDMY (std::string dateString)
				{
						if (dateString.length = 8 && numValid (dateString))
						{
								int tempDate = atoi (dateString.substr (0, 2));
								int tempMonth = atoi (dateString.substr (2, 2));
								int tempYear = atoi (dateString.substr (4, 4));
								date = (dateValid (cDate) ? cDate : -1);
								month = (monthValid (cMonth) ? cMonth : -1);
								year = (yearValid (cYear) ? cYear : -1);
						}
						else if (dateString.length = 10)
						{
								int tempDate = atoi (dateString.substr (0, 2));
								int tempMonth = atoi (dateString.substr (3, 2));
								int tempYear = atoi (dateString.substr (6, 4));
								date = (dateValid (cDate) ? cDate : -1);
								month = (monthValid (cMonth) ? cMonth : -1);
								year = (yearValid (cYear) ? cYear : -1);
						}
						else
						{
								date = -1;
								month = -1;
								year = -1;
						}
				}
};
#endif
