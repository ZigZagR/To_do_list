#ifndef TODO_LIST_H
#define TODO_LIST_H

#define MAX_TASKS 10
#define MAX_DESC_LEN 100

typedef struct {
    char description[MAX_DESC_LEN];
    int priority;
    int completed; // 0 = not completed, 1 = completed
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TM;

void add_task(TM *tm);
void update_task(TM *tm);
void delete_task(TM *tm);
void display_tasks(TM *tm);

#endif // TODO_LIST_H
