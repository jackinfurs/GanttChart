#include <stdio.h>
#include <string.h>
#include "chart.h"
#include "definitions.h"
#include "struct.h"

int maxLength = 0;
int lineLength = 0;

int maxLenOfString(struct Task task[], int numOfTasks)
{
    int maxStringLength = 0;
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

void ganttChart(struct Task tasks[], int numOfTasks) {
    // clear screen
    int i,j;
    maxLength = maxLenOfString(tasks,numOfTasks);
    lineLength = 0;

    FILE *fp;
    fp = fopen("chart","w+");

    fprintf(fp,"%*s",maxLength,EMPTY);
    for (i = 0 ; i < DEC)

    fclose(fp);
}
