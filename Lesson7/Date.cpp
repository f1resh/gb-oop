#include "Date.h"

Date::Date(size_t _day, size_t _month, size_t _year)
{
	day = (_day > 0 && _day <= 31) ? _day : 1;
	month = (_month > 0 && _month <= 12) ? _month : 1;
	year = (_year > 0 && _year <= 9999) ? _year : 1;
}

size_t Date::getDay() const
{
	return day;
}

size_t Date::getMonth() const
{
	return month;
}

std::string Date::getMonthName() const
{
	return MONTHS[month-1];
}

size_t Date::getYear() const
{
	return year;
}

void Date::setDay(size_t _day)
{
	if (_day < 1 || _day>31) {
		std::cout << "Wrong day number is entered!" << std::endl;
		return;
	}
	day = _day;
}

void Date::setMonth(size_t _month)
{
	if (_month < 1 || _month>12) {
		std::cout << "Wrong month number is entered!" << std::endl;
		return;
	}
	month = _month;
}

void Date::setYear(size_t _year)
{
	if (_year < 1 || _year>9999) {
		std::cout << "Wrong year number is entered!" << std::endl;
		return;
	}
	year = _year;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.day << " " << date.MONTHS[date.month - 1] << ", " << date.year;
	return out;
}
