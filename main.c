// COMP10050 Assignment 2
// Group B0:
// Martina D'Argenzio   22789139
// Jack Dunne           22483576
// https://csgitlab.ucd.ie/jack-dunne626/bo-assignment-2.git
// using C11

// what's wrong with pen and paper?

// import necessary libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// import local libs
#include "chart.h" // chart.c
#include "placeholder.h"
#include "struct.h"

// for error checking
void error() {
    printf("Invalid input.");
    exit(-1);
}

// global struct array for entering tasks
struct Task tasks[MAX_TASKS];
// global int for number of tasks in array
int taskNum;
int dependencyCheck;

// function for user to create their own tasks
void createChart() {
    // increments
    int i, j;
    // init global int taskNum
    taskNum = 0;
    printf("Please enter how many tasks:\n");
    scanf(" %d", &taskNum); // scanf used, no need to worry about buffer overflow in such a low-level project
    // error checking
    if (taskNum < 1 || taskNum > 10) {
        error();
    }
    // loop for amount of tasks
    for (i = 0; i < taskNum; ++i) {
        // ptr title for brevity, more details below
        char *title;

        printf("Enter the name of task %d\n", i + 1);
        scanf(" %s", tasks[i].name);
        title = tasks[i].name;

        // title = tasks[i].name, looks nicer
        printf("Enter the start month for %s\n", title);
        scanf(" %d", &tasks[i].startMonth);
        // error checking for out of bounds, JAN = 1 DEC = 12 as per enum
        if (tasks[i].startMonth < JAN || tasks[i].startMonth > DEC) {
            error();
        }

        printf("Enter the end month for %s\n", title);
        scanf(" %d", &tasks[i].endMonth);
        // error checking to make sure end month is not before start month/out of bounds
        if (tasks[i].endMonth < tasks[i].startMonth || tasks[i].endMonth > DEC) {
            error();
        }

        printf("Enter the number of dependencies for %s\n", title);
        scanf(" %d", &tasks[i].numOfDepen);
        // loop for 1 or more dependencies, entered above
        if (tasks[i].numOfDepen > 0) {
            // loop for dependencies entered above, add to dependency array in struct
            for (j = 0; j < tasks[i].numOfDepen; ++j) {
                printf("Enter dependent task %d for %s\n", j + 1, title);
                scanf(" %d", &tasks[i].dependencies[j]);
                // error checking for out of bounds, if task entered above is greater than the num of tasks entered
                if (tasks[i].dependencies[j] > taskNum || tasks[i].dependencies[j] < 1) {
                    error();
                }
            }
        }
            // error checking for negative / 10 or more tasks
            // i.e. a task cannot be dependent on 10 or above because then it'd have to depend on itself, impossible
        else if (tasks[i].numOfDepen < 0 || tasks[i].numOfDepen >= MAX_TASKS) {
            error();
        }
        // new line for style points
        printf("\n");
    }
    // print chart with tasks as created above, see chart.c for details
    ganttChart(tasks, taskNum);
}

int circularCheck(struct Task task[], int taskID, int visited_numb[], int taskNum) {
    visited_numb[taskNum++] = taskID;
    if (taskNum > 10) {
        return 1;
    }

    if (task[taskID].numOfDepen == 0) {
        return 0;
    }

    for (int i = 0; i < task[i].numOfDepen; i++) {
        int dependent_task = task[taskID].dependencies[i];

        for (int j = 0; j < taskNum; j++) {
            if (dependent_task == visited_numb[j]) {
                return 1;
            }
        }

        if (circularCheck(task, taskID, visited_numb, taskNum)) {
>>>>>>> 5c0932fcfd3ed8547880f53c7201e3c5569f25df
            return 1;
        }
    }
    return 0;
}

