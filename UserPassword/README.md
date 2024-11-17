# UserPassword Project 
 
## Overview 
The UserPassword project is a Qt application that provides a secure login and registration system. Users can log in or register with encrypted usernames and passwords, which are stored in a text file. This project demonstrates the use of Qt for GUI development, file handling, and basic encryption techniques in C++. 
 
## Project Structure 
\``` 
UserPassword.pro 
main.cpp 
loginscreen.cpp 
loginscreen.h 
user.cpp 
user.h 
superuser.cpp 
superuser.h 
encryption.cpp 
encryption.h 
loginscreen.ui 
\``` 
 
## Classes and Files 
 
### User Class 
- **File Name:** `user.h`, `user.cpp` 
- **Description:** Represents a user with a username and password. 
- **Methods:** 
  - `std::string getUsername() const` 
  - `std::string getPassword() const` 
 
### SuperUser Class 
- **File Name:** `superuser.h`, `superuser.cpp` 
- **Description:** Inherits from `User` and represents a superuser with additional functionalities. 
- **Methods:** 
 
### Encryption Functions 
- **File Name:** `encryption.h`, `encryption.cpp` 
- **Description:** Provides simple encryption and decryption methods. 
- **Methods:** 
 
### LoginScreen Class 
- **File Name:** `loginscreen.h`, `loginscreen.cpp` 
- **Description:** Represents the login screen with functionalities for logging in and registering users. 
- **Methods:** 
  - `LoginScreen(QWidget *parent = nullptr)` 
  - `~LoginScreen()` 
  - `void onLoginClicked()` 
  - `void onRegisterClicked()` 
 
### Main File 
- **File Name:** `main.cpp` 
- **Description:** Entry point of the application. Initializes and displays the login screen. 
 
### Qt Designer File 
- **File Name:** `loginscreen.ui` 
- **Description:** Defines the layout and widgets for the login screen. 
- **Widgets:** 
  - `QLabel` for "Username:" 
  - `QLineEdit` for entering the username (object name: `usernameEdit`) 
  - `QLabel` for "Password:" 
  - `QLineEdit` for entering the password (object name: `passwordEdit`, `echoMode` set to `Password`) 
  - `QPushButton` for "Login" (object name: `loginButton`) 
  - `QPushButton` for "Register" (object name: `registerButton`) 
 
## Interconnections 
- **LoginScreen** connects the `loginButton` and `registerButton` to the `onLoginClicked()` and `onRegisterClicked()` slots, respectively. 
- **Encryption Functions** are used in `LoginScreen` to encrypt and decrypt usernames and passwords before storing/retrieving data from the text file. 
- **User** and **SuperUser** classes are used to represent and manage user data. 
 
## How to Run the Project 
1. **Clone the Repository:** 
  \```sh 
  git clone https://github.com/jentimanatol/QT/tree/main/UserPassword/UserPassword 
  cd UserPassword 
  \``` 
 
2. **Open the Project in Qt Creator:** 
  - Open `UserPassword.pro` in Qt Creator. 
 
3. **Build and Run the Project:** 
  - Click on the "Run" button in Qt Creator to build and run the project. 
 
## Features 
- **Secure Login and Registration:** Users can log in or register with encrypted usernames and passwords. 
- **File Handling:** User data is stored in a text file. 
- **Qt GUI:** The application uses Qt for the graphical user interface. 
- **Encryption:** Simple encryption and decryption methods are used to secure user data. 
 
## Screenshots 
![Login Screen](https://github.com/jentimanatol/QT/blob/main/UserPassword/UserPassword/LoginScreen.jpg) 
![Registration Screen](https://github.com/jentimanatol/QT/blob/main/UserPassword/UserPassword/Register.jpg) 
 
## Diagrams 
### Project Structure 
![Project Structure](https://github.com/jentimanatol/QT/blob/main/UserPassword/UserPassword/Project%20Structure.txt) 
### UML Diagram 
![UML Diagram](https://github.com/jentimanatol/QT/blob/main/UserPassword/UserPassword/Untitled%20Diagram.drawio.png) 
 
## License 
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details. 
 
## Acknowledgements 
- Qt for providing the framework for GUI development. 
- The authors of the C++ libraries used in this project. 
 
## Contact 
If you have any questions or suggestions, feel free to contact me at [https://github.com/jentimanatol](https://github.com/jentimanatol). 
