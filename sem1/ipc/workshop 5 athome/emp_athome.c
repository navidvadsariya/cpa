
//----------------------------------------------
// Name:           Navid Vadsariya
// Student Number: 136884186
// Email:          nnvadsariya@myseneca.ca
// Section:        SHH
// Workshop:       5 (at-home)
//----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define SIZE 4


 
struct employee
{
	int ID, age;
	double salary;
};

/* main program */
int main(void)
{

	int option = 0, counter = 0,update_search=0, done = 0, remove_search=0;
	double new_salary = 0;
	struct employee emp[SIZE] = { {0} };

	printf("---=== EMPLOYEE DATA ===---\n\n");

	do {
		
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	
			printf("Exiting Employee Data Program. Good Bye!!!");

			break;
		case 1: 
				
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (int i = 0; i < SIZE; i++)
			{
				if (emp[i].ID > 0)
				{
					printf("%6d%9d%11.2lf\n", emp[i].ID, emp[i].age, emp[i].salary);
				}
			}
						printf("\n");
			break;
		case 2:	
			printf("Adding Employee\n");
			printf("===============\n");

			if (counter >= SIZE)
			{
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			}
			else
			{
				for (int i = 0; i < SIZE; i++)
				{
					if (emp[i].ID == 0)
					{
						printf("Enter Employee ID: ");
						scanf("%d", &emp[i].ID);


						printf("Enter Employee Age: ");
						scanf("%d", &emp[i].age);


						printf("Enter Employee Salary: ");
						scanf("%lf", &emp[i].salary);
						break;
					}
				}
				

				counter++;
			}
			printf("\n");


			break;
		case 3:
			printf("Update Employee Salary\n");
			printf("======================\n");
			do
			{
				printf("Enter Employee ID: ");
				scanf("%d", &update_search);


				for (int i = 0; i <= SIZE; i++)
				{
					if (emp[i].ID == update_search)
					{
						printf("The current salary is %.2lf\n", emp[i].salary);
						printf("Enter Employee New Salary: ");
							scanf("%lf", &new_salary);
							emp[i].salary = new_salary;
							done = 1;
							break;
					}

				}
				if (done == 0)
				{
					printf("*** ERROR: Employee ID not found! ***\n");
				}
				
			} while (done == 0);
			break;
		case 4: done = 0;
			    printf("Remove Employee\n");
				printf("===============\n");
				do
				{
					printf("Enter Employee ID: ");
					scanf("%d", &remove_search);


					for (int i = 0; i <= SIZE; i++)
					{
						if (emp[i].ID == remove_search)
						{
							printf("Employee %d will be removed\n\n",emp[i].ID);
							emp[i].ID = 0;
							done = 1;
							counter--;
							break;
						}

					}
					if (done == 0)
					{
						printf("*** ERROR: Employee ID not found! ***\n");
					}

				} while (done == 0);
				break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


	return 0;
}

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements