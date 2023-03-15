#include <stdio.h>
#include "chart.h"
#include "definitions.h"
#include "struct.h"

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

int ganttChart(struct Task tasks)
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
    copyFile();

    FILE *fp;
    fp = fopen("format","w");
    int month = 1;

    f = fgetc();
    while ()

    fclose(fp);
    return 0;
}
