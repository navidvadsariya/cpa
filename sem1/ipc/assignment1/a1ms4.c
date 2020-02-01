/* -------------------------------------------
Name: Navid Vadsariya
Student number:136884186
Email: nnvadsariyanavid@myseneca.ca
Section:SHH
Date:7/13/19
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include"contacts.h"



int main(void)
{
	// Declare variables here :

	// Create a variable of type Contact and call it something self-describing like "contact"
	// - HINT: Be sure to initialize the values to 0 and empty C strings
	// IMPORTANT:  Do NOT declare variables of type Name, Address, or Numbers
	struct Contact contact = { 0 };

	// Displaying the title
	printf("Contact Management System\n");
	printf("=========================\n");

	// Calling the Contact function getName to store the values for the Name member
	getName(&contact.name);

	// Calling the Contact function getAddress to store the values for the Address member
	getAddress(&contact.address);

	// Calling the Contact function getNumbers to store the values for the Numbers member
	getNumbers(&contact.numbers);

	// Displaying Contact summary details
	printf("\nContact Details\n");
	printf("---------------\n");

	printf("Name Details\n");
	printf("------------\n");
	printf("First name: %s\n", contact.name.firstName);
	printf("Middle initial(s): %s\n", contact.name.middleInitial);
	printf("Last name: %s\n", contact.name.lastName);

	printf("\nAddress Details\n");
	printf("------------\n");
	printf("Street number: %u\n", contact.address.streetNumber);
	printf("Street name: %s\n", contact.address.street);
	printf("Apartment: %u\n", contact.address.apartmentNumber);
	printf("Postal code: %s\n", contact.address.postalCode);
	printf("City: %s\n", contact.address.city);

	printf("\nPhone Numbers:\n");
	printf("------------\n");
	printf("Cell phone number: %s\n", contact.numbers.cell);
	printf("Home phone number: %s\n", contact.numbers.home);
	printf("Business phone number: %s\n", contact.numbers.business);


	// Displaying Completion Message
	printf("Structure test for Contact using functions done!\n");

	return 0;
}