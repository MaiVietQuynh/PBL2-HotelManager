#include "Date.h"
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

Date::Date(const int &day, const int &month, const int &year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(const Date &date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date::~Date()
{
}

int Date::Get_day()
{
    return this->day;
}

int Date::Get_month()
{
    return this->month;
}

int Date::Get_year()
{
    return this->year;
}

void Date::Set_day(int day)
{
    this->day = day;
}

void Date::Set_month(int month)
{
    this->month = month;
}

void Date::Set_year(int year)
{
    this->year = year;
}
istream &operator>>(istream &in, Date &date)
{
    in >> date.day >> date.month >> date.year;
    return in;
}
ostream &operator<<(ostream &os, const Date &date)
{
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}

const Date &Date::operator=(const Date &date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    return (*this);
}
bool Date::IsLeapYear()
{
    if (this->year % 400 == 0 || (this->year % 4 == 0 && this->year % 100 != 0))
    {
        return true;
    }
    return false;
}
bool Date::IsValidDate()
{
    if (this->day <= 0 || this->month <= 0 || this->year <= 0)
        return false;
    switch (this->month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (this->day > 0 && this->day <= 31)
        {
            return true;
            break;
        }
        else
        {
            return false;
            break;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        if (this->day > 0 && this->day <= 30)
        {
            return true;
        }
        else
        {
            return false;
        }
    case 2:
        if (IsLeapYear() == true)
        {
            if (this->day > 0 && this->day <= 29)
                return true;
            return false;
        }
        else
        {
            if (this->day > 0 && this->day <= 28)
                return true;
            return false;
        }
    default:
        return false;
    }
}
int Date::DayInMonth(const int &month, const int &year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) ? 29 : 28;
    default:
        return 0;
    }
}
void Date::PreviousDay(int& day, int& month, int& year)
{
	if (IsValidDate() == true)
	{
		day--;
		if (day == 0)
		{
			month--;
			if (month == 0)
			{
				year--;
				month = 12;
				day = 31;
			}
			else
				day = DayInMonth(month, year);
		}
	}
}

int Date::countDay(Date thatdate)
{
    int count = 0;
    int d = day;
    int m = month;
    int y = year;
    if (IsValidDate() == true)
    {
        while (d != thatdate.day || m != thatdate.month || y != thatdate.year)
        {
            PreviousDay(d, m, y);
            count++;
        }
    }
    return count;
}
bool Date::operator==(const Date &D){
    return (this -> day == D.day && this -> month == D.month && this -> year == D.year);
}