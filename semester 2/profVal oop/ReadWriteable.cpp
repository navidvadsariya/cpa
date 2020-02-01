/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#include <iostream>
#include "ReadWriteable.h"

using namespace std;

namespace sdds {

	std::ostream& operator<<(std::ostream& os, const ReadWriteable& readWriteable)
	{
		readWriteable.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, ReadWriteable& readWriteable)
	{
		readWriteable.read(is);
		return is;
	}
}