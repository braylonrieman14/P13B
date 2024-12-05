#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream> 
using namespace std;

//function prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);

int main()
{
	while (true)
	{
		//variables
		int year;
		int month;
		int day;

		//input
		cout << "Enter a date or Q to quit: ";
		cin >> month >> day >> year;
		if (cin.fail())
			break;

		//ouput
		switch (dayOfWeek(month, day, year))
		{
		case 0: cout << "Saturday"; break;
		case 1: cout << "Sunday"; break;
		case 2: cout << "Monday"; break;
		case 3: cout << "Tuesday"; break;
		case 4: cout << "Wednesday"; break;
		case 5: cout << "Thursday"; break;
		case 6: cout << "Friday"; break;
		}
		cout << ", ";
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
		cout << " " << day << ", " << year << endl;
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

/**
dayOfWeek - Computes the weekday of a given date.
@param year the year
@param month the month (1 = January ... 12 = December)
@param day the day of the month
@return the weekday (0 = Saturday ... 6 = Friday)
*/
int dayOfWeek(int month, int day, int year)
{
	if (month <= 2)
	{
		month += 12;
		year--;
	}
	return((day + ((month + 1) * 26 / 10) + year + (year / 4) + (6 * (year / 100)) + (year / 400)) % 7);
}