int circularCheck(struct Task task[], int taskID) {
    printf("%d -> ",taskID);
    if (task[taskID-1].numOfDepen == 0)
    {
        return 0;
    }
    else if (dependencyCheck > MAX_TASKS)
    {
        return 1;
    }
    else if (task[taskID-1].numOfDepen > 0)
    {
        for (int i = 0 ; i < task[taskID-1].numOfDepen ; ++i)
        {
            dependencyCheck++;
            if (circularCheck(task,task[taskID-1].dependencies[i]) == 0)
                return 0;
            else return 1;
        }
    }
}


void printDependencies(struct Task task[MAX_LENGTH], int taskID, int visitedTask[]) {
    int i;

    printf("%d -> ", taskID);
    if (task[taskID - 1].numOfDepen == 0) {
        printf("END\nNo circular dependencies found.\n");
    } else {
        for (i = 0; i < task[taskID - 1].numOfDepen; ++i) {
            // where we left off
            if (visitedTask[taskID - 1] == 0) {
                taskID = task[taskID - 1].dependencies[i];
                visitedTask[taskID - 1] += 1;
                printDependencies(task, taskID, visitedTask);
            } else {
                printf("\n!!! Warning potential circular dependencies !!!\n");
                dependencyCheck = 0;
                if (circularCheck(task,taskID) == 0)
                {
                    printf("No circular dependencies found.\n");
                }
                else
                {
                    printf("Circular dependency found. Please fix.\n");
                }
            }
        }
    }
}

// function to edit, test, or quit
// provided either user-made struct or placeholder-made struct
void editTestQuit(struct Task task[MAX_LENGTH], int taskQuant) {
    // increments
    int i, j;
    // for console input
    char input[MAX_LENGTH];
    printf("\nIf you would like to edit a task, please type 'edit'\n");
    printf("If you would like to test a task for circular dependencies, please type 'test'\n");
    printf("If you would like to quit, please type 'quit'\n");
    scanf(" %s", input);

    // edit
    if (strcmp(input, "edit") == 0) {
        printf("Please enter the name of the task you wish to change.\n");
        scanf(" %s", input);
        i = 0;
        // run through struct array to find index of task in array by name
        while (strcmp(input, task[i].name) != 0) {
            if (i > taskQuant) {
                error();
            }
            ++i;
        }
        // brevity, see above
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
                if (task[i].dependencies[j] > taskQuant || task[i].dependencies[j] < 1) {
                    error();
                }
            }
        } else if (task[i].numOfDepen < 0 || task[i].numOfDepen >= MAX_TASKS) {
            error();
        }
        printf("\n");

        // print gantt chart with newly-edited struct entries, see chart.c for details
        ganttChart(task, taskQuant);
        // after printing, rerun function
        // (considered a recursive call but not really a problem, depends on user input)
        editTestQuit(task, taskQuant);
    }
        // enter circular dependency test function here
    else if (strcmp(input, "test") == 0) {

        int taskID;
        printf("Please enter the task number you wish to test\n");
        scanf(" %d", &taskID);

        int visitedTask[MAX_TASKS] = {0};

        printDependencies(task, taskID, visitedTask);
        // go to taskID in task array with an initialised visitedTask array
    }
        // quit program safely
    else if (strcmp(input, "quit") == 0) {
        printf("\nThank you for using the Gantt Generator.\n");
    }
}

// main function
int main(void) {
    // user input
    int option;

    printf("Welcome to the Gantt Generator.\n");
    printf("Please enter:\n\t1: to view an example chart\n\t2: to create your own chart\n");
    scanf(" %d", &option); // scanf used, no need to worry about buffer overflow in such a low-level project

    switch (option) {
        case 1: // view example chart with placeholder struct array of 10 tasks
            ganttChart(placeholder, MAX_TASKS);
            editTestQuit(placeholder, MAX_TASKS);
            break;
        case 2: // create own chart
            createChart();
            editTestQuit(tasks, taskNum);
            break;
        default: // error checking, anything other than 1 or 2
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
