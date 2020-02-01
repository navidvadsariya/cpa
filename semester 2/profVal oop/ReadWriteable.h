/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#ifndef SDDS_READWRITEABLE_H__
#define SDDS_READWRITEABLE_H__
#include <iostream>
namespace sdds {
	
	class ReadWriteable
	{
	public:
		//virtual read function
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		//virtual write function
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
	};
	//operator overload for cout
	std::ostream& operator<<(std::ostream& os, const ReadWriteable& readWriteable);
	//operator overload for cin
	std::istream& operator>>(std::istream& is, ReadWriteable& readWriteable);
	
}
#endif // !