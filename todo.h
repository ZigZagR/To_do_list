#ifndef TODO_LIST_H
#define TODO_LIST_H

#define MAX_TASKS 10
#define MAX_DESC_LEN 100

typedef struct {
    char description[MAX_DESC_LEN];
    int priority;
    int completed; // 0 = not completed, 1 = completed
} Task;

void add_task(Task tasks[], int *task_count);
void update_task(Task tasks[], int task_count);
void delete_task(Task tasks[], int *task_count);
void display_tasks(Task tasks[], int task_count);

#endif // TODO_LIST_H
