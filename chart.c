// include necessary libs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// include local libs
#include "chart.h"

// define empty string for readability
#define EMPTY   ""

// create global vars for max length of string, and number of lines to divide rows
int maxLength;
int lineLength;

// create char ptr array of size months+1
// for readability, jan = 1 and so on, rather than jan = 0 which will confuse
char *monthsArr[13] = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

// function to universally clear console
// warning: format depends on the size of the window. if it's small, it won't display properly.
void clear() {
    // for not-windows
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    // for windows
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

// function to find longest string in struct array
// used for padding at first column
void maxLenOfStr(struct Task tasks[], int numOfTasks) {
    // loop for number of tasks
    for (int i = 0 ; i < numOfTasks ; ++i)
    {
        // if task name is longer than what's in global var maxLength, set maxLength to the length of the string
        if (strlen(tasks[i].name) > maxLength)
        {
            maxLength = (int) strlen(tasks[i].name);
        }
    }
}

// function to print the dividing rows
void printLines() {
    printf("\n");
    // lineLength declared above and set below
    for (int i = 0 ; i < lineLength ; ++i)
    {
        printf("-");
    }
    printf("\n");
}

// function to print a gantt chart given a struct array and the num of tasks in it
void ganttChart(struct Task tasks[MAX_LENGTH], int numOfTasks) {
    // clear screen, see function above
    clear();

    // increments
    int i,j;
    // init global vars
    maxLength = 0;
    // 20 because:
    // a: it's a nice round number
    // b: tasks 1-10 and a space between is of length 20, so that the divider can reach beyond the dependencies column
    lineLength = 20;
    // see function above
    maxLenOfStr(tasks,numOfTasks);

    // opens new file "format" or formats it
    FILE *fp;
    // w+ for read/write perms
    fp = fopen("format","w+");

    // to file:
    // print empty string with padding of maxLength
    fprintf(fp," %*s |",maxLength,EMPTY);
    // print months row
    for (i = JAN ; i < DEC+1 ; ++i)
    {
        fprintf(fp," %s |", monthsArr[i]);
    }
    fprintf(fp," Dependencies");
    // since pointer is at the end, add position of pointer to lineLength
    lineLength += ftell(fp); // fuckin genius
    // rewind to start of file and print everything so far
    rewind(fp);
    int c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    // print divider
    printLines();

    // print tasks
    // loop printing for tasks
    // mostly described above
    for (i = 0 ; i < numOfTasks ; ++i)
    {
        printf(" %*s |",maxLength,tasks[i].name);
        // no real reason for enums here
        for (j = JAN ; j < DEC+1 ; ++j)
        {
            // if month is within start/end month of task, print an X. otherwise nothing.
            if (tasks[i].startMonth <= j && tasks[i].endMonth >= j)
            {
                printf("  X  |");
            }
            else
            {
                printf("     |");
            }
        }
        // spacing
        printf(" ");
        // print dependencies entered
        for (j = 0 ; j < tasks[i].numOfDepen ; ++j)
        {
            printf("%d ",tasks[i].dependencies[j]);
        }
        // print divider
        printLines();
    }
}
