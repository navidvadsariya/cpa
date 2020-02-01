/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */

#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {
	//flushes keyboard input
	void flushKeyboard()
	{
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n');
	}
	//Read str in desired length
	void input(char* str, int len, const char* errorMessage)
	{
		bool ok;
		do {
			ok = true;
			cin.getline(str, (len + 1), '\n');
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				ok = false;
			}
		} while (!ok && cout << errorMessage);
	}
	void input(int& val, int min, int max, const char* ErrorMess)
	{
		bool ok;
		char newline;
		do {
			cin >> val;
			newline = cin.get();
			if (cin.fail() || newline != '\n') {
				ok = false;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else {
				ok = val <= max && val >= min;
			}
		} while (!ok && cout << ErrorMess);
	}
}