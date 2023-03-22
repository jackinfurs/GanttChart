#include <stdio.h>
#include <string.h>
#include "chart.h"

int maxLength;
int lineLength;

int maxLenOfString(struct Task task[], int numOfTasks)
{
    for (int i = 0 ; i < numOfTasks ; ++i)
    {
        if (strlen(task[i].name) > maxLength)
        {
            maxLength = strlen(task[i].name);
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
    maxLength = maxLenOfString(tasks,numOfTasks);
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
