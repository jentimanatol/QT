#Run the code in the SQL enviroment 
# Shange the  root Loginand  Pass in the QT enviroment 
CREATE DATABASE UserManagement;
USE UserManagement;
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


-- Create IncomeEntry table
CREATE TABLE IncomeEntry (
    incomeID INT AUTO_INCREMENT PRIMARY KEY,
    userID INT,
    source VARCHAR(100) NOT NULL,
    amount DECIMAL(10, 2) NOT NULL,
    date DATE NOT NULL,
    FOREIGN KEY (userID) REFERENCES User(userID)
);

-- Create ExpenseEntry table
CREATE TABLE ExpenseEntry (
    expenseID INT AUTO_INCREMENT PRIMARY KEY,
    userID INT,
    category VARCHAR(50) NOT NULL,
    subcategory VARCHAR(50) NOT NULL,
    amount DECIMAL(10, 2) NOT NULL,
    date DATE NOT NULL,
    FOREIGN KEY (userID) REFERENCES User(userID)
);
