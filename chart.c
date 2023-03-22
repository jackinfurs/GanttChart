#include <stdio.h>
#include <string.h>
#include "chart.h"
#include "definitions.h"

int maxLength;
int lineLength;

enum months {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
};

char *monthsArray[12] = {"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};

void maxLenOfString(struct Task tasks[], int numOfTasks)
{
    for (int i = 0 ; i < numOfTasks ; ++i)
    {
        if (strlen(tasks[i].name) > maxLength)
        {
            maxLength = (int) strlen(tasks[i].name);
        }
    }
}

void printLines() {
    printf("\n");
    for (int i = 0 ; i < lineLength ; ++i)
    {
        printf("-");
    }
    printf("\n");
}

void ganttChart (struct Task tasks[], int numOfTasks) {
    // clear screen
    int i,j;
    maxLenOfString(tasks,numOfTasks);
    lineLength = 20;

    FILE *fp;
    fp = fopen("chart","w+");

    fprintf(fp,"%*s|",maxLength,EMPTY);
    for (i = JAN ; i < (DEC) ; ++i)
    {
        fprintf(fp," %s ",monthsArray[i]);
        fprintf(fp,"|");
    }
    fprintf(fp,"Dependencies");
    fseek(fp,0,SEEK_SET);
    int c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c",*&c);
        lineLength += 1;
    }
    fclose(fp);

    printLines();

    for (i = 0 ; i < numOfTasks ; ++i)
    {
        printf("%*s|",maxLength,tasks[i].name);

        for (j = JAN ; j < DEC+1 ; ++j)
        {
            if (tasks[i].start_month >= j)
            {
                printf("  X  |");
            }
            else
            {
                printf("     |");
            }
        }
        for (j = 0 ; j < tasks[i].numbOfDepen ; ++j)
        {
            printf("%d ", tasks[i].dependencies[j]);
        }
        printLines();
    }
}
