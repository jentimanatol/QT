
#Structured Query Language (SQL)


 CREATE DATABASE IF NOT EXISTS Cafe;


SELECT * FROM bhcclab1.students;
SELECT * FROM bhcclab1.courses;
SELECT * FROM bhcclab1.faculty;
SELECT * FROM bhcclab1.students;
use bhcclab1; 
SELECT * FROM students;

select * from students;
select studentName, studentGPA from students ; 

SELECT * FROM students where studentGPA < 3 ;
SELECT * FROM students where studentGPA > 3.5 ;


use bhcc;
select *from clients;
use bhcclab1;
select * from courses;
select CourseID, CourseName from courses where courseid < 11;
select CourseID, CourseName from courses LIMIT 0,15; # show  elements from 0 yo 15 
show tables;
explain courses; # give structure of the table , mention if can be null.
describe Students;  # same describe table 
#TIMESTAMP;   # RETURN DATE AND TIME AUTOMATICALY 
#VARCHAR() # CAN SPECIFAY HOU MUCH CARACTER WE CAN HAVE. 

------------------------------

#HOW TO CREATE TABLES -> 

#CREATE TABLE STUDENTS(ID int, lastname VARCHAR(256) , firstname VARCHAR(256) )

--------------------------

#CREATE A TABLE AND ALAW NULL LINE OR RESTRICT. 

create table Clasrooms (ID INT, Seats INT NULL, Building char not NULL, Room INT not null);
describe Clasrooms;

------------------------
#to make ID UNIQUE  : 
create table Clasrooms (ID INT not null unique, Seats INT NULL, Building char not NULL, Room INT not null);
describe Clasrooms;

------------------------
#to make ID primary : 
create table Clasrooms (ID INT not null unique, Seats INT NULL, Building char not NULL, Room INT not null, primary key (ID));
describe Clasrooms;
----------------------

#TO AUTOMATICALY INCREMENT id 
create table Clasrooms (ID INT not null auto_increment, Seats INT NULL, Building char not NULL, Room INT not null, primary key (ID));
describe Clasrooms;
-------------------------------------------


#combaining to diferent tables : -> 
select * from Courses;
select  CourseName, courses.TextbookISBN ,TextbookTitle, TextbookAuthor from Courses Join Textbooks where Courses.TextbookISBN = Textbooks.TextbookISBN  ;

# show all from 2 fiferent tables 
select * from Courses Join Textbooks where Courses.TextbookISBN = Textbooks.TextbookISBN  ;

-----------------------------------


#automatic comand creater :

CREATE TABLE `bhcc7`.`users` (
  `id` INT NOT NULL AUTO_INCREMENT,
  `firstname` VARCHAR(45) NOT NULL,
  `lastname` VARCHAR(45) NOT NULL,
  `phone` VARCHAR(20) NULL,
  `email` VARCHAR(45) NOT NULL DEFAULT 'admin.bhcc@edu',
  `Date` DATE NULL DEFAULT NOW(),
  PRIMARY KEY (`id`));

------------------------------
#autoincrements 
create table customertest3 (id int auto_increment, lastname varchar(125) , `first name` varchar(54), primary key( id ));

-------------------------------------
#droping a table 

drop table customertest2;

--------------------------------
# name of the table with 2 words  mentioned use ````` not ''''''' cveri important 

create table customer1 (id int, lastname varchar(125) , `first name` varchar(54));

-----------------------------
# create a data base if not eist 

create table if not exists customertest4 (id int auto_increment, lastname varchar(125) , `first name` varchar(54), primary key( id ));

--------------------------------------------------------
#explain table  if it is autoincrement , with one is prime key.

explain customertest4;
----------------------------------------------------------

# describe a table 

describe customertest4;


--------------------------------
#drop a table or drop table if exist drop multiple tables .
drop table customertest4;
drop table if exists customertest4;
drop table if exists customertest4 ,customertest3 ;



---------------------------------------------
# select time as default with local server time auto inserted. 
create table testtable1 (id int, `last name` varchar(100), date_registred datetime default now());

--------------------

# show warning 
show warnings;

--------------------------------


select *from customers limit 1000, 10 ; # firs number start from and second one how much customers to show . 

select *from employees limit 3; # use one number by default from zero 

-----------------------------------------------
select orderID, Customers.firstname, Customers.Lastname, employees.firstname, employees.Lastname 
 from orders join customers, employees where orders.customerID = Customers.customerID and orders.employeeID = employees.employeeID ;
 # joining of 3 tables in one requares 


