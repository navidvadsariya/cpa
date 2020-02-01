//----------------------------------------------
// Name:           Navid Vadsariya
// Student Number: 136884186
// Email:          nnvadsariya@myseneca.ca
// Section:        SHH
// Workshop:       3 (at-home)
//----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#define NUMS 4

#include<stdio.h>

int main(void)
{
	int i = 0, high = 0, low = 0, done = 0 , high_total = 0, low_total = 0, max = 0,min = 0 , high_day = 0 , low_day = 0;
	float high_mean = 0.0f, low_mean = 0.0f, total_mean=0;

	printf("---=== IPC Temperature Analyzer ===---");

	for (i = 0;i < NUMS;i++)
	{
		while (done == 0)
		{
			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%d", &high);

			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%d", &low);

			if (high < low || high > 40 || low < -40)
			{
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			}
			else
			{
				done = 1;
			}
		}
		
		done = 0;
		high_total += high;
		low_total += low;		

		if (i == 0)
		{
			max = high;
			min = low;
			high_day = i + 1;
			low_day = i + 1;
		}

		if (high > max)
		{
			max = high;
			high_day = i + 1;
		}
		if (low < min)
		{
			min = low;
			low_day = i + 1;
		}		
	}

	high_mean = (float) high_total / NUMS;
	low_mean = (float) low_total / NUMS;
	total_mean = (float)(high_total + low_total) / (2 * NUMS) ;
	
	printf("\nThe average(mean) LOW temperature was: %.2f", low_mean);
	printf("\nThe average(mean) HIGH temperature was: %.2f", high_mean);
	printf("\nThe average(mean) temperature was: %.2f", total_mean);
	printf("\nThe highest temperature was %d, on day %d", max , high_day);
	printf("\nThe lowest temperature was %d, on day %d", min , low_day);

	return(0);
}
