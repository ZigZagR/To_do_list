#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char* description;  
    int priority;       
};

struct TaskManager {
    struct Task* tasks;  
    int task_count;      
};

void allocate_task_description(struct Task *task, const char* desc);
void free_task(struct Task* task);
void free_all_tasks(struct TaskManager* tm);
void add_task(struct TaskManager* tm, const char* description);
void display_tasks(struct TaskManager* tm);
void update_task(struct TaskManager* tm, int index, const char* new_description);
void delete_task(struct TaskManager* tm, int index);
void execute_option(int choice, struct TaskManager* tm);
void menu(struct TaskManager* tm);

#endif
