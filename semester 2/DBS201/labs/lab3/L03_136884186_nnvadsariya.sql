/*Q1. Display the information of all offices.*/
Select *
From offices;
/*Q2. Display the employee number for all employees whose office code is 1. */
Select distinct employees
Where officeCode = 1;
/*Q3. Display customer number, customer name, contact first name and contact last name, and phone for all customers in Paris.*/
Select distinct customerNumber, customerName, contactFirstName,contactLastName,phone
From customers
Where city = ‘Paris’;
/*Q4. Display customer number for customers who have payments.*/
Select distinct customerNumber
From payments
Where amount > 0;
/*Q5. List customer numbers, check number, and amount for customers whose payment amount is not in the range of $30,000 to $65,000. Sort the output by top payments amount first.*/
Select distinct customerNumber,checkNumber,amount
From payments
Where  amount < 30000 and amount >  65000
Order by amount desc;
/*Q6. Display the order information for all orders that are cancelled.*/ 
Select distinct *
From orders
Where status = ‘Cancelled’;
 /*Q7. Display the information of all products with string ‘co’ in their product name. (c and o can be lower or upper case).*/
Select distinct *
From products
Where productName =’%co%’; 
/*Q8. Display all customers whose contact first name starts with letter s (both lowercase and uppercase) and includes letter e (both lowercase and uppercase).*/
Select distinct *
From customers
Where contactFirstName = ‘s%’ and contactFirstName = ‘%e%’;
