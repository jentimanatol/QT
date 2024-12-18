# Terminal Cleanup Script

## Overview
This script is a batch file designed to clean directories by removing unwanted files while preserving essential ones based on predefined extensions. It's a great tool for managing clutter in development or project directories, offering a simple and efficient way to organize your workspace.

### Purpose
The main objectives of this script are:
- **Automation:** Quickly delete unnecessary files without manual effort.
- **Preservation:** Ensure critical files like source code, scripts, and configurations remain untouched.
- **Simplicity:** Provide a straightforward method for directory cleanup.

---

## How to Use the Script

### Step 1: Save the Script
1. Open Notepad or your favorite text editor.
2. Copy the batch file code (provided below).
3. Save the file with a `.bat` extension, e.g., `cleanup.bat`.

### Step 2: Place the Script
Move the `cleanup.bat` file to the directory you want to clean.

### Step 3: Execute the Script
- **Via Double-Click:** Double-click the `.bat` file in Windows Explorer.
- **Via Command Prompt:**  
  1. Open Command Prompt (`cmd`).
  2. Navigate to the directory where the script is located using the `cd` command:
     ```cmd
     cd path\to\directory
     ```
  3. Run the script by typing:
     ```cmd
     cleanup.bat
     ```

### Step 4: Review the Cleanup
The script will:
- Display the files it deletes.
- Confirm completion of the cleanup process.
- Keep the Command Prompt window open for further commands.

---

## Code Explanation

### Full Script
```batch
@echo off
cd /d "%~dp0"

REM Loop through all files in the directory
for %%f in (*) do (
    REM Check if the file does not end with the specified extensions and is not .gitignore or a .bat file
    if /I not "%%~xf"==".cpp" if /I not "%%~xf"==".h" if /I not "%%~xf"==".pro" if /I not "%%~xf"==".ui" if /I not "%%~xf"==".bat" if /I "%%~nxf" neq ".gitignore" (
        echo Deleting file: %%f
        del "%%f"
    )
)

echo Deletion completed!
cmd
```

### Key Sections

#### Initialization
```batch
@echo off
cd /d "%~dp0"
```
- **`@echo off`:** Suppresses the display of commands being executed for a cleaner output.
- **`cd /d "%~dp0"`:** Sets the working directory to the location of the script.

#### File Processing
```batch
for %%f in (*) do (
    if /I not "%%~xf"==".cpp" if /I not "%%~xf"==".h" if /I not "%%~xf"==".pro" if /I not "%%~xf"==".ui" if /I not "%%~xf"==".bat" if /I "%%~nxf" neq ".gitignore" (
        echo Deleting file: %%f
        del "%%f"
    )
)
```
- **`for %%f in (*)`:** Loops through all files in the directory.
- **Conditions:** Exclude files with the specified extensions (.cpp, .h, .pro, .ui, .bat, .gitignore).
- **Commands:**
  - **`echo Deleting file: %%f`:** Displays the name of each file being deleted.
  - **`del "%%f"`:** Deletes the file.

#### Completion
```batch
echo Deletion completed!
cmd
```
- **`echo Deletion completed!`:** Displays a confirmation message.
- **`cmd`:** Keeps the terminal open after execution.

---

## Features
- **Selective Cleanup:** Deletes unwanted files while retaining essential ones.
- **User Feedback:** Displays each file being deleted for transparency.
- **Customizable:** Easily modify file extensions and conditions to suit your needs.

---

## Practical Use Cases
1. **Development Environments:**
   - Quickly clean up build artifacts, logs, and temporary files.

2. **Project Organization:**
   - Remove unrelated files before archiving or sharing a project.

3. **Shared Directories:**
   - Ensure that only necessary files are retained in collaborative workspaces.

---

## Customization
To add or remove file types to exclude from deletion, modify the `if` condition. For example, to exclude `.txt` files, add:
```batch
if /I not "%%~xf"==".txt"
```

To delete specific file types only, replace the `if` block with:
```batch
if /I "%%~xf"==".log" (
    echo Deleting log file: %%f
    del "%%f"
)
```

---

## Learning Points
This script is an excellent example of how simple batch scripts can:
- Automate repetitive tasks.
- Be customized for various use cases.
- Provide clear and interactive user feedback.

---

Happy scripting! This terminal-based cleanup tool will help keep your directories organized and your projects clutter-free.



_Not protected by copyright, may be used for its intended purpose._  
_Author: Anatolie Jentimir._

