//
// Created by dynam on 22/03/2023.
//

#include <string.h>
#include <stdio.h>
#include "chart.h"

#define EMPTY   ""

int maxLength;
int lineLength;

char *monthsArr[13] = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

void maxLenOfStr(struct Task tasks[], int numOfTasks) {
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

void ganttChart(struct Task tasks[MAX_LENGTH], int numOfTasks) {
    // clear screen
    int i,j;
    maxLength = 0;
    lineLength = 20;
    maxLenOfStr(tasks,numOfTasks);

    FILE *fp;
    fp = fopen("format","w+");

    fprintf(fp,"%*s|",maxLength,EMPTY);
    for (i = JAN ; i < DEC+1 ; ++i)
    {
        fprintf(fp," %s |", monthsArr[i]);
    }
    fprintf(fp," Dependencies");
    fseek(fp,0,SEEK_END);
    lineLength += ftell(fp); // fuckin genius
    rewind(fp);
    int c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }
    fclose(fp);
    printLines();

}
