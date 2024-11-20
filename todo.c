#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

void add_task(Task tasks[], int *task_count) {
    if (*task_count >= MAX_TASKS) {
        printf("Task manager is full. Delete some tasks.\n");
        return;
    }

    printf("Enter task description: ");
    getchar(); // Clear the input buffer
    fgets(tasks[*task_count].description, MAX_DESC_LEN, stdin);
    tasks[*task_count].description[strcspn(tasks[*task_count].description, "\n")] = '\0'; // Remove newline

    printf("Enter task priority (1-5): ");
    scanf("%d", &tasks[*task_count].priority);

    tasks[*task_count].completed = 0; 
    (*task_count)++;
    printf("Task added successfully.\n");
}

void update_task(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks to update.\n");
        return;
    }

    int index;
    printf("Enter task number to update (1-%d): ", task_count);
    scanf("%d", &index);

    if (index < 1 || index > task_count) {
        printf("Invalid task number.\n");
        return;
    }

    index--; 

    printf("Updating Task %d:\n", index + 1);
    printf("Enter new description: ");
    getchar(); // Clear the input buffer
    fgets(tasks[index].description, MAX_DESC_LEN, stdin);
    tasks[index].description[strcspn(tasks[index].description, "\n")] = '\0';

    printf("Enter new priority (1-5): ");
    scanf("%d", &tasks[index].priority);

    printf("Mark as completed? (1 = Yes, 0 = No): ");
    scanf("%d", &tasks[index].completed);

    printf("Task updated successfully.\n");
}

void delete_task(Task tasks[], int *task_count) {
    if (*task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int index;
    printf("Enter task number to delete (1-%d): ", *task_count);
    scanf("%d", &index);

    if (index < 1 || index > *task_count) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // Convert to 0-based index

    // Shift tasks to fill the gap
    for (int i = index; i < *task_count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*task_count)--;
    printf("Task deleted successfully.\n");
}

void display_tasks(Task tasks[], int task_count) {
    if (task_count == 0) {
        printf("No tasks to display.\n");
        return;
    }

    printf("\nTo-Do List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s (Priority: %d, Completed: %s)\n",
               i + 1,
               tasks[i].description,
               tasks[i].priority,
               tasks[i].completed ? "Yes" : "No");
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count = 0;

    int choice;
    do {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Update Task\n");
        printf("3. Delete Task\n");
        printf("4. Display Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(tasks, &task_count);
                break;
            case 2:
                update_task(tasks, task_count);
                break;
            case 3:
                delete_task(tasks, &task_count);
                break;
            case 4:
                display_tasks(tasks, task_count);
                break;
            case 5:
                printf("Exiting To-Do List Manager.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