select orderID , Customers.firstname as `Customers Firstname` , Customers.Lastname as 'Customers Lastname' , employees.firstname, employees.Lastname 
 from orders join customers, employees where orders.customerID = Customers.customerID and orders.employeeID = employees.employeeID ;

# as use to rename visible the colum name inside the table `Customers Firstname` 



------------------------------

  select orderID ,
  Customers.firstname as `Customers Firstname` ,
 Customers.Lastname as 'Customers Lastname' ,
 employees.firstname as 'Employees Lastname' , 
 employees.Lastname as 'Employees Lastname' 
 from orders join customers, employees where orders.customerID = Customers.customerID 
 and orders.employeeID = employees.employeeID  and Customers.lastname  like 'Andersen';
 
 # use like instead of = 

-------------------------------

 #-----------------------------------------------------------------------------
  select orderdetails.orderID ,
		 Customers.firstname as `Customers Firstname` ,
         Customers.Lastname as `Customers Lastname` ,
         employees.firstname as `Employees Firstname`, 
         employees.Lastname as `Employees Lastname`,
         orderdetails.OrderDetailID,
         `orderdetails`.`ProductID`,
         `products`.`ProductName`,
         `products`.`SupplierID`,
         `suppliers`.`SupplierName`
 from orders
 join customers, employees , orderdetails , products, suppliers
 where orders.customerID = Customers.customerID 
 and orders.employeeID = employees.employeeID  
 and orders.OrderID = orderdetails.OrderID
 and `orderdetails`.`ProductID` = `products`.`ProductID`
 and `suppliers`.`SupplierID` = `products`.`SupplierID`
 and Customers.lastname  like 'Andersen'
 and products.ProductName like 'Geitost'
 ;#join 5 tables 
 #-------------------------------------------------------------------------------------------
 
 
 
 
 use bargainbuy;
SELECT EmployeeName, Salary 
FROM Employee 
WHERE Salary NOT BETWEEN 2500 AND 4000;

SELECT * FROM Employees  WHERE LastName LIKE  '__a%';
#-----------------------
#Consider the Employee table with the following columns:
#EmployeeID, EmployeeName, Job, HireDate, Salary, Commission, Department
#Write a query to display the names of employees that contain ”M” as First and “L” as third alphabet?

select LastName FROM Employees  WHERE LastName LIKE  'M_L%';
#------------------------------------------------------------------

select  SUM(Salary) AS 'Total Salary Buget' FROM Employee  GROUP BY Department;

select * from Customer ;
create TABLE CustomersBak LIKE Customers; #to make a copy of original table. 
insert into CustomersBak ( select * from Customers); # copy all record from Customers in new  CustomersBak



#--------------------------------------------------
set SQL_SAFE_UPDATES = 0;#for dangeros instruction use safe to 0 
update CustomersBak set country = "USA";  # where contry = "United State of America "
set SQL_SAFE_UPDATES = 1;
#-------------------------
delete from CustomersBak ;

#--------------------------------------------------------------------
update CustomersBak set country = "USA" where customerID = 1 ;
#---------------------------------------------------------------------

#alter -> change structure of the table 
#update -> change data in the table 
#-------------------------
#add one more column in the table 
alter table customers  add column `pass` varchar(45) not null after `Email`;

update customers set pass = concat( LastName, CustomerID );

#RAND() -> retun a number from 0 to 1 

update customers set pass = concat( floor(rand()*1000) ,    char(floor ( 65 + (   rand() * 25 ) ) ), floor( rand() * 1000    ));



select md5( "123") ;  # pasword will be 32 carcters 

update customers set pass =  md5(concat (floor(rand()*1000) ,    char(floor ( 65 + (   rand() * 25 ) ) ), floor( rand() * 1000    )));

select MD5("1234");   #codificate a pasword 

select length(SHA1("1234"));

select SHA2("1234",224);

select SHA1("1234");


select SHA2("1234",224);

select length(SHA2("1234", 512));

select length(SHA2("1234", 256));
set SQL_SAFE_UPDATES = 0;#for dangeros instruction use safe to 0 
update customers set pass = sha2(CONCAT(LastName, CustomerID), 512);
set SQL_SAFE_UPDATES = 1;





