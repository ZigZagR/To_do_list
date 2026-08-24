# Antigravity Code & Feature Review: To-Do List Application

## Overview
This review focuses on expanding the current To-Do list application to make it highly practical for daily student use. While the current implementation provides a solid foundation for managing generic tasks, students have specific needs, such as tracking deadlines, categorizing assignments by class, and managing varied task states.

Below are proposed functionality improvements to elevate this simple To-Do app into a powerful student planner.

---

## Proposed Functional Improvements (School & Daily Use Focus)

### 1. **Due Dates and Deadlines**
**Problem:** Students live by deadlines. A priority system (1-5) is helpful, but knowing *when* a task is due is critical for time management.
**Improvement:** 
- Add a `due_date` field (e.g., a string `YYYY-MM-DD` or a struct representing date and time) to the `Task` structure.
- **Benefit:** Allows students to see exactly how much time they have left for assignments, projects, or studying for exams.

### 2. **Course/Subject Categorization**
**Problem:** A monolithic list of tasks can become overwhelming. Mixing a "Calculus Homework" with "Buy Groceries" makes it hard to focus on specific study sessions.
**Improvement:** 
- Add a `subject` or `category` string field to the `Task` structure (e.g., "Math", "History", "Personal").
- **Benefit:** Students can organize their work by class, making it easier to plan study blocks and ensure no subject is neglected.

### 3. **Enhanced Task Status (In Progress)**
**Problem:** The current system only supports "Completed" (1) and "Not Completed" (0). Many school projects take days or weeks.
**Improvement:** 
- Change `completed` to a `status` enum: `TODO`, `IN_PROGRESS`, `DONE`.
- **Benefit:** Students can track ongoing assignments (like writing an essay or reading a book) without feeling like they haven't accomplished anything yet.

### 4. **Sorting and Filtering**
**Problem:** As the semester progresses, the list of tasks will grow. Finding specific tasks becomes tedious.
**Improvement:** 
- Implement functions to sort the displayed tasks by **Due Date** (most urgent first) or by **Priority**.
- Implement filtering options to display only tasks for a specific `subject` or tasks that are currently `IN_PROGRESS`.
- **Benefit:** Drastically improves navigation and helps students prioritize their immediate workload.

### 5. **Task Types / Tags**
**Problem:** Not all school tasks are the same. An exam requires different preparation than a reading assignment.
**Improvement:**
- Allow users to assign a type to tasks, such as "Homework", "Exam", "Reading", or "Project".
- **Benefit:** Provides immediate visual context to the type of work required.

---

## Architectural Adjustments Needed for these Features

To support the features above, the `Task` structure in `todo.h` should be expanded. Here is a conceptual example:

```c
#define MAX_SUBJECT_LEN 30
#define MAX_DATE_LEN 11 // YYYY-MM-DD + '\0'

typedef enum {
    STATUS_TODO,
    STATUS_IN_PROGRESS,
    STATUS_DONE
} TaskStatus;

typedef enum {
    TYPE_GENERAL,
    TYPE_HOMEWORK,
    TYPE_EXAM,
    TYPE_PROJECT,
    TYPE_READING
} TaskType;

typedef struct {
    char description[MAX_DESC_LEN];
    char subject[MAX_SUBJECT_LEN];
    char due_date[MAX_DATE_LEN]; 
    int priority;
    TaskStatus status;
    TaskType type;
} Task;
```

### Next Steps for Implementation:
1. **Update `todo.h`**: Modify the `Task` struct to include the new fields.
2. **Update `todo.c` functions**:
   - `add_task()`: Prompt for the new fields (Subject, Due Date, Type).
   - `update_task()`: Allow updating these new fields.
   - `display_tasks()`: Format the output to clearly show the subject, due date, and status. Consider formatting it as a clean table.
   - `save()` and `load()`: Update the file I/O formatting to write and read the new data structure (e.g., using `|` delimiters for the new fields).
3. **Add New Menu Options**:
   - Add options for "Sort by Due Date" or "Filter by Subject" to the main menu.

Implementing these features will transform this generic To-Do list into an essential, specialized tool for managing daily academic life.
