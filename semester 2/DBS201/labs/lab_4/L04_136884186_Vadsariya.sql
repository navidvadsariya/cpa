/*
This entire lab is done by me and nothing is copied from anywhere.
*/

/*
Part A
1. Create the following tablles and their given constraints:(20%)
MOVIES (id:int, title:varchar(35), year:int, director:int,score:decimal(3,2))	
*/
CREATE TABLE MOVIES(
id int PRIMARY KEY,
title varchar(35) NOT NULL,
year int NOT NULL,
Director int NOT NULL,
score decimal(3,2),
Constraint score check(0 and 5)
);

/*
ACTORS (id:int, name:varchar(20), lastname:varchar(30))
*/
CREATE TABLE ACTORS(
id int PRIMARY KEY,
name varchar(20) NOT NULL,
Lastname varchar(30) NOT NULL
);

/*
CASTINGS (movieid:int, actorid:int)
*/
CREATE TABLE CASTINGS(
movieid int,
actorid int,
primary key(movieid,actorid:int)
);

/*
DIRECTORS(id:int, name:varchar(20), lastname:varchar(30))
*/
CREATE TABLE DIRECTORS(
id int primary key,
name varchar(20)NOT NULL,
Lastname varchar(30)NOT NULL,
);

/*
2.	Modify the movies table to create a foreign key constraint that refers to table directors. (10%) 
*/
ALTER TABLE MOVIES
ADD FOREIGN KEY (Directors)references Directors(id);

/*
3.	Modify the movies table to create a new constraint so the uniqueness of the movie title is guaranteed. (10%)
*/
ALTER TABLE MOVIES
ADD UNIQUE(title);

/*
4.	Write insert statements to add the following data to table directors and movies. (10%)
*/
INSERT INTO Directors(id,name,Lastname)
VALUES(1010,'Rob','Minkoff');

INSERT INTO Directors(id,name,Lastname)
VALUES(1020,'Bill','Condon');

INSERT INTO Directors(id,name,Lastname)
VALUES(1050,'Josh','Cooley');

INSERT INTO Directors(id,name,Lastname)
VALUES(2010,'Brad','Bird');

INSERT INTO Directors(id,name,Lastname)
VALUES(3020,'Lake','Bell');

INSERT INTO Movies(id,title,year,director,score)
VALUES(100,'The Lion King',2019,3020,3.50);

INSERT INTO Movies(id,title,year,director,score)
VALUES(200,'Beauty and the Beast',2017,1050,4.20);

INSERT INTO Movies(id,title,year,director,score)
VALUES(300,'Toy Stroy 4',2019,1020,4.50);

INSERT INTO Movies(id,title,year,director,score)
VALUES(400,'Mission Impossible',2018,2010,5.00);

INSERT INTO Movies(id,title,year,director,score)
VALUES(500,'The Secret Life of Pets',2016,1010,3.90);

/*
5.	Write a SQL statement to remove all above tables. Is the order of tables important when removing? Why? (5%)
*/
DROP TABLE ACTORS;
DROP TABLE CASTINGS;
DROP TABLE DIRECTORS;
DROP TABLE MOVIES;
/*
Yes the order is important as some tables may have a primary key with other tables.
*/

/*
Part B (More DML) (45%):
*/
/*
1.	Create a new empty table employee2 exactly the same as table employees. (5%)
*/
CREATE TABLE employee2 AS
(SELECT * FROM employees);

/*
2.	Modify table employee2 and add a new column username to this table. The value of this column is not required and does not have to be unique. (10%)
*/

ALTER TABLE employee2
ADD username varchar(30);

/*
3.	Insert all student data from the employees table into your new table employee2. (5%)
*/
INSERT INTO employee2
SELECT * FROM employees
where jobTitle = 'student';

/*
4.	In table employee2, write a SQL statement to change the first name and the last name of employee with ID 1002 to your name. (5%)
*/

UPDATE employee2
SET firstName = 'Navid', lastName = 'Vadsariya'
where employeeNumber = 1002;

/*
5.	In table employee2, generate the email address for column username for each student by concatenating the first character of employee’s first name and the employee’s last name. For instance, the username of employee Peter Stone will be pstone. (10%)
*/

SELECT 
concat(substring(firstName,1,1),substring(lastName,1,30))username
FROM employee2;

/*
6.	In table employee2, remove all employees with office code 4. (5%)
*/
DELETE FROM employee2
WHERE officeCode = 4;

/*
7.	Drop table employee2. (5%)
*/
DROP TABLE employee2;