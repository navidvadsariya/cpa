//*****************//
//*Navid Vadsariya//
//**136 884 186**//
//****DCF255****//
//*************//

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int i = 0;
	int counter = 0;
	string bit = "011111101111110";
	string flag = "01111110";

	cout << "Before Stuffing: " << bit << " -- " << bit.size() << " characters" << endl;

	for (i = 0; i < bit.size(); i++)
	{
		if (bit[i] == '1')
		{
			counter++;
		}
		else
		{
			counter = 0;
		}

		if (counter == 5 && (bit[i - 5] == '0'))
		{
			bit.insert(i + 1, "0");
			counter = 0;
		}
	}

	cout << "After Stuffing: " << bit << " -- " << bit.size() << " characters" << endl;
	bit.insert(0, flag);
	bit.append(flag);
	cout << "After framing: " << bit << endl;
	return 0;
}