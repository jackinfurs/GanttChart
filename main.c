#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "chart.h"
#include "placeholder.h"

void error() {
    printf("Invalid input.");
    exit(-1);
}

struct Task tasks[MAX_TASKS];
int taskNum;

void createChart() {
    int i, j;
    taskNum = 0;
    printf("Please enter how many tasks:\n");
    scanf(" %d", &taskNum);
    if (taskNum < 1 || taskNum > 10) {
        error();
    }
    for (i = 0; i < taskNum; ++i) {
        char *title;
        printf("Enter the name of task %d\n", i + 1);
        scanf(" %s", tasks[i].name);
        title = tasks[i].name;

        printf("Enter the start month for %s\n", title);
        scanf(" %d", &tasks[i].startMonth);
        if (tasks[i].startMonth < JAN || tasks[i].startMonth > DEC) {
            error();
        }

        printf("Enter the end month for %s\n", title);
        scanf(" %d", &tasks[i].endMonth);
        if (tasks[i].endMonth < tasks[i].startMonth || tasks[i].endMonth > DEC) {
            error();
        }

        printf("Enter the number of dependencies for %s\n", title);
        scanf(" %d", &tasks[i].numOfDepen);
        if (tasks[i].numOfDepen > 0) {
            for (j = 0; j < tasks[i].numOfDepen; ++j) {
                printf("Enter dependent task %d for %s\n", j + 1, title);
                scanf(" %d", &tasks[i].dependencies[j]);
                if (tasks[i].dependencies[j] > taskNum) {
                    error();
                }
            }
        } else if (tasks[i].numOfDepen < 0 || tasks[i].numOfDepen >= MAX_TASKS) {
            error();
        }
        printf("\n");
    }
    ganttChart(tasks, taskNum);
}

void editTestQuit(struct Task task[MAX_LENGTH], int taskQuant) {
    int i,j;
    char input[MAX_LENGTH];
    printf("\nIf you would like to edit a task, please type 'edit'\n");
    printf("If you would like to test a task for circular dependencies, please type 'test'\n");
    printf("If you would like to quit, please type 'quit'\n");

    scanf(" %s", input);
    if (strcmp(input, "edit") == 0) {
        printf("Please enter the name of the task you wish to change.\n");
        scanf(" %s", input);
        i = 0;
        while (strcmp(input, task[i].name) != 0) {
            if (i > taskQuant) {
                error();
            }
            ++i;
        }
        char *title;
        printf("Re-enter the name of %s\n", task[i].name);
        scanf(" %s", task[i].name);
        title = task[i].name;

        printf("Enter the start month for %s\n", title);
        scanf(" %d", &task[i].startMonth);
        if (task[i].startMonth < JAN || task[i].startMonth > DEC) {
            error();
        }

        printf("Enter the end month for %s\n", title);
        scanf(" %d", &task[i].endMonth);
        if (task[i].endMonth < task[i].startMonth || task[i].endMonth > DEC) {
            error();
        }

        printf("Enter the number of dependencies for %s\n", title);
        scanf(" %d", &task[i].numOfDepen);
        if (task[i].numOfDepen > 0) {
            for (j = 0; j < task[i].numOfDepen; ++j) {
                printf("Enter dependent task %d for %s\n", j + 1, title);
                scanf(" %d", &task[i].dependencies[j]);
                if (task[i].dependencies[j] > taskQuant) {
                    error();
                }
            }
        } else if (task[i].numOfDepen < 0 || task[i].numOfDepen >= MAX_TASKS) {
            error();
        }
        printf("\n");
        ganttChart(task,taskQuant);
        editTestQuit(task,taskQuant);
    } else if (strcmp(input, "test") == 0) {
        printf("test");
    } else if (strcmp(input, "quit") == 0) {
        printf("\nThank you for using the Gantt Generator.\n");
    }
}

int main(void) {
    int option;

    printf("Welcome to the Gantt Generator.\n");
    printf("Please enter:\n\t1: to view an example chart\n\t2: to create your own chart\n");
    scanf(" %d", &option);

    switch (option) {
        case 1:
            ganttChart(placeholder, MAX_TASKS);
            editTestQuit(placeholder,MAX_TASKS);
            break;
        case 2:
            createChart();
            editTestQuit(tasks,taskNum);
            break;
        default:
            error();
            break;
    }

    return 0;
}

/*

                         M                                         M   M
                             NXXN                                  M  MM
                          XKOxoodk0X                             NN
                       X0OxdddolccloxOKN      M             NNK0OkOK
                   NX0kxddddddocccllclodxk0X           NXK0OkxdddddkX
                NKOkxdddddddddlcccclllllllodxOKN  NXK0OkxdddddddddddkX  M
             NKOkxddddddddddddlccccccllllllolodxkkxxddddddddddddxddxdkX
         NXKOkxddddxxddxddddddllllllllllllloooddddddxxdddxddddddddddddkX
        N0xdddddc;;;;;;;;;;;;;,,,,,,,,,,,,,,,;;;;;;;;;;;;;;;;;:cdddddddkX
        Kxdddddo.                                              .oxddddddkX
        0ddddddo'                                              .oddddddddkX
       Nkodddddo'         .;:ccc:;.       ,::;.                .odddddddddOX
MM     Kxodddddl.      'oOX M     XOo.   'O MN:                .oxdddddddddON
MM   M Oddddoddl.    .oX  N0xoodkKN O,   'O MN:                .oxddddddddkK M
  M  MXkoddddodl.   .x   O:.     .;:.    'OMMN:                .odddddddx0N   M
  M   Kdodoododo.   c   0,               'OMMN:                .odddddxOX
      Oooooooodl.   dM Mx.               'O MN:                .oxdddkKN
     Nkooooooodl.   lN  0'               'O MN:                .oddx0N
M MM Kdooooooodl.   .k M O,       ,;.    'O MN:                .oxkK
MM  NOoooooooodl.    .xN  NOocccoOX 0:.  'OMM kclccccc'        .dKN
MM  Xxoooooooool.      ;xKN   MM  NOo'   'OMM MMMMMMMMx.       ,K
    Kdoooooooooc.        .,:loool:'.     .,:::::::::::'        ;X    MM
  M Oooooooooool.                                              ;K
MM Xxloooooooodo'                                              'x0KXNN
MM Kdlollooodddo.                                              .odddxkO0KXN
  NOollooodddddo.                                              .oxdddddddxkk0X
  Xxlloodddddddo.                                              .oddddddddxddkX
  Koloddddddddxo.   .:::::::::::::::c;.                        .oddddddddddkK
  0odxddddddddxo'   ;0XXXXXXXXXXXXXXXO'                        .odddddddddxKN
  X0kxddddddddxo'    .................                         .oddddddddx0N
    NXOkdddddddo'                                              .odddddddx0N
       NKOxdddxo,..............................................,oddddddx0N
          X0kxddoooolllllllllllllllooollllollllllllllllllloolloodddddddON
            NX0kddddddddddddddddddxk00kdddddddddddddddddddddddddddddddON
               NKOxdddddddddddddxOKN  NK0OxdddddddddddddddddddddddxddkX
                  XKOxddddddddxOKN        X0kxddddddddddddddddddddddkX
                     X0kxdddx0X             NXOkxxdddddddddddddddddxX   M
                       NKOk0X                  NXXKK0OOkxxxdddddddxK
                                                        NXXKK0OOkkK
                             M                       MM          N     M

 */
