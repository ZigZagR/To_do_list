# C To-Do List

A simple, terminal-based To-Do List application built in C. Designed for simple task management.

## Features

* **1. Add Task:** Create tasks with a description and a priority level.
* **2. Update Task:** Modify the description, priority, or completion status.
* **3. Delete Task:** Remove tasks by their index (automatically reorders the list).
* **4. Display Tasks:** View all current tasks with formatted status and priority.
* **5. Complete Task:** Quickly mark a selected task as finished.
* **6. Auto-Save/Load:** Data persists in a `tasks.txt` file, so your list is ready whenever you return.

---

## Running It

### Prerequisites
You need a C compiler (like `gcc`) installed.

### Compilation
Open your terminal in the project directory and run:

```bash
gcc main.c -o todo.exe