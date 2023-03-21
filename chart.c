#include <stdio.h>
#include <string.h>
#include "chart.h"
#include "definitions.h"
#include "struct.h"

int maxLength = 0;
const int numOfTasks =

void max_Length(struct Task tasks[MAX_TASKS]) {
    int numOfTasks = 0;
    for (int i = 0 ; i < numOfTasks ; ++i)
    {
        if (strlen(tasks[i].name) > maxLength)
        {
            maxLength = strlen(tasks[i].name);
        }
    }
}

void copyFile()
{
        FILE *fptr1, *fptr2;
        char c;

        // Open template for reading
        fptr1 = fopen("formatTemplate", "r");

        // Open working file for writing
        fptr2 = fopen("format", "w");

        // Read contents from template and copy to other
        c = (char) fgetc(fptr1);
        while (c != EOF)
        {
            fputc(c, fptr2);
            c = (char) fgetc(fptr1);
        }

        fclose(fptr1);
        fclose(fptr2);
}

int ganttChart(struct Task tasks[MAX_TASKS])
{/*
read through every char until a newline,
at x, if the start month >= enum value && end month <= enum value, enter X, if not then replace with a space
at s, fprintf("%*s", max_length, taskname);
at f, fprintf("%*s", max-length, EMPTY);
at y, if num of dependencies > 0, enter dependencies (it may be a string or some shit)
at newline, skip another line and repeat
at eof, return 0
else move forward
 */
    enum Months {ERR,Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
    copyFile();

    FILE *fp;
    fp = fopen("format","w");
    int i = 0;
    int month = 1;

    int f = fgetc(fp);
    while (fgetc(fp) != EOF)
    {
        if (f == 'x')
        {
            if (tasks[i].start_month >= month && tasks[i].end_month <= month)
            {
                fseek(fp,-1,SEEK_CUR);
                fputc('X',fp);
            }
        }
        if (f == 's')
        {
            fseek(fp,-1,SEEK_CUR);
            fprintf("%*s", maxLength, tasks[i].name);
        }
        i += 1;
    }

    fclose(fp);
    return 0;
}
