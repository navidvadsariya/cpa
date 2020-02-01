#define _CRT_SECURE_NO_WARNINGS
//Navid Vadsariya  136884186
#include <mysql.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Employee
{
	int employeeNumber;
	char lastName[50];
	char firstName[50];
	char email[100];
	char phone[50];
	char extension[10];
	char reportsTo[100];
	char jobTitle[50];
	char city[10];
};
//Menu
int menu(void)
{
	int option = -1;
	bool done = false;
	while (!done) {
		cout << "********************* HR Menu *********************" << endl;
		cout << "1) Find Employee" << endl;
		cout << "2) Employees Report" << endl;
		cout << "3) Add Employee" << endl;
		cout << "4) Update Employee" << endl;
		cout << "5) Remove Employee" << endl;
		cout << "0) Exit" << endl;
		cin >> option;
		if (option >= 0 && option <= 5)
		{
			done = true;
		}
		else
		{
			cout << "wrong option selected" << endl;
		}
	}
	return option;
};
//searches employee 
int findEmployee(MYSQL* conn, int employeeNumber, struct Employee* emp = nullptr)
{
	int result = 0;

	if (conn != nullptr) {
		string command = "SELECT  e.employeeNumber,  e.lastName,  e.firstName , e.email, phone, e.extension, concat(e2.firstName, ' ', e2.lastName)  AS  ManagerName,  e.jobTitle, city FROM employees AS e LEFT JOIN employees AS e2 ON e2.employeeNumber  =  e.reportsTo INNER JOIN offices O  ON  O.officeCode = e.officeCode   WHERE e.employeeNumber = ";

		string employeeNumbers = to_string(employeeNumber);
		string colon = ";";
		string query = command + employeeNumbers + colon;
		const char* employeeQuery = query.c_str();

		int exequery;
		exequery = mysql_query(conn, employeeQuery);
		if (exequery) {
			cout << "Error message: " << mysql_error(conn) << endl;
		}

		MYSQL_RES* res;
		res = mysql_store_result(conn);

		MYSQL_ROW row;
		row = mysql_fetch_row(res);
		if (row != NULL) {
			if (emp != nullptr) {
				emp->employeeNumber = employeeNumber;
				strcpy(emp->lastName, row[1]);
				strcpy(emp->firstName, row[2]);
				strcpy(emp->email, row[3]);
				strcpy(emp->phone, row[4]);
				strcpy(emp->extension, row[5]);
				strcpy(emp->reportsTo, row[6]);
				strcpy(emp->jobTitle, row[7]);
				strcpy(emp->city, row[8]);
			}
			result = 1;
		}
	}
	return result;
}
//displays employee
void displayEmployee(MYSQL* conn, struct Employee emp)
{
	int employeeNumber;
	int checkResult;
	cout << "Enter a employee number to search: ";
	cin >> employeeNumber;
	cout << "Checking....." << endl;

	checkResult = findEmployee(conn, employeeNumber, &emp);

	if (checkResult == 1) {
		cout << "Employee Number: " << emp.employeeNumber << endl;
		cout << "Last Name: " << emp.lastName << endl;
		cout << "First Name: " << emp.firstName << endl;
		cout << "Email: " << emp.email << endl;
		cout << "Phone: " << emp.phone << endl;
		cout << "Extension: " << emp.extension << endl;
		cout << "Reports to: " << emp.reportsTo << endl;
		cout << "Job Title: " << emp.jobTitle << endl;
		cout << "City: " << emp.city << endl;
		cout << endl;
	}
	else {
		cout << "Employee " << employeeNumber << " does not exist." << endl;
	}
}
//displayes all employees
void displayAllEmployees(MYSQL* connection)
{
	string allEmployees = "SELECT e.employeeNumber,  CONCAT(e.firstName,' ', e.lastName)  as  employeeName, e.email, phone,e.extension, CONCAT(m.firstName, ' ', m.lastName)  as  managerName FROM employees e INNER JOIN employees m ON m.employeeNumber = e.reportsTo  INNER JOIN offices  ON  offices.officeCode = e.officeCode";

	const char* command = allEmployees.c_str();

	int exequery;
	exequery = mysql_query(connection, command);

	if (exequery) {
		cout << "**Error message** " << mysql_error(connection) << endl;
	}

	MYSQL_RES* res;
	res = mysql_store_result(connection);

	MYSQL_ROW row;

	while (row = mysql_fetch_row(res)) {
		printf("%s %-15s %-25s %-15s %-5s %-15s\n", row[0], row[1], row[2], row[3], row[4], row[5]);
	}
}

int main()
{
	int option;    //choice of option
	int done = 0;  //flag

	//connecting to server
	MYSQL* conn;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "mymysql.senecacollege.ca", "db_nnvadsariya", "NW-ad8GAmN", "db_nnvadsariya", 3306, nullptr, 0);
	if (conn) {
		cout << "successful connection to database" << endl;
	}
	else {
		cout << "Connection Failed" << mysql_error(conn) << endl;
	}

	while (done != 1) {
		option = menu();
		if (option == 1)
		{
			Employee emplopyee{ '\0' };

			displayEmployee(conn, emplopyee);
		}
		else if (option == 2)
		{
			displayAllEmployees(conn);
		}
		else if (option == 3)
		{
			cout << "(option 3)" << endl;
		}
		else if (option == 4)
		{
			cout << "(option 4)" << endl;
		}
		else if (option == 5)
		{
			cout << "(option 5)" << endl;
		}
		else if (option == 0)
		{
			cout << "Program terminated" << endl;
			done = 1;
		}
	}
	return 0;
}