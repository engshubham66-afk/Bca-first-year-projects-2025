#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LEN 200

char tasks[MAX_TASKS][MAX_LEN];
int task_count = 0;

void saveTasks() {
	
    FILE *fp = fopen("tasks.txt", "w");
    if(fp==NULL){
	return ;
	}
	int i ;
    for ( i = 0; i < task_count; i++) {
        fprintf(fp, "%s\n", tasks[i]);
    }
    fclose(fp);
}

void loadTasks() {
    FILE *fp = fopen("tasks.txt", "r");
    if (fp == NULL) return;

    task_count = 0;
    while (fgets(tasks[task_count], MAX_LEN, fp)) {
        tasks[task_count][strcspn(tasks[task_count], "\n")] = '\0'; // remove newline
        task_count++;
    }

    fclose(fp);
}

void addTask() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }
    printf("Enter new task: ");
    getchar(); // clear buffer
    fgets(tasks[task_count], MAX_LEN, stdin);
    tasks[task_count][strcspn(tasks[task_count], "\n")] = '\0';
    task_count++;
    saveTasks();
    printf("Task added!\n");
}

void viewTasks() {
    if (task_count == 0) {
        printf("No tasks found.\n");
        return;
    }
    printf("\n--- TO-DO LIST ---\n");
    int i; 
    for ( i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void deleteTask() {
    if (task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    int num;
    printf("Enter task number to delete: ");
    scanf("%d", &num);

    if (num < 1 || num > task_count) {
        printf("Invalid number.\n");
        return;
    }

     int i; 
    for ( i = num - 1; i < task_count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    task_count--;
    saveTasks();
    printf("Task deleted!\n");
}

int main() {
    loadTasks();
    int choice;

    while (1) {
        printf("\n--- TO-DO LIST MENU ---\n");
        printf("1. View Tasks\n");
        printf("2. Add Task\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewTasks(); break;
            case 2: addTask(); break;
            case 3: deleteTask(); break;
            case 4: printf("Goodbye!\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
