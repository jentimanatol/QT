#Readme 
#Run the code in the SQL enviroment 
# Change the  root Loginand  Pass in the QT enviroment file mainwindow.cpp
#   db.setHostName("localhost");
 #   db.setDatabaseName("usermanagement");
 #   db.setUserName("root");
 #   db.setPassword("admin");
#     db.setPort(3306);
#-----------------------------
#install mysql-connector-c++-9.1.0-winx64.msi or  mysql-connector-c-6.1.11-winx64.msi if have connection problem 

CREATE DATABASE UserManagement;
USE UserManagement;


CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    email VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL
);


INSERT INTO users (email, password_hash) VALUES ('user@example.com', 'hashed_password');
INSERT INTO users (email, password_hash) VALUES ('Anatolie@example.com', '1234');
INSERT INTO users (email, password_hash) VALUES ('a', 'a');


select *from users;

DESCRIBE users;

UPDATE users SET password_hash = SHA2('1234', 256) WHERE email = 'a';

INSERT INTO users (email, password_hash) VALUES ('z',  SHA2('z', 256));

ALTER TABLE users ADD COLUMN username VARCHAR(255);




CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL
);





CREATE DATABASE usermanagement;

USE usermanagement;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(100) NOT NULL,
    password VARCHAR(100) NOT NULL
);

-- Add some test users:
INSERT INTO users (username, password) VALUES ('admin', 'password123');


select * from users;










#uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu
-- Create the users table
CREATE TABLE users (
    userID INT AUTO_INCREMENT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    City VARCHAR(50),
    Country VARCHAR(50),
    Phone VARCHAR(15),
    Email VARCHAR(100) UNIQUE NOT NULL,
    pass VARCHAR(255) NOT NULL
);

-- Insert some sample data
INSERT INTO users (FirstName, LastName, City, Country, Phone, Email, pass) 
VALUES 
('John', 'Doe', 'New York', 'USA', '1234567890', 'john.doe@example.com', SHA2('password123', 256)),
('Jane', 'Smith', 'Los Angeles', 'USA', '0987654321', 'jane.smith@example.com', SHA2('password456', 256));

#uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu




-- Insert some sample data
INSERT INTO users (FirstName, LastName, City, Country, Phone, Email, pass) 
VALUES 
('Anatolie', 'Jentimir', 'Boston', 'USA', '2234567890', 'ja@bhcc.edu', SHA2('1234', 256)),
('george', 'washinghton', 'California', 'USA', '0187654321', 'george@gmail.com', SHA2('1234', 256));

-- Insert some sample data
INSERT INTO users (FirstName, LastName, City, Country, Phone, Email, pass) 
VALUES 
('Anatol', 'Jentim', 'Boston', 'USUserLoginProcedureUserLoginProcedureA', '2234567891', 'ja@', SHA2('1234', 256));


-- Insert some sample data
INSERT INTO users (FirstName, LastName, City, Country, Phone, Email, pass) 
VALUES 
('Anatn', 'Jent', 'Boston', 'USA', '1234267891', 'a', SHA2('a', 256));


DELETE FROM Users WHERE userID = 6;

select * from users;





#rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
-- Create procedure for user registration
DELIMITER //
CREATE PROCEDURE RegisterUser (
    IN p_firstName VARCHAR(50),
    IN p_lastName VARCHAR(50),
    IN p_city VARCHAR(50),
    IN p_country VARCHAR(50),
    IN p_phone VARCHAR(15),
    IN p_email VARCHAR(100),
    IN p_password VARCHAR(255),
    OUT p_userID INT
)
BEGIN
    -- Insert into users table
    INSERT INTO users (FirstName, LastName, City, Country, Phone, Email, pass) 
    VALUES (p_firstName, p_lastName, p_city, p_country, p_phone, p_email, SHA2(p_password, 256));
    
    -- Get the userID of the newly inserted user
    SET p_userID = LAST_INSERT_ID();
END //
DELIMITER ;
#rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr









#llllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll
-- Create procedure for user login
DELIMITER //
CREATE PROCEDURE UserLoginProcedure (
    IN p_email VARCHAR(100),
    IN p_password VARCHAR(255),
    OUT p_userID INT
)
BEGIN
    DECLARE temp_password VARCHAR(255);

    -- Hash the input password
    SET temp_password = SHA2(p_password, 256);

    -- Check if the email and hashed password match an entry in the users table
    SELECT userID
    INTO p_userID
    FROM users
    WHERE Email = p_email AND pass = temp_password
    LIMIT 1;

    -- If no matching entry found, set userID to NULL
    IF p_userID IS NULL THEN
        SET p_userID = NULL;
    END IF;
END //
DELIMITER ;

#lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll



#ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
-- Create procedure for resetting password
DELIMITER //
CREATE PROCEDURE ForgotPassword (
    IN p_email VARCHAR(100),
    IN p_newPassword VARCHAR(255)
)
BEGIN
    UPDATE users
    SET pass = SHA2(p_newPassword, 256)
    WHERE Email = p_email;
END //
DELIMITER ;
#fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff



#iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii
-- Create IncomeSource table (assuming it exists)
CREATE TABLE IF NOT EXISTS IncomeSource (
    sourceID INT AUTO_INCREMENT PRIMARY KEY,
    category VARCHAR(50) NOT NULL
);

-- Create IncomeEntry table with userID foreign key
CREATE TABLE IF NOT EXISTS IncomeEntry (
    incomeID INT AUTO_INCREMENT PRIMARY KEY,
    userID INT,
    sourceID INT,
    amount DECIMAL(10, 2) NOT NULL,
    date DATE NOT NULL,
    FOREIGN KEY (userID) REFERENCES users(userID),
    FOREIGN KEY (sourceID) REFERENCES IncomeSource(sourceID)
);

-- Insert predefined categories into IncomeSource table
INSERT INTO IncomeSource (category) VALUES 
('Salary'),
('Freelance'),
('Investments');
#iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii






#eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
CREATE TABLE IF NOT EXISTS ExpenseCategory (
    categoryID INT AUTO_INCREMENT PRIMARY KEY,
    category VARCHAR(50) NOT NULL,
    subcategory VARCHAR(50) NOT NULL
);

#
-- Create ExpenseEntry table with userID foreign key
CREATE TABLE ExpenseEntry (
    expenseID INT AUTO_INCREMENT PRIMARY KEY,
    userID INT,
    categoryID INT,
    amount DECIMAL(10, 2) NOT NULL,
    date DATE NOT NULL,
    FOREIGN KEY (userID) REFERENCES Users(userID),
    FOREIGN KEY (categoryID) REFERENCES ExpenseCategory(categoryID)
);

#---------Subcatedory make it staticck 
-- Insert predefined categories and subcategories
INSERT INTO ExpenseCategory (category, subcategory) VALUES 
('Housing', 'Rent'),
('Housing', 'Utilities'),
('Transportation', 'Public Transport'),
('Transportation', 'Fuel'),
('Food', 'Groceries'),
('Food', 'Dining Out'),
('Entertainment', 'Movies'),
('Entertainment', 'Games'),
('Health', 'Medical'),
('Health', 'Fitness');
#eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee


SELECT * FROM users;
SELECT * FROM IncomeEntry;
SELECT * FROM ExpenseEntry;

SELECT category FROM IncomeSource;
SELECT category, subcategory FROM ExpenseCategory;





#CALL `usermanagement`.`UserLoginProcedure`(<{IN p_email VARCHAR(100)}>, <{IN p_password VARCHAR(255)}>, <{OUT p_userID INT}>);








































































# save for late improvement blobal economy total of all users 



#Mace it simple  no users level qt complication 
 -- Create the User table
CREATE TABLE User (
    userID INT AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(50) NOT NULL,
    lastname VARCHAR(50) NOT NULL,
    position ENUM('admin', 'user') NOT NULL
);

-- Create the UserLogin table
CREATE TABLE UserLogin (
    loginID INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    accessLevel INT NOT NULL,
    userID INT,
    FOREIGN KEY (userID) REFERENCES User(userID)
);

-- Insert sample data into User table
INSERT INTO User (firstname, lastname, position) VALUES ('John', 'Doe', 'admin');
INSERT INTO User (firstname, lastname, position) VALUES ('Jane', 'Smith', 'user');

