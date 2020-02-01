#pragma once
/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#ifndef SDDS_MAGAZINE_H__
#define SDDS_MAGAZINE_H__
#include "PubRecord.h"
namespace sdds {

	class Magazine : public PubRecord
	{
		int volume;
		int issueNumber;

	public:
		//default constructor
		Magazine();
		//copy constructor
		Magazine(const Magazine& m_magazine);
		//returns ID (M)
		char recID() const;
		//checks in Magazines
		void checkIn();
		//check Magazines out
		void checkOut();

		//reads Magazines values
		std::istream& read(std::istream& is = std::cin);
		//displays Magazines
		std::ostream& write(std::ostream& os = std::cout) const;
	};
}
#endif // !


