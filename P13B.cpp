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
		string monthString;
		int day;
		string fileName;
		ofstream outFile;

		//input
		cout << "Enter a month and year or Q to quit: ";
		cin >> monthString >> year;
		if (cin.fail())
			break;

		if (monthString == "January")
			month = 1;
		if (monthString == "February")
			month = 2;
		if (monthString == "March")
			month = 3;
		if (monthString == "April")
			month = 4;
		if (monthString == "May")
			month = 5;
		if (monthString == "June")
			month = 6;
		if (monthString == "July")
			month = 7;
		if (monthString == "August")
			month = 8;
		if (monthString == "September")
			month = 9;
		if (monthString == "October")
			month = 10;
		if (monthString == "November")
			month = 11;
		if (monthString == "December")
			month = 12;

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

		cout << endl;

		switch (month)
		{
		case 1: fileName = "Jan"; break;
		case 2: fileName = "Feb"; break;
		case 3: fileName = "Mar"; break;
		case 4: fileName = "Apr"; break;
		case 5: fileName = "May"; break;
		case 6: fileName = "Jun"; break;
		case 7: fileName = "Jul"; break;
		case 8: fileName = "Aug"; break;
		case 9: fileName = "Sep"; break;
		case 10: fileName = "Oct"; break;
		case 11: fileName = "Nov"; break;
		case 12: fileName = "Dec"; break;
		}

		fileName += to_string(year) + ".txt";
		outFile.open(fileName);

		//output
		switch (month)
		{
		case 1: cout << "January"; outFile << "January"; fileName = "Jan"; break;
		case 2: cout << "Febrary"; outFile << "Febrary"; fileName = "Feb"; break;
		case 3: cout << "March"; outFile << "March"; fileName = "Mar"; break;
		case 4: cout << "April"; outFile << "April"; fileName = "Apr"; break;
		case 5: cout << "May"; outFile << "May"; fileName = "May"; break;
		case 6: cout << "June"; outFile << "June"; fileName = "Jun"; break;
		case 7: cout << "July"; outFile << "July"; fileName = "Jul"; break;
		case 8: cout << "August"; outFile << "August"; fileName = "Aug"; break;
		case 9: cout << "September"; outFile << "September"; fileName = "Sep"; break;
		case 10: cout << "October"; outFile << "October"; fileName = "Oct"; break;
		case 11: cout << "November"; outFile << "November"; fileName = "Nov"; break;
		case 12: cout << "December"; outFile << "December"; fileName = "Dec"; break;
		}
		
		outFile << " " << year << "\nSu Mo Tu We Th Fr Sa\n";
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
			outFile << calendar[i].substr(counter, temp) << endl;
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

