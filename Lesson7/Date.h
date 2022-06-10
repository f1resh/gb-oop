#pragma once
#include <string>
#include <iostream>
class Date
{
private:
	size_t day;
	size_t month;
	size_t year;
	std::string MONTHS[12] = {"January","February","March","April","May","June","July","August","September","October","November","December" };
	friend std::ostream& operator<<(std::ostream& out, const Date& date);
public:
	Date(size_t _day, size_t _month, size_t _year);
	size_t getDay() const;
	size_t getMonth() const;
	std::string getMonthName() const;
	size_t getYear() const;
	void setDay(size_t);
	void setMonth(size_t);
	void setYear(size_t);
};

