/*
1.	Create an empty table exactly the same as the employees table and name it newEmployees.
*/

create table  newEmployee as 
select * from employees;

set autocommit = off;
	start transaction;

/*
3.	Write an INSERT statement to populate the newEmployees table with the rows of the sample data.
 Insert the NULL value for the reportsTo column. (Write a single INSERT statement to insert all the rows)
*/
insert into newEmployees
values
(100,'Patel','Ralph',22333,'rpatel@mail.com',1,NULL,'Sales Rep'),
(101,'Denis','Betty',33444,'bdenis@mail.com',4,NULL,'Sales Rep'),
(102,'Biri','Ben',44555,'bbirir@mail.com',2,NULL,'Sales Rep'),
(103,'Newman','Chad',66777,'cnewman@mail.com',3,NULL,'Sales Rep'),
(104,'Ropeburn','Audrey',77888,'aropebur@mail.com',1,NULL,'Sales Rep');

/*
4.	Create a report that shows all the inserted rows from the newEmployees table. How many rows are selected?

*/

select *
from newEmployees;
/*5 rows are selected.*/

/*
5.	Execute the rollback command. Display all rows and columns from the newEmployees table. How many rows are selected?
*/
rollback;
select* from newEmployees;
/*5 rows are selected.*/

/*
6.	Do Task 3. Make the insertion permanent to the table newEmployees.
 Display all rows and columns from the newEmployee table. How many rows are selected?
*/
commit;
select * from newEmployee;
/*5 rows are selected.*/

/*
7.Write an update statement to update the value of column jobTitle to ‘unknown’
 for all the employees in the newEmployees table.
 */
update newEmployee
set jobTitle = 'unknown';

/*8.	Make your changes permanent.*/
commit;

/*
9.	Execute the rollback command. 
*/
rollback;

/*
a.	Display all employees from the newEmployees table whose job title is ‘unknown’. How many rows are updated?
*/
select * from newEmployee
where jobTitle = 'unknown';
/*
all the rows are updated
*/
/*
b.	Was the rollback command effective?
No it did not do anything as commit command was used ealier.
*/

/*
c.	What was the difference between the result of the rollback execution from Task 5 and the result
 of the rollback execution of this task?
 First rollback was effictive but second command did not do anything as there was a commit command executed before.
*/