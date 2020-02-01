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



	int number_days, done = 0, i = 0, j = 0, high[100], low[100], max, min, high_day, low_day, days_average, flag = 0, stop =0;
	float average;

	printf("---=== IPC Temperature CalculatorV2.0===---");
	printf("\nPlease enter the number of days,between 3 and 10, inclusive: ");

	for (i = 0; i <= 10; i++)
	{
		while (done == 0)
		{
			scanf("%d", &number_days);
			if (number_days >= 3 && number_days <= 10)
			{
				done = 1;
			}
			else
			{
				printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
			}
		}
	}
	printf("\n");
	for (j = 0; j < number_days; j++)
	{
		printf("Day %d - High: ", j + 1);
		scanf("%d", &high[j]);
		printf("Day %d - Low: ", j + 1);
		scanf("%d", &low[j]);

	}
	printf("\nDay  Hi  Low");

	for (j = 0; j < number_days; j++)
	{
		printf("\n%-3d  %-2d  %3d", j + 1, high[j], low[j]);
	}

	max = high[0];
	min = low[0];
	for (j = 0; j < number_days; j++)
	{
		if (high[j] > max)
		{
			max = high[j];
			high_day = j + 1;
		}

		if (low[j] < min)
		{
			min = low[j];
			low_day = j + 1;
		}
	}
	printf("\n\nThe highest temperature was %d, on day %d\nThe lowest temperature was %d, on day %d\n", max, high_day, min, low_day); 
	             
                   
	
	flag = 0;
	for (i = 0; i <= 20; i++)
	{
		printf("\nEnter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		while (flag == 0 && stop == 0)
		{
			scanf("%d", &days_average);
			if (days_average >= 1 && days_average <= 5)
			{
				flag = 1;
			}
			else if(days_average < 0)
			{
				printf("\nGoodbye!");
				stop = 1;
				break;
			}
			else
			{
				printf("\nInvalid entry, please enter a number between 1 and 5, inclusive: ");
			}
		}
		if (stop == 1)
		{
			break;
		}
		flag = 0;
		average = 0;
		for (j = 0; j < days_average; j++)
		{
			average += (high[j] + low[j]);
		}
		average /= (days_average * 2);
		printf("\n\nThe average temperature up to day %d is: %.2f\n", days_average, average);

	}
	
		
	return 0;
}