-- Insert sample data into UserLogin table
INSERT INTO UserLogin (username, password, accessLevel, userID) 
VALUES ('adminUser', SHA2('adminPass123', 256), 1, 1);
INSERT INTO UserLogin (username, password, accessLevel, userID)
VALUES ('regularUser', SHA2('userPass123', 256), 2, 2);
#
#

#
#
#
#
#
#
#
#





























CREATE TABLE User (
    userID INT AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(50) NOT NULL,
    lastname VARCHAR(50) NOT NULL,
    position VARCHAR(50) NOT NULL
);
CREATE TABLE UserLogin (
    loginID INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    accessLevel INT NOT NULL,
    userID INT,
    FOREIGN KEY (userID) REFERENCES User(userID)
);
INSERT INTO User (firstname, lastname, position) VALUES ('John', 'Doe', 'Developer');
INSERT INTO UserLogin (username, password, accessLevel, userID) 
VALUES ('newUser', SHA2('password123', 256), 1, 1);
#-------------------------------Show db table ------------------------------------------
SELECT User.userID, User.firstname, User.lastname, User.position, 
       UserLogin.loginID, UserLogin.username, UserLogin.accessLevel
FROM User
INNER JOIN UserLogin ON User.userID = UserLogin.userID;
#--------------------------------------------------------------------
SHOW VARIABLES LIKE 'have_openssl';
SHOW VARIABLES LIKE '%ssl%';  # connection error troule shurting 
#Log procedure 
DELIMITER //
CREATE PROCEDURE UserLoginProcedure (
    IN p_username VARCHAR(50),
    IN p_password VARCHAR(255),
    OUT p_accessLevel INT,
    OUT p_userID INT
)
BEGIN
    DECLARE temp_password VARCHAR(255);

    -- Hash the input password
    SET temp_password = SHA2(p_password, 256);

    -- Check if the username and hashed password match an entry in the UserLogin table
    SELECT accessLevel, userID
    INTO p_accessLevel, p_userID
    FROM UserLogin
    WHERE username = p_username AND password = temp_password
    LIMIT 1;

    -- If no matching entry found, set accessLevel and userID to NULL
    IF p_userID IS NULL THEN
        SET p_accessLevel = NULL;
        SET p_userID = NULL;
    END IF;
END //

DELIMITER ;
#test log procedure 
CALL UserLoginProcedure('username', 'password123', @accessLevel, @userID);
SELECT @accessLevel, @userID;



#------------------------------------Registry button ---------------------

DELIMITER //

CREATE PROCEDURE RegisterUser (
    IN p_firstName VARCHAR(50),
    IN p_lastName VARCHAR(50),
    IN p_username VARCHAR(50),
    IN p_password VARCHAR(255),
    IN p_position VARCHAR(50),
    OUT p_userID INT
)
BEGIN
    DECLARE temp_userID INT;

    -- Insert into User table
    INSERT INTO User (firstname, lastname, position) 
    VALUES (p_firstName, p_lastName, p_position);
    
    -- Get the userID of the newly inserted user
    SET temp_userID = LAST_INSERT_ID();
    
    -- Insert into UserLogin table with access level set to 1
    INSERT INTO UserLogin (username, password, accessLevel, userID) 
    VALUES (p_username, SHA2(p_password, 256), 1, temp_userID);
    
    -- Set the output userID
    SET p_userID = temp_userID;
END //

DELIMITER ;
#----------------------------------------------


#test procedure registry 
SET @userID = 0;
SET @position = 'User';
CALL RegisterUser('Bob1', 'Johnson', 'Bob1','1234',@position, @userID);

-- Retrieve the new user ID 
SELECT @userID;

select *from userlogin;


#---------------------------------------------------------


#-------Forgot pasword procedure  trust remote  server only 
DELIMITER //

CREATE PROCEDURE ForgotPassword (
    IN p_username VARCHAR(50),
    IN p_newPassword VARCHAR(255)
)
BEGIN
    UPDATE UserLogin
    SET password = SHA2(p_newPassword, 256)
    WHERE username = p_username;
END //

DELIMITER ;
#-----------------------------------------------------------------
#
#
#
#
#
##
#









