#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds{

	void flushKeyboard()
	{
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n');
	}

}