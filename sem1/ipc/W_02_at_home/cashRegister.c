//----------------------------------------------
// Name:           Navid Vadsariya
// Student Number: 136884186
// Email:          nnvadsariya@myseneca.ca
// Section:        SHH
// Workshop:       2 (at_home)
//----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	double amount, GST;
	int loonies, quarters, dimes, nickel, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &amount);

	GST = (amount * 0.13) + 0.005;
	amount += GST;
	printf("GST: %.2lf\nBalance owing: $%.2lf\n", GST,amount);

	loonies = (int) amount;
	amount -= loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n", loonies, amount);

	quarters = ((int)(amount * 100)) / 25;
	amount = (double) ((int)(amount * 100) % 25) / 100;
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, amount);

	dimes = ((int)(amount * 100)) / 10;
	amount = (double)((int)(amount * 100) % 10) / 100;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, amount);

	nickel = ((int)(amount * 100)) / 5;
	amount = (double)((int)(amount * 100) % 5) / 100;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickel, amount);
	
	pennies = ((int)(amount * 100));
	amount = (double)((int)(amount * 100) % 1) / 100;
	printf("Pennies required: %d, balance owing $%.2lf ", pennies, amount);

	return 0;
}
