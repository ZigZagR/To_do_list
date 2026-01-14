#ifndef TODO_LIST_H
#define TODO_LIST_H

#define MAX_TASKS 10
#define MAX_DESC_LEN 100
#define TASK_FILE "../tasks.txt"
typedef struct {
    char description[MAX_DESC_LEN];
    int priority;
    int completed; // 0 = not completed, 1 = completed
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TM;

int add_task(TM *tm);
int update_task(TM *tm);
int delete_task(TM *tm);
int display_tasks(TM *tm);
int complete_task(TM *tm);
int save(TM *tm);
int load(TM *tm);

#endif // TODO_LIST_H
