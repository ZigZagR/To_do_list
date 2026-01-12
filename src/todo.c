#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "todo.h"

int add_task(TM *tm);
int update_task(TM *tm);
int delete_task(TM *tm);
int display_tasks(TM *tm); 
int complete_task(TM *tm); 
int save(TM *tm);
int load(TM *tm);

int main() {
    TM tm;
    load(&tm);

    int running = 1;
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
                save(&tm);
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (running);

    return 0;
}

int add_task(TM *tm) {
    if (tm->task_count >= MAX_TASKS) {
        printf("Task manager is full. Delete some tasks.\n");
        return 0;
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
    return 1;
}

int update_task(TM *tm) {
    if (tm->task_count == 0) {
        printf("No tasks to update.\n");
        return 0;
    }

    int index;
    printf("Enter task number to update (1-%d): ", tm->task_count);
    scanf("%d", &index);

    if (index < 1 || index > tm->task_count) {
        printf("Invalid task number.\n");
        return 0;
    }

    index--; // IT'S MAGIC AIN'T EXPLAINING SHIT (I'm actually explaining)
    // converts human(1,2,3,..) to computer(0,1,2,...)

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
    return 1;
}

int delete_task(TM *tm) {
    if (tm->task_count == 0) {
        printf("No tasks to delete.\n");
        return 0;
    }

    int index;
    printf("Enter task number to delete (1-%d): ", tm->task_count);
    scanf("%d", &index);

    if (index < 1 || index > tm->task_count) {
        printf("Invalid task number.\n");
        return 0;
    }

    index--; // Convert to 0-based index

    // Shift tasks to fill the gap
    for (int i = index; i < tm->task_count - 1; i++) {
        tm->tasks[i] = tm->tasks[i + 1];
    }

    (tm->task_count)--;
    printf("Task deleted successfully.\n");
    return 1;
}

int display_tasks(TM *tm) {
    if (tm->task_count == 0) {
        printf("\nNo tasks to display.\n");
        return 0;
    }

    printf("\nTo-Do List:\n");
    for (int i = 0; i < tm->task_count; i++) {
        printf("%d. %s (Priority: %d, Completed: %s)\n",
               i + 1,
               tm->tasks[i].description,
               tm->tasks[i].priority,
               tm->tasks[i].completed ? "Yes" : "No");
    }
    printf("Press enter to continue...");
    while (getchar() != '\n');
    getchar(); 

    return 1;
}

int complete_task(TM *tm) {
    if (tm->task_count == 0) {
        printf("\nNo tasks to complete.\n");
        return 0;
    }

    int index;
    printf("Enter task number to complete (1-%d): ", tm->task_count);
    scanf("%d", &index);

    if (index < 1 || index > tm->task_count) {
        printf("Invalid task number.\n");
        return 0;
    }

    index--; // IT'S MAGIC AIN'T EXPLAINING SHIT

    printf("Mark as completed? (1 = Yes, 0 = No): ");
    scanf("%d", &tm->tasks[index].completed);

    printf("Task updated successfully.\n");
    return 1;

}

int save(TM *tm) {
    FILE* file;

    file = fopen(TASK_FILE, "w");

    if(file == NULL) {
        printf("ERROR: File is not opened.");
        return 0;
    }

    for(int i = 0; i < tm->task_count; i++){
        fprintf(file, "%s|%d|%d\n",
            tm->tasks[i].description,
            tm->tasks[i].priority,
            tm->tasks[i].completed);

    }
    if(fclose(file) == 0){
        printf("File closed sucessfully.\n");
        file = NULL;
        return 1;
    } else{
        printf("Error: Data might not have saved.\n");
        return 0;
    }
}

int load(TM *tm){
    FILE* file;    
    file = fopen(TASK_FILE, "r");
  
    if(file == NULL) {
        tm->task_count = 0; 
        return 0;
    }

    tm->task_count = 0;
    while (fscanf(file, "%[^|]|%d|%d\n", 
           tm->tasks[tm->task_count].description, 
           &tm->tasks[tm->task_count].priority, 
           &tm->tasks[tm->task_count].completed) == 3) 
    {
        tm->task_count++;
        if(tm->task_count > MAX_TASKS) break;
    }

    if(fclose(file) == 0){
        printf("File closed sucessfully.\n");
        file = NULL;
        return 1;
    } else{
        printf("Error: Data might not have saved.\n");
        return 0;
    }
}