insert into customers (lastname, firstName, company, city, country, phone, email, pass )
value ('Azri', 'ali', 'BHCC', 'boston','USA', '222-222-2222', 'ali@gmail.com',sha2(CONCAT(lastname, customerID),512));





update Customers set pass = sha2("1234",512) where customerID = 10001;

select * from customers where email = "ali@gmail.com" and pass = sha2("1234",512);


select * from customers where customerid = 10001; # shou one client by ID 


use  mysql;
 show tables;
 select * from user;
 
 create user `Alli2@localhost` identified by '1234'; 
 
 grant all privileges on bargainbay. * to `Alli2@localhost`; #setup rivileges 
 
 
 grant all privileges on bargainbay. * to `userDonket@localhost`; #setup rivileges


create user `userDonkey`@`localhost` identified by '1234';


 grant select on bargainbay. * to `userDonkey`@`localhost`; 
#-----------------------------------------------------
 use bargainbuy;
 set @bonus_percent = 0.05;
 update products
 set price = price + (Price * @bonus_percent)
 where ProductID = 3;
  #---------------------------------------------------
  
DELIMITER //
create procedure GetAllProducts()
begin 
select * from Products;
end //
DELIMITER ; # changig bakk delimiter for new line 
 call GetAllProducts();
 #---------------------------------------------------------
 
 
   
DELIMITER //
create procedure GetProductsBestPrice(in minPrice DECIMAL (10,2 )) #bold 10 number and 2 decimal points 
begin 
select * from Products where Price >= minPrice; 
end //
DELIMITER ; # changig bakk delimiter for new line 
 call GetProductsBestPrice(1000);
 #---------------------------------------------------------
 
 
 
 DELIMITER //
 
 
 
create procedure CalculaleGroosSail(in UnitPrice DECIMAL  (10,2 ),out GrossPrice Decimal (10,2))
begin 
select  GrossPrice =  UnitPrice = ( UnitPrice * 0.10 ); 
end //
DELIMITER ; # changig bakk delimiter for new line 
 call CalculaleGroosSail(2000, @GrossPrice);
 #---------------------------------------------------------
 select @GrossPrice;
 
 #-------------------------------------------------------------------
delimiter //
create procedure square(in aNumber INT , out aSquare INT)
begin
set aSquare = aNumber * aNumber;
end;
//
DELIMITER ;

call square(5, @aSquare); 

select @aSquare; 

#------------------------------------------------------
#create table users with fields : id , lastname, firstname , email  
 CREATE TABLE Users  ( 
 ID INT PRIMARY KEY AUTO_INCREMENT,
 lastname TEXT, 
 firstname TEXT, 
 email TEXT );
 
 describe users;
 
 
 
 
 #--------------------
 
 DELIMITER //

CREATE PROCEDURE getRandomLastName()
BEGIN
    DECLARE lastName TEXT;
    
    SELECT lastname INTO lastName
    FROM customers
    ORDER BY RAND()
    LIMIT 1;
    
    SELECT lastName AS randomLastName;
END //

DELIMITER ;

call getRandomLastName();

 
 
					 #----------------------------
					 delimiter //
					 CREATE function getRandomLastNameF()  RETURNS TEXT
					 BEGIN 
					 declare aLastname TEXT;
					 
					 SELECT lastname into aLastname from Customers where ID = rand();
					 
					 RETURN @aLastName;
					 END//
					 delimiter ;
					 SELECT getRandomLastNameF();

 #----------------
DELIMITER //
CREATE FUNCTION getRandomLastNameF3() RETURNS TEXT
deterministic
BEGIN
    DECLARE aLastname TEXT;
    SELECT lastname INTO aLastname
    FROM Customers
   where Customerid =  ceil( RAND()*10000) limit 1;
    RETURN aLastname;
END //
DELIMITER ;
SELECT getRandomLastNameF3();
  #----------------Working perfect



 #----------------
DELIMITER //
CREATE FUNCTION getRandomfirstName() RETURNS TEXT
deterministic
BEGIN
    DECLARE aLastname TEXT;
    SELECT firstname INTO aLastname
    FROM Customers
   where Customerid =  ceil( RAND()*10000) limit 1;
    RETURN aLastname;
END //
DELIMITER ;
SELECT getRandomfirstName();
  #----------------Working perfect



#----------------------------------------

 #--------------------
 
 DELIMITER //
