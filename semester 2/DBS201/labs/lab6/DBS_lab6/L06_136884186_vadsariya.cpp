#include <mysql.h>
#include <iostream>


using namespace std;

int main(void)
{
	//declartion
	MYSQL* conn;
	conn = mysql_init(0);
	int exequery;
	string query = "select employeeNumber, firstName,lastName and extension  from employees;";
	const char* q = query.c_str();
	exequery = mysql_query(conn, q);
	MYSQL_RES* res;
	MYSQL_ROW row;
	string query1 = "select employeeNumber,lastName,phoneNumber and extension  from employees where jobTitle is manager;";
	const char* q1 = query1.c_str();
	exequery = mysql_query(conn, q1);
	MYSQL_RES* res1;
	MYSQL_ROW row1;


	conn = mysql_real_connect(conn, "mymysql.senecacollege.ca", "db_nnvadsariya", "NW-ad8GAmN", "DBS211", 3306, nullptr, 0);

		if (conn) {
			cout << "successful connection to database" << endl;
		}
		else {
			cout << "Connection Failed" << mysql_error(conn) << endl;
		}

		if (!exequery) {
			//query execution is successful
			cout << "The query executed successfully with no error." << endl;
		}
		else {
		//query execution is not successful
		cout << "Error message: " << mysql_error(conn) << ": " << mysql_errno(conn) << endl;
        }
		//first command
		res = mysql_store_result(conn);
		mysql_error(res);
		mysql_errorno(res);
		
		if (mysql_fetch_row(res) == nullptr) {
			cout << "The result is empty." << endl;
		}
		cout << "*************** Employee Report ***************";
		cout << "Employee Report:";
		while (row = mysql_fetch_row(res)) {
			printf("Employee Number: %s,First Name: %s, Last Name: %s , Extension: %s\n", row[0], row[1],row[3], row[4]);

		}
		//second command
		res1 = mysql_store_result(conn);
		mysql_error(res1);
		mysql_errorno(res1);

		if (mysql_fetch_row(res1) == nullptr) {
			cout << "The result is empty." << endl;
		}
		
		cout << "Manager Report:";
		while (row1 = mysql_fetch_row(res1)) {
			printf("Employee Number: %s, Last Name: %s,Phone Number : %s,, Extension: %s\n", row[0], row[1], row[3], row[4]);

		}

		mysql_close(conn);
		
	
		return 0;
}
