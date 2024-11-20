# include "todo.h"

void allocate_task_description(struct Task *task,const char* desc){
    size_t lenght = strlen(desc) + 1;

    task->description = (char *) malloc(lenght * sizeof(char));

    if (task->description == NULL){
        printf("Error: Memory allocation failed");
        exit(1);
    }

    strcpy(task->description, desc);
}

void free_task(struct Task *task){
    if (task->description != NULL){
        free(task->description);
        task->description = NULL;
    }
}

void add_task(struct TaskManager* tm, const char description){

    tm->tasks = realloc(tm->tasks, (tm->task_count + 1) * sizeof(struct Task));
    if(tm->tasks == NULL){
        printf("Error: Memory allocation");
        exit(1);
    }
    struct Task new_task;
    alllocate_task_description(&new_task, description);
    printf("\n-------------------------------\n");
    new_task.priority = 1;
    tm->tasks[tm->task_count] = new_task;
    tm->task_count++;
}

void display_tasks(struct TaskManager* tm){
    if(tm->task_count == 0){
        printf("No tasks to display");
        return;
    }

    for(int i = 0; i < tm->task_count; i++){
        printf("Task %d: %s (Priority %d)\n", i + 1, tm->tasks[i].description, tm->tasks[i].priority);
    }    
}

void update_task(struct TaskManager* tm, int index, const char* new_description){
    
}

void execute_option(int choice, struct TaskManager* tm){
    switch (choice){
        case 1:
            // add_task(tm, "New Task");
            printf("Test: Add Task\n");
            break;
        case 2:
            printf("Test: Display Tasks\n");
            // display_tasks(tm);
            break;
        case 3:
            printf("Test: Update Task\n");
            // update_task(tm, 0, "Upload Task");
            break;
        case 4:
            printf("Test: Delete Task\n");
            // delete_task(tm, 0);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid input. Try again.\n");
    }
}

void menu(struct TaskManager* tm){
    int choice; 
    do {
        printf("\nTask Manager Menu\n");
        printf("-------------------------------\n");
        printf("1. Add a New Task.\n");
        printf("2. View All Tasks.\n");
        printf("3. Update Task.\n");
        printf("4. Delete a Task\n");
        printf("5. Exit\n");
        printf("-------------------------------\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        execute_option(choice, tm);
    } while (choice != 5);

}

void free_tm(struct TaskManager* tm){
    for(int i = 0; i < tm->task_count; i++){
        free_task(&tm->tasks[i]);
    }
    free(tm->tasks);
    tm->tasks = NULL;
    tm->task_count = 0;
}

int main(){
    struct TaskManager tm = {NULL, 0};

    menu(&tm);

    free_tm(&tm);

    return 0;
}

