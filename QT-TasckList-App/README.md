Here is a detailed `README.md` file for your To-Do List Qt application:

---

# To-Do List Application

This application is a feature-rich and user-friendly to-do list built using Qt. It allows users to manage tasks effectively, providing functionality to add, edit, complete, and remove tasks. The application dynamically updates the task status to display completed and pending tasks.

---

## Features

### Main Features
- **Add Tasks**: Create new tasks easily with a customizable name.
- **Edit Tasks**: Update the task name if needed.
- **Mark as Complete**: Strike out tasks to indicate completion.
- **Remove Tasks**: Delete tasks that are no longer needed.
- **Dynamic Task Status**: Real-time updates to the count of completed and pending tasks.

### User Interface
- Clean and intuitive layout.
- Uses checkboxes for marking task completion.
- Buttons for editing and removing tasks integrated directly within each task item.

---

## Installation and Setup

### Prerequisites
1. **Qt Development Environment**:
   - Qt 6.8.1 or later.
   - MinGW 64-bit or MSVC 2022 64-bit compiler.
2. **C++ Compiler**:
   - Ensure MinGW 13.1 or MSVC is properly installed.
3. **CMake or Build Toolchain** (optional if using `qmake`).

### Setting Up the Project
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-repo/todo-list-app.git
   cd todo-list-app
   ```

2. **Open the Project in Qt Creator**:
   - Launch **Qt Creator**.
   - Open the `ToDoListApp.pro` file.

3. **Build the Project**:
   - Select **Build > Run qmake**.
   - Select **Build > Rebuild All**.

4. **Run the Application**:
   - Press `Ctrl + R` or navigate to **Run > Start Debugging**.

---

## Usage

### Adding Tasks
1. Click the **Add Task** button in the toolbar.
2. Enter the task name in the dialog box.
3. Confirm the input. The new task appears in the task list.

### Editing Tasks
1. Locate the task in the list.
2. Click the **Edit** button associated with the task.
3. Modify the task name in the dialog box and save the changes.

### Marking Tasks as Complete
1. Check the box next to the task name.
2. The task name will be struck through, indicating its completion.

### Removing Tasks
1. Locate the task to remove.
2. Click the **Remove** button.
3. The task will be deleted from the list.

---

## Code Structure

### Main Components
- **MainWindow**:
  - Manages the layout, task addition, task removal, and status updates.
- **Task**:
  - Represents an individual task with features like marking as complete, renaming, and removal.

---

### Code Details

#### `MainWindow`
The `MainWindow` class serves as the primary interface and manages the overall application behavior.

**Key Functions**:
- `addTask()`: Creates a new `Task` object and adds it to the task list.
- `removeTask(Task* task)`: Removes a task and updates the status.
- `taskStatusChanged(Task* task)`: Handles changes in task completion status.
- `updateStatus()`: Updates the display to show the count of completed and pending tasks.

---

#### `Task`
The `Task` class defines the behavior of individual tasks in the list.

**Key Functions**:
- `setName(const QString& name)`: Sets the task name.
- `isCompleted() const`: Returns whether the task is marked as complete.
- `rename()`: Opens a dialog box to edit the task name.
- `checked(bool checked)`: Updates the UI to strike through completed tasks.

**Signals**:
- `removed(Task* task)`: Emitted when the task is removed.
- `statusChanged(Task* task)`: Emitted when the task’s completion status changes.

---

## User Interface Design

### `MainWindow.ui`
- A **toolbar** at the top with:
  - **Status Label**: Displays the count of pending and completed tasks.
  - **Add Task Button**: Opens a dialog to add a new task.
- A **task layout** below for dynamically displaying task widgets.

### `Task.ui`
- **CheckBox**: Marks the task as complete or incomplete.
- **Edit Button**: Opens a dialog to rename the task.
- **Remove Button**: Deletes the task from the list.

---

## Environment Details

- **Operating System**: Windows 10/11 (64-bit) or Linux.
- **Development Tools**: Qt Creator 6.8.1, MinGW 13.1 or MSVC 2022.
- **Dependencies**: None outside the Qt framework.

---

## Future Enhancements

1. **Task Persistence**:
   - Save tasks to a local file or database for future sessions.
2. **Task Sorting**:
   - Allow sorting tasks by name, creation date, or status.
3. **Dark Mode**:
   - Add a toggle for dark mode in the user interface.
4. **Priority Levels**:
   - Introduce prioritization with visual indicators for tasks.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Contributing

We welcome contributions to enhance this application. To contribute:
1. Fork the repository.
2. Create a branch for your feature or bug fix.
3. Submit a pull request with a detailed description of your changes.

---

Let me know if you need further customizations!