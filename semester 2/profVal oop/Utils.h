/*****************************/
/*                           */
/* Author: Navid Vadsariya   */
/* Student Id: 136 884 186   */
/* OOP244 NAA                */
/*                           */
#pragma once
#ifndef SDDS_UTILS_H__
#define SDDS_UTILS_H__

namespace sdds {
	//Flushes keyboard
	void flushKeyboard();
	void input(char* str, int len, const char* errorMessage = "");
	void input(int& val, int min, int max, const char* errorMessage = "");
}
#endif // !

