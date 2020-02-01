//---------------------------------------------
// Name:           Navid Vadsariya
// Student Number: 136884186
// Email:          nnvadsariya@myseneca.ca
// Section:        SHH
// Workshop:       4 (in-lab)
//---------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include<stdio.h>
int main(void)
{
	int number_days, done = 0, i = 0, j=0, high[100], low[100];

	printf("---=== IPC Temperature CalculatorV2.0===---");
	printf("\nPlease enter the number of days,between 3 and 10, inclusive:");
	
	for (i = 0; i <= 10; i++)
	{
		while (done == 0)
		{
			scanf("%d", &number_days);
			if (number_days == 3 || number_days == 4 || number_days == 5 || number_days == 6 || number_days == 7 || number_days == 8 || number_days == 9 || number_days == 10)
			{
				done = 1;
			}
			else
			{
				printf("Invalid entry, please enter a number between 3 and 10, inclusive:");
			}
		}
	}
	for (j = 0; j < number_days; j++)
	{
		printf("Day %d - High:", j + 1);
		scanf("%d", &high[j]);
		printf("Day %d - Low:", j + 1);
		scanf("%d", &low[j]);

	}	
	printf("Day  Hi  Low");
	for (j = 0; j < number_days; j++)
	{
		//printf("Day  Hi  Low");
		printf("\n%-3d  %-2d  %3d", j + 1, high[j], low[j]);
	}
		
		
	return 0;
}