#pragma once
/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include "PubRecord.h"

namespace sdds {

	class Book : public PubRecord
	{
		long long int isbn;
		int membershipId;
		Date date;

	public:
		//default constructor
		Book();
		//copy constructor
		Book(const Book& book);
		//returns ID (B)
		char recID() const;
		//returns member ID
		int memberId() const;
		//checks in
		void checkIn();
		//check book out
		void checkOut();
		//reads input
		std::istream& read(std::istream& is = std::cin);
		//displays book
		std::ostream& write(std::ostream& os = std::cout) const;
		//assignment operator
		Book& operator=(const Book& b_book);
	};
}
#endif // !


