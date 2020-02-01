/*
ALL THE PARTS OF THIS LAB IS DONE BY ME AND NOT COPIED FROM ANY SOURCE
1.	For all employees in France, display employee number, first name, last name, city, phone number and postal code.  (15%)
*/
SELECT employeeNumber,firstName,lastName,city,phone,postalCode
from employees
Inner Join offices
on employees.officeCode=4 and offices.officeCode=4;
/*
2.	Create a view (customer_order) to  list all orders with the following data for all customers:  
customerNumber, order number, order date,  order line number,product name, quantity ordered, and price for each product in every order. (15%)
*/
create view customer_order as
select orders.customerNumber,orderNumber, orderDate, orderLineNumber,productName, quantityOrdered, price
from orders
left join orderdetails
on orders.orderNumber=orderdetails.orderNumber
inner join products
on orderdetails.productCode=products.productCode;
/*
3.	Using the customer_order  view, display the order information for customer number 124. Sort the output based on order number and then order line number. (15%)
*/
select *
from custome_order
where customerNumber=124
order byorderNumber,orderLineNumber
/*
4.	Display customer number, first name, last name, phone, and credit limits for all customers who do not have any orders. (15%)
*/
select customerNumber,firstName,lastName,phone,creditLimit
from customers
on custmoers.customerNumber=order.customerNumber is null;
/*
5.	Create a view (employee_manager) to display all information of all employees and the name and the last name of their managers if there is any manager that the employee reports to. (15%)
*/
create view employee_manager as
select employees,manager.firstName,manager.lastName
from employees
left join employees as manager
on employee.reportsTo=manager.employeeNumber;
/*
6.	Modify the employee_manager view so the view returns only employee information for employees who have a manager. (15%)
*/
replace view employee_manager as 
select employee.*,manager.firstName,manager.lastName
where employee.reportTo is not null;
/*
7.	Drop both customer_order and employee_manager views. (10%)
*/
Drop view customer_order,employee_manager;
