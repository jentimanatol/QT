# TextFinder Project 
 
## Overview 
The TextFinder project is a Qt application that allows users to search for specific text within a larger body of text. This project demonstrates the use of Qt for GUI development and basic text processing in C++. It's a simple yet powerful tool that showcases the integration of various Qt widgets and functionalities. 
 
## Project Structure 
\``` 
TextFinder.pro 
main.cpp 
mainwindow.cpp 
mainwindow.h 
ui_mainwindow.h 
mainwindow.ui 
\``` 
 
## Classes and Files 
 
### MainWindow Class 
- **File Name:** `mainwindow.h`, `mainwindow.cpp` 
- **Description:** Represents the main window of the application with functionalities for text searching. 
- **Methods:** 
  - `MainWindow(QWidget *parent = nullptr)`: Constructor to initialize the main window. 
  - `~MainWindow()`: Destructor to clean up resources. 
  - `void on_findButton_clicked()`: Slot function to handle the search button click event. 
 
### Ui_MainWindow Class 
- **File Name:** `ui_mainwindow.h` 
- **Description:** Represents the user interface elements of the main window. 
- **Attributes:** 
  - `QTextEdit *textEdit`: Widget for displaying and editing the main text. 
  - `QLineEdit *lineEdit`: Widget for entering the search text. 
  - `QPushButton *findButton`: Button to initiate the search. 
 
### Main File 
- **File Name:** `main.cpp` 
- **Description:** Entry point of the application. Initializes and displays the main window. 
 
### Qt Designer File 
- **File Name:** `mainwindow.ui` 
- **Description:** Defines the layout and widgets for the main window. 
- **Widgets:** 
  - `QTextEdit` for displaying and editing the main text (object name: `textEdit`) 
  - `QLineEdit` for entering the search text (object name: `lineEdit`) 
  - `QPushButton` for initiating the search (object name: `findButton`) 
 
## Interconnections 
- **MainWindow** uses **Ui_MainWindow** to access and manage the user interface elements. 
- **Ui_MainWindow** contains the user interface elements such as `QTextEdit`, `QLineEdit`, and `QPushButton`. 
 
## How to Run the Project 
1. **Clone the Repository:** 
  \```sh 
  git clone https://github.com/jentimanatol/QT/tree/main/TextFinder 
  cd TextFinder 
  \``` 
 
2. **Open the Project in Qt Creator:** 
  - Open `TextFinder.pro` in Qt Creator. 
 
3. **Build and Run the Project:** 
  - Click on the "Run" button in Qt Creator to build and run the project. 
 
## Features 
- **Text Search:** Users can search for specific text within a larger body of text. 
- **Qt GUI:** The application uses Qt for the graphical user interface. 
- **Simple and Intuitive:** The user interface is simple and easy to use. 
 
## Screenshots 
![Main Window](https://github.com/jentimanatol/QT/blob/main/TextFinder/AnatolieTextFinder/mainWindow.jpg) 
![Search Result - Text Found](https://github.com/jentimanatol/QT/blob/main/TextFinder/AnatolieTextFinder/SearchResultTextFound.jpg) 
![Search Result - Text Not Found](https://github.com/jentimanatol/QT/blob/main/TextFinder/AnatolieTextFinder/SearchResultTextFound.jpg) 
 
## UML Diagram 
\```plantuml 
@startuml 
class MainWindow { 
- Ui::MainWindow *ui 
+ MainWindow(QWidget *parent = nullptr) 
+ ~MainWindow() 
+ void on_findButton_clicked() 
} 
 
class Ui_MainWindow { 
- QTextEdit *textEdit 
- QLineEdit *lineEdit 
- QPushButton *findButton 
} 
 
MainWindow "1" *-- "1" Ui_MainWindow : uses 
@enduml 
\``` 
 
## License 
This project is licensed under the MIT License - see the LICENSE file for details. 
 
## Acknowledgements 
- Qt for providing the framework for GUI development. 
- The authors of the C++ libraries used in this project. 
 
## Contact 
If you have any questions or suggestions, feel free to contact me at [your-email@example.com](mailto:your-email@example.com). 
