
// Final Project Milestone 1 
// Date Module
// File	Date.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2019/11/11		       Preliminary release
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include "Utils.h"
using namespace std;
#include "Date.h"
namespace sdds {
	bool Date::validate()
	{
		errCode(NO_ERROR);
		if (m_year < MIN_YEAR || m_year > m_CUR_YEAR) {
			errCode(YEAR_ERROR);
		}
		else if (m_mon < 1 || m_mon > 12) {
			errCode(MON_ERROR);
		}
		else if (m_day < 1 || m_day > mdays()) {
			errCode(DAY_ERROR);
		}
		return !bad();
	}
	int Date::mdays()const
	{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}
	int Date::curYear()const
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		return lt.tm_year + 1900;
	}
	void Date::setToToday()
	{
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		errCode(NO_ERROR);
	}
	int Date::daysSince0001_1_1()const
	{ // Rata Die day since 0001/01/01 
		int ty = m_year;
		int tm = m_mon;
		if (tm < 3) {
			ty--;
			tm += 12;
		}
		return 365 * ty + ty / 4 - ty / 100 + ty / 400 + (153 * tm - 457) / 5 + m_day - 306;
	}
	Date::Date() :m_CUR_YEAR(curYear())
	{
		setToToday();
	}
	Date::Date(int year, int mon, int day) : m_CUR_YEAR(curYear())
	{
		m_year = year;
		m_mon = mon;
		m_day = day;
		validate();
	}
	const char* Date::dateStatus()const
	{
		return DATE_ERROR[errCode()];
	}
	int Date::currentYear()const
	{
		return m_CUR_YEAR;
	}
	void Date::errCode(int readErrorCode)
	{
		m_ErrorCode = readErrorCode;
	}
	int Date::errCode()const
	{
		return m_ErrorCode;
	}
	bool Date::bad()const
	{
		return m_ErrorCode != 0;
	}
	//cin operator for date
	istream& Date::read(istream& is)
	{
		errCode(NO_ERROR);
		is >> m_year;
		is.ignore(1);
		is >> m_mon;
		is.ignore(1);
		is >> m_day;

		if (is.fail())
		{
			errCode(CIN_FAILED);
			is.clear();
			flushKeyboard();
		}
		else
		{
			if (!validate())
			{
				errCode(CIN_FAILED);
			}
		}
		
		return is;
	}
	//cout operator for date
	ostream& Date::write(ostream& os)const
	{
		if (bad()) {
			os << dateStatus();
		}
		else {
			os << m_year << "/";
			os.width(2);
			os.fill('0');
			os.setf(ios::right);
			os << m_mon << "/";
			os.width(2);
			os << m_day;
			os.unsetf(ios::right);
			os.fill(' ');
		}
		return os;
	}
	//returns number of days since 0001_1_1
	int Date::days()const
	{
		return daysSince0001_1_1();
	}
	//returns true if both dates are same
	bool operator==(const Date& lhs, const Date& rhs)
	{
		return (lhs.days() == rhs.days());
	}
	//returns true if both dates are not same
	bool operator!=(const Date& lhs, const Date& rhs)
	{
		return (!(lhs == rhs));
	}
	//returns true if lhs >= rhs
	bool operator>=(const Date& lhs, const Date& rhs)
	{
		return (lhs.days() >= rhs.days());
	}
	//returns true if lhs <= rhs
	bool operator<=(const Date& lhs, const Date& rhs)
	{
		return (lhs.days() <= rhs.days());
	}
	//returns true if lhs > rhs
	bool operator>(const Date& lhs, const Date& rhs)
	{
		return(lhs.days() > rhs.days());
	}
	//returns true if lhs < rhs
	bool operator<(const Date& lhs, const Date& rhs)
	{
		return(lhs.days() < rhs.days());
	}
	//returns lhs >= rhs
	int operator-(const Date& lhs, const Date& rhs)
	{
		return (lhs.days() - rhs.days());
	}
	//returns true if date is valid
	Date::operator bool()
	{
		return (validate());
	}
	ostream& operator<<(ostream& os, const Date& date)
	{
		date.write(os);
		return os;
	}
	//reads date
	istream& operator>>(istream& is, Date& date)
	{
		date.read(is);
		return is;
	}
}
