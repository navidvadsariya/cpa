#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"contacts.h"


// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name* name)
{
	char respond;
	printf("Please enter the contact's first name: ");
	scanf("%30[^\n]%*c", &name->firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf("%c%*c", &respond);

	if (respond == 'Y' || respond == 'y')
	{
		printf("Please enter the contact's middle initial(s): ");
		scanf("%6[^\n]%*c", &name->middleInitial);
		respond = '\0';
	}

	printf("Please enter the contact's last name: ");
	scanf("%35[^\n]%*c", &name->lastName);

}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

void getAddress(struct Address* address)
{
	char respond;
	printf("Please enter the contact's street number: ");
	scanf("%u%*c", &address->streetNumber);

	printf("Please enter the contact's street name: ");
	scanf("%40[^\n]%*c", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf("%c%*c", &respond);

	if (respond == 'Y' || respond == 'y')
	{
		printf("Please enter the contact's apartment number: ");
		scanf("%u%*c", &address->apartmentNumber);
		respond = '\0';
	}

	printf("Please enter the contact's postal code: ");
	scanf("%7[^\n]%*c", address->postalCode);

	printf("Please enter the contact's city: ");
	scanf("%40[^\n]%*c", address->city);
}


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function

void getNumbers(struct Numbers* numbers)
{
	char respond;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf("%c%*c", &respond);

	if (respond == 'Y' || respond == 'y')
	{
		printf("Please enter the contact's cell phone number: ");
		scanf("%10[^\n]%*c", numbers->cell);
		respond = '\0';
	}


	printf("Do you want to enter a home phone number? (y or n): ");
	scanf("%c%*c", &respond);

	if (respond == 'Y' || respond == 'y')
	{
		printf("Please enter the contact's home phone number: ");
		scanf("%10[^\n]%*c", numbers->home);
		respond = '\0';
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf("%c%*c", &respond);

	if (respond == 'Y' || respond == 'y')
	{
		printf("Please enter the contact's business phone number: ");
		scanf("%10[^\n]%*c", numbers->business);
		respond = '\0';
	}
}
