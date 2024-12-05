#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream> 
using namespace std;

//function prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main()
{
	while (true)
	{
		//variables
		int year;
		int month;

		//input
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;
		if (cin.fail())
			break;

		//ouput
		switch (month)
		{
		case 1: cout << "January"; break;
		case 2: cout << "Febrary"; break;
		case 3: cout << "March"; break;
		case 4: cout << "April"; break;
		case 5: cout << "May"; break;
		case 6: cout << "June"; break;
		case 7: cout << "July"; break;
		case 8: cout << "August"; break;
		case 9: cout << "September"; break;
		case 10: cout << "October"; break;
		case 11: cout << "November"; break;
		case 12: cout << "December"; break;
		}
		cout << " " << year << " has " << daysInMonth(month, year) << " days.\n";
	}
}

/**
isLeapYear – determines whether a given year is a leap year
under the Gregorian calendar.
@param year the year; expected to be >= 1582
@return true if year is a leap year; false otherwise
*/
bool isLeapYear(int year)
{
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	else
		return false;
}

/**
daysInMonth – determines the number of days in a specified month
@param month the month; expected to be in the range [1..12]
@param year the year; expected to be >= 1582
@return either 28, 29, 30, or 31, based on month and (leap) year
*/
int daysInMonth(int month, int year)
{
	if (month == 2)
	{
		if (isLeapYear(year))
			return(29);
		else
			return(28);
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return(31);
	else
		return(30);
}


