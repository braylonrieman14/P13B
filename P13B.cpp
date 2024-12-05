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
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;
		if (cin.fail())
			break;

		//calendar
		// character positions:  012345678901234567890123456789012345678
		  string calendar[] = { "                   1  2  3  4  5  6  7 ",
								" 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
								" 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
								"16 17 18 19 20 21 22 23 24 25 26 27 28 ",
								"23 24 25 26 27 28 29 30 31             ",
								"30 31                                  " };

		//finds first day of month
		int firstDay = dayOfWeek(month, 1, year);

		//output
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
		cout << " " << year << "\nSu Mo Tu We Th Fr Sa\n";
		
		int counter;
		if (firstDay == 0)
			counter = 0;
		else if (firstDay == 1)
			counter = 18;
		else if (firstDay == 2)
			counter = 15;
		else if (firstDay == 3)
			counter = 12;
		else if (firstDay == 4)
			counter = 9;
		else if (firstDay == 5)
			counter = 6;
		else if (firstDay == 6)
			counter = 3;
		for (int i = 0; i <= 5; i++)
		{
			int temp = 20;
			if (i >= 4)
			{
				if (daysInMonth(month, year) == 30)
					temp -= 6;
				if (daysInMonth(month, year) == 29)
					temp -= 6;
				if (daysInMonth(month, year) == 28)
					temp -= 12;
			}
			cout << calendar[i].substr(counter, temp) << endl;
		}
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

