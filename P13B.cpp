#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream> 
using namespace std;

//function prototypes
bool isLeapYear(int year);

int main()
{
	while (true)
	{
		//variables
		int year;

		//input
		cout << "Enter a year or Q to quit: ";
		cin >> year;
		if (cin.fail())
			break;

		//ouput
		if (isLeapYear(year))
			cout << year << " is a leap year.\n";
		else
			cout << year << " is not a leap year.\n";
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

