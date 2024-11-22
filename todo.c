#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

void add_task(TM *tm) {
    if (tm->task_count >= MAX_TASKS) {
        printf("Task manager is full. Delete some tasks.\n");
        return;
    }

    printf("Enter task description: ");
    getchar(); // Clear the input buffer
    fgets(tm->tasks[tm->task_count].description, MAX_DESC_LEN, stdin);
    tm->tasks[tm->task_count].description[strcspn(tm->tasks[tm->task_count].description, "\n")] = '\0'; // Remove newline

    printf("Enter task priority (1-5): ");
    scanf("%d", &tm->tasks[tm->task_count].priority);

    tm->tasks[tm->task_count].completed = 0; 
    (tm->task_count)++;
    printf("Task added successfully.\n");
}

void update_task(TM *tm) {
    if (tm->task_count == 0) {
        printf("No tasks to update.\n");
        return;
    }

    int index;
    printf("Enter task number to update (1-%d): ", tm->task_count);
    scanf("%d", &index);

    if (index < 1 || index > tm->task_count) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // IT'S MAGIC AIN'T EXPLAINING SHIT

    printf("Updating Task %d:\n", index + 1);
    printf("Enter new description: ");
    getchar(); // Clear the input buffer
    fgets(tm->tasks[index].description, MAX_DESC_LEN, stdin);
    tm->tasks[index].description[strcspn(tm->tasks[index].description, "\n")] = '\0';

    printf("Enter new priority (1-5): ");
    scanf("%d", &tm->tasks[index].priority);

    printf("Mark as completed? (1 = Yes, 0 = No): ");
    scanf("%d", &tm->tasks[index].completed);

    printf("Task updated successfully.\n");
}

void delete_task(TM *tm) {
    if (tm->task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int index;
    printf("Enter task number to delete (1-%d): ", tm->task_count);
    scanf("%d", &index);

    if (index < 1 || index > tm->task_count) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // Convert to 0-based index

    // Shift tasks to fill the gap
    for (int i = index; i < tm->task_count - 1; i++) {
        tm->tasks[i] = tm->tasks[i + 1];
    }

    (tm->task_count)--;
    printf("Task deleted successfully.\n");
}

void display_tasks(TM *tm) {
    if (tm->task_count == 0) {
        printf("\nNo tasks to display.\n");
        return;
    }

    printf("\nTo-Do List:\n");
    for (int i = 0; i < tm->task_count; i++) {
        printf("%d. %s (Priority: %d, Completed: %s)\n",
               i + 1,
               tm->tasks[i].description,
               tm->tasks[i].priority,
               tm->tasks[i].completed ? "Yes" : "No");
    }
    printf("Press enter to continue... ");
    while (getchar() != '\n');
    getchar();    
}

void complete_task(TM *tm) {
    if (tm->task_count == 0) {
        printf("\nNo tasks to complete.\n");
        return;
    }

    int index;
    printf("Enter task number to complete (1-%d): ", tm->task_count);
    scanf("%d", &index);

    if (index < 1 || index > tm->task_count) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // IT'S MAGIC AIN'T EXPLAINING SHIT

    printf("Mark as completed? (1 = Yes, 0 = No): ");
    scanf("%d", &tm->tasks[index].completed);

    printf("Task updated successfully.\n");

}

int main() {
    TM tm;
    tm.task_count = 0;

    int choice;
    do {
        printf("\nTo-Do List Menu:\n");
        printf("1. Add Task\n");
        printf("2. Update Task\n");
        printf("3. Delete Task\n");
        printf("4. Display Tasks\n");
        printf("5. Complete Task\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(&tm);
                break;
            case 2:
                update_task(&tm);
                break;
            case 3:
                delete_task(&tm);
                break;
            case 4:
                display_tasks(&tm);
                break;
            case 5:
                complete_task(&tm);
                break;
            case 6:
                printf("Exiting To-Do List Manager.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
