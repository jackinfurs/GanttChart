#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void error() {
    printf("Invalid input.");
    exit(-1);
}

void createChart() {
    int i,j;
    int taskNum;
    struct Task tasks[MAX_TASKS];
    printf("Please enter how many tasks:\n");
    scanf(" %d",&taskNum);
    if (taskNum < 1 || taskNum > 10)
    {
        error();
    }
    for (i = 0 ; i < taskNum ; ++i)
    {
        char *title;
        printf("Enter the name of task %d\n", i+1);
        scanf(" %s",tasks[i].name);
        title = tasks[i].name;

        printf("Enter the start month for %s\n",title);
        scanf(" %d",&tasks[i].startMonth);
        if (tasks[i].startMonth < JAN || tasks[i].startMonth > DEC)
        {
            error();
        }

        printf("Enter the end month for %s\n",title);
        scanf(" %d",&tasks[i].endMonth);
        if (tasks[i].endMonth < tasks[i].startMonth || tasks[i].endMonth > DEC)
        {
            error();
        }

        printf("Enter the number of dependencies for %s\n",title);
        scanf(" %d",&tasks[i].numOfDepen);
        if (tasks[i].numOfDepen > 0)
        {
            for (j = 0 ; j < tasks[i].numOfDepen ; ++j)
            {
                printf("Enter dependent task %d for %s\n",j+1,title);
                scanf(" %d",&tasks[i].dependencies[j]);
            }
        } else if (tasks[i].numOfDepen < 0)
        {
            error();
        }
    }
    // print chart of above
}

void editTestQuit() {
    printf("");
}

int main(void) {
    int option;

    printf("Welcome to the Gantt Generator.\n");
    printf("Please enter:\n\t1: to view an example chart\n\t2: to create your own chart\n");
    scanf(" %d",&option);

    switch (option)
    {
        case 1:
            // make chart with placeholder
            break;
        case 2:
            createChart();
            editTestQuit();
            break;
        default:
            error();
    }

    return 0;
}
