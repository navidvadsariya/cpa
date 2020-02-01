#pragma once
/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds {
	const int NO_ERROR = 0;
	const int CIN_FAILED = 1;
	const int YEAR_ERROR = 2;
	const int MON_ERROR = 3;
	const int  DAY_ERROR = 4;
	const char DATE_ERROR[5][20] = {
	   "No Error",
	   "Invalid Date Object",
	   "Bad Year Value",
	   "Bad Month Value",
	   "Bad Day Value"
	};
	const int  MIN_YEAR = 1500;
	class Date
	{
	private:
		int m_year;
		int m_mon;
		int m_day;
		int m_ErrorCode;
		int m_CUR_YEAR;
		int daysSince0001_1_1()const; // returns number of days passed since the date 0001/1/1
		bool validate();             /* validates the date setting the error code and then returning the result
									  true, if valid, and false if invalid.*/
		void errCode(int);           // sets the error code
		int curYear()const;          // returns the current system year
		bool bad()const;             // return true if
		int mdays()const;            // returns the number of days in current month
		void setToToday();           // sets the date to the current date (system date)
	public:
		Date();                      // creates a date with current date
		Date(int year, int mon, int day); /* create a date with assigned values
										   then validates the date and sets the
										   error code accordingly */
		int errCode()const;         // returns the error code or zero if date is valid
		const char* dateStatus()const;  // returns a string corresponding the current status of the date
		int currentYear()const;         // returns the m_CUR_YEAR value;

		//returns number of days since 0001_1_1
		int days()const;
		//reads date
		std::istream& read(std::istream& is = std::cin);
		//displays date
		std::ostream& write(std::ostream& os = std::cout)const;
		//returns true if date is valid
		operator bool();

	};
	//returns true if both dates are same
	bool operator==(const Date& lhs, const Date& rhs);
	//returns true if both dates are not same
	bool operator!=(const Date& lhs, const Date& rhs);
	//returns true if lhs >= rhs
	bool operator>=(const Date& lhs, const Date& rhs);
	//returns true if lhs <= rhs
	bool operator<=(const Date& lhs, const Date& rhs);
	//returns true if lhs > rhs
	bool operator>(const Date& lhs, const Date& rhs);
	//returns true if lhs < rhs
	bool operator<(const Date& lhs, const Date& rhs);
	//returns lhs >= rhs
	int operator-(const Date& lhs, const Date& rhs);
	//cout operator for date
	std::ostream& operator<<(std::ostream& os, const Date& date);
	//cin operator for date
	std::istream& operator>>(std::istream& is, Date& date);
}
#endif