CREATE PROCEDURE getRandomLastName()
BEGIN
    DECLARE lastName TEXT;
    SELECT lastname INTO lastName
    FROM customers
    ORDER BY RAND()
    LIMIT 1;
    SELECT lastName AS randomLastName;
END //
DELIMITER ;
call getRandomLastName();
 #-------------------------------------------------

  DELIMITER //
CREATE PROCEDURE getRandomLastName()
BEGIN
    DECLARE lastName TEXT;
    SELECT lastname INTO lastName
    FROM customers
    ORDER BY RAND()
    LIMIT 1;
    SELECT lastName AS randomLastName;
END //
DELIMITER ;
call getRandomLastName();
 #-------------------------------------------------

create database ComerceCompany;
use ComerceCompany;
create table ErrorLogTable( orderID int , ErrorValue varchar (600)) ;

create table OrderDetails ( orderID int, 
                          MembershipTier varchar(25) ,  
                          orderAmount  decimal (10,2),  
                          discount  decimal  (10,2),  

#create table customer1 (id int, lastname varchar(125) , `first name` varchar(54));


#---------------------------------
 DELIMITER //
create procedure CalculateOrderDiscount( in OrderID INT ,
                                         in Membership varchar(25) ,
                                         in OrderAmount decimal (10,2) ,
                                         out discount decimal (10,2) )
                                         
             
BEGIN

IF (Membership = "silver" ) THEN
      IF ( OrderAmount <  50 ) Then
        set discount = OrderAmount < 




# declare Discount INTEGER ;
#parameter orderID int
#membershipTier(warchar)
#orderAmount(DECIMAL)
#orderDetails()
#erorLogTable.
RETURN @Discount;
END //
DELIMITER ;

 
 

 
 call CalculateOrderDiscount( 1234, "silver", 150, @discount);
 select @discount; 
 
 
 
 use bargainbuy;
 
 

create idx_name on employees(last_name);

select * forom employees where last_name = 'Smith';

show index from table_name; #to se how mani index have the table 










 use bargainbuy;

 #----------------
DELIMITER //
CREATE FUNCTION customers_login(   p_username varchar(255) , p_password varchar (255)      )

 RETURNS varchar (50)
 
deterministic
BEGIN
    DECLARE store_password varchar (255) ;
    DECLARE store_lastname varchar (255) ;
    DECLARE store_firstname varchar (255) ;
  #  DECLARE store_message varchar (255) ;
        DECLARE result_message varchar (255) ;
    
    SELECT lastname , firstname , pass INTO  store_lastname,  store_firstname,  store_password 
    FROM Customers
   where email =  p_username;
   
   # Checc if the user exist 
   if  store_password is null then 
       set result_message = 'x';
	else 
    # compare the giveng password 
    if store_password = sha2( p_password , 512) then 
        set result_message = concat ( store_firstname , " " , store_lastname  );
	else 
        set   result_message  = 'x'; 
	end if;
end if;

    RETURN result_message ;
END //
DELIMITER ;



SELECT customers_login( 'jentimanato@gmail.com','123456');




insert into customers (lastname, firstName, company, city, country, phone, email, pass ,SubscriptionDate)
value ('Azri', 'ali', 'BHCC', 'boston','USA', '222-222-2222', 'ali@gmail.com',sha2(CONCAT(lastname, customerID),512),SubscriptionDate );




 use bargainbuy;
insert into customers (lastname, firstName, company, city, country, phone, email, pass, SubscriptionDate )
value ('Anatol', 'Jentim', 'BHCC', 'boston','USA', '222-222-22', 'jent@gmail.com',sha2("123456",512), CURDATE());



update orders set customerid = 1001 where customerid = 20; 

update castumers set pass= sha2("1234",512) where customersid = 20;

select * from users;

 select * from products;
 
 select * from orders; 
 
 
 select * from  customers where lastname = 'Anatoli'; 
 
  
 select * from  customers where customerID = 10009; 
 
   
 select * from  customers
 where customerID = 10008; 
DELETE FROM customers
WHERE customerID = 10008;


 select * from  customers
 where customerID = 10001; 
DELETE FROM customers
WHERE customerID = 10001;





 use bargainbuy;
 select CustomerID,FirstName,lastName, Company,City, Country , Phone,  Email  , SubscriptionDate  from customers;





#-------------------------------------------
USE bargainbuy;

DELIMITER //

CREATE FUNCTION CountCustomersByYear(input_year INT)
RETURNS INT
READS SQL DATA
BEGIN
    DECLARE customer_count INT;
    SELECT COUNT(*) INTO customer_count
    FROM customers
    WHERE YEAR(SubscriptionDate) = input_year;
    RETURN customer_count;
END //

DELIMITER ;
#-------------------------------------------categories




 select * from  orders;
 #-----------------------------------
 
 USE bargainbuy;

DELIMITER //

CREATE PROCEDURE CountTodayOrders()
BEGIN
    SELECT OrderID, CustomerID, EmployeeID, ShipperID, OrderDate
    FROM orders
    WHERE DATE(OrderDate) = CURDATE();
END //

DELIMITER ;



 #--------------------------------
USE bargainbuy;
DELIMITER //
CREATE PROCEDURE CountTodayOrdersReturnInt()
  BEGIN
    SELECT COUNT(*) AS order_count
    FROM orders
    WHERE DATE(OrderDate) = CURDATE();
  END //
DELIMITER ;
#------------------------------------








DELIMITER //
CREATE FUNCTION CountOrdersByCustomerAndProduct(cust_lastname VARCHAR(255), prod_name VARCHAR(255))
RETURNS INT
READS SQL DATA
BEGIN
    DECLARE order_count INT;
    SELECT COUNT(*) INTO order_count
    FROM orders
    JOIN customers ON orders.customerID = customers.customerID
    JOIN orderdetails ON orders.OrderID = orderdetails.OrderID
    JOIN products ON orderdetails.ProductID = products.ProductID
    WHERE customers.lastname LIKE cust_lastname AND products.ProductName LIKE prod_name;
    RETURN order_count;
END //
DELIMITER ;











DELIMITER //

CREATE PROCEDURE GetTotalSalesByCustomer(
    IN cust_lastname VARCHAR(255), 
    IN start_date DATE, 
    IN end_date DATE
)
BEGIN
    SELECT 
        Customers.firstname AS 'Customer Firstname',
        Customers.lastname AS 'Customer Lastname',
        SUM(orderdetails.Quantity * products.Price) AS 'Total Sales'
    FROM orders
    JOIN customers ON orders.customerID = customers.customerID
    JOIN orderdetails ON orders.OrderID = orderdetails.OrderID
    JOIN products ON orderdetails.ProductID = products.ProductID
    WHERE customers.lastname = cust_lastname
      AND orders.OrderDate BETWEEN start_date AND end_date
    GROUP BY customers.customerID;
END //

DELIMITER ;





DELIMITER //

CREATE PROCEDURE getRandomLastName()
BEGIN
    SELECT lastname 
    FROM customers 
    ORDER BY RAND() 
    LIMIT 1;
END //

DELIMITER ;







DELIMITER //

CREATE PROCEDURE getRandomLastNameDetail()
BEGIN
    SELECT CustomerID, FirstName, LastName, Company, City, Country, Phone, Email, SubscriptionDate 
    FROM customers 
    ORDER BY RAND() 
    LIMIT 1;
END //

DELIMITER ;










DELIMITER //

CREATE FUNCTION GetCustomerOrderCount(cust_lastname VARCHAR(255))
RETURNS INT
READS SQL DATA
BEGIN
    DECLARE order_count INT;
    SELECT COUNT(*) INTO order_count
    FROM orders
    JOIN customers ON orders.customerID = customers.customerID
    WHERE customers.lastname = cust_lastname;
    RETURN order_count;
END //

DELIMITER ;








DELIMITER //

CREATE PROCEDURE getEmployeeLastNamesByPattern(IN pattern VARCHAR(255))
BEGIN
    SELECT LastName 
    FROM Employees 
    WHERE LastName LIKE pattern;
END //

DELIMITER ;





DELIMITER //

CREATE PROCEDURE getRandomFirstNameDetail()
BEGIN
    SELECT CustomerID, FirstName, LastName, Company, City, Country, Phone, Email, SubscriptionDate 
    FROM customers 
    ORDER BY RAND() 
    LIMIT 1;
END //

DELIMITER ;

#-------------------------------------

DELIMITER //

CREATE PROCEDURE getRandomLastNameDetail()
BEGIN
    SELECT CustomerID, FirstName, LastName, Company, City, Country, Phone, Email, SubscriptionDate 
    FROM customers 
    ORDER BY RAND() 
    LIMIT 1;
END //

DELIMITER ;








