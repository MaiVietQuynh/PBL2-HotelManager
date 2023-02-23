#ifndef _DATE_
#define _DATE_
#include<string>
#include <iostream>
#include <time.h>
#include <ctime>
#include <cmath>
#include <sstream>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public: 
    
    Date(const int& = -1, const int& = -1, const int& = -1);
    Date(const Date&);
	~Date();

    friend istream& operator>> (istream&, Date&);
	friend ostream& operator<< (ostream&, const Date&);
    const Date& operator=(const Date&);
    bool operator==(const Date&);

	int Get_day();
	int Get_month();
    int Get_year();
    void Set_day(int);
    void Set_month(int);
    void Set_year(int);
    bool IsLeapYear();
	bool IsValidDate();
    static int DayInMonth(const int&, const int&);
    void PreviousDay(int&, int&, int&);
    int countDay(Date);
    bool operator <(Date x)
    {
    	if(year < x.Get_year())
    		return true;
    	if(year == x.Get_year() && month < x.Get_month())
    		return true;
    	if(year == x.Get_year() && month == x.Get_month() && day < x.Get_day())
    		return true;
    	if(year == x.Get_year() && month == x.Get_month() && day == x.Get_day())
    		return true;
    	return false;
	}
  	int operator-(Date x){		
		long kc=0;
		kc=abs(year-x.Get_year())*365;
		int ngay1=day-1+(month*30-30);
		int ngay2=x.Get_day()-1+(x.Get_month()*30-30);
		kc=kc+abs(ngay1-ngay2);
		return kc;
	}
	void getToDay()
	{
		time_t rawtime;
	    time(&rawtime);
	    struct tm* timeinfo;
	    timeinfo = localtime(&rawtime);
	    day = timeinfo->tm_mday;
	    month = timeinfo->tm_mon + 1;
	    year = timeinfo->tm_year + 1900;
	}
	string toString() {
	    stringstream res;
	    res << this->day << "/" << this->month << "/" << this->year;
	    return res.str();
	}
	string toString1() {
	    stringstream res;
	    res << this->day << "_" << this->month << "_" << this->year;
	    return res.str();
	}
	int daysBetweenDates(Date date2)
	{
	    string str1, str2;
	    str1 = this->toString();
	    str2 = date2.toString(); // dang dd/mm/yyy
	
	    stringstream ss(str1 + "/" + str2);
	    int year, month, day;
	    char hyphen;
	
	    // Parse the first date into seconds
	    ss >> day >> hyphen >> month >> hyphen >> year;
	    struct tm starttm = { 0, 0, 0, day,
	                          month - 1, year - 1900 };
	    time_t start = mktime(&starttm);
	
	    // Parse the second date into seconds
	    ss >> hyphen >> day >> hyphen
	        >> month >> hyphen >> year;
	    struct tm endtm = { 0, 0, 0, day,
	                        month - 1, year - 1900 };
	    time_t end = mktime(&endtm);
	
	    // Find out the difference and divide it
	    // by 86400 to get the number of days
	    return abs(end - start) / 86400;
	
	}

    // static Date getCurrentDate();


};    
#endif
