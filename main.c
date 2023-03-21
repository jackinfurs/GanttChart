/*  COMP10050 Assignment 2
    Group BO:
	    Martina D’Argenzio	22789139
        Jack Dunne		    22483576
    https://csgitlab.ucd.ie/jack-dunne626/bo-assignment-2.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chart.h"
#include "definitions.h"
#include "struct.h"
#include "placeholder.h"

// definitions for MAX_LENGTH, EMPTY, MAX_TASKS

/*
 * For Martina:
 * Below in "int main", add in error checking for the scanf statements
 * e.g.: make sure invalid options cannot be entered.
 *
 * Below in int main, add in the option to enter dependencies to different tasks
 * Check the briefing doc on Moodle for an example (far right column dependencies)
 *
 * In a new file called "placeholder.c"
 * Create placeholder text for the example chart
 * Create 10 tasks with different sample names, start months, end months, and dependencies
 * (might have to research structs!)
 *
 */

/*void dependencies_count (int numbOfDepen)
{
    char dependencies[MAX_LENGTH];
    char input[MAX_LENGTH];
    for (int i = 0; i<numbOfDepen; i++)
    {
        printf("Enter the dependent task:\n");
        scanf("%s",&input);
        strcat(" ",input);
        strcpy(&dependencies[i],input);
    }
}*/

void error() {
    printf("Invalid entry.\n");
    exit(1);
}

int main() {
    struct Task tasks[MAX_TASKS];
    int numOfTasks;
    int i, j, option;

    printf("Welcome to the Gantt Generator\n");
    printf("Would you like to use the test example (1) or create your own Gantt from scratch (2)?\n");
    scanf("%d", &option);
    if (option != 1 && option != 2) {
        error();
    }

    if (option == 1) {


    } else if (option == 2) {

        // Create own series of tasks: using a struct with name, start/end month, and dependencies

        // How many tasks? (0 invalid, else iterate for number of tasks entered)
        printf("How many tasks would you like to add ? (1-10)\n");
        scanf(" %d", &numOfTasks); // using scanf, no need to worry about buffer overflow in 1st year project
        if (numOfTasks < 1 || numOfTasks > 10) {
            error();
        }

        for (i = 0; i < numOfTasks; i++) {
            // Task name
            printf("Please enter the name of task %d:\n", i + 1);
            scanf(" %s", tasks[i].name);

            // Start/end month (input <= 0 or > 12, invalid input)
            printf("Please enter the start month (1-12):\n");
            scanf(" %d", &tasks[i].start_month);

            if (tasks[i].start_month <= 0 || tasks[i].start_month > 12) {
                error();
            }

            // Start/end month (input <= 0 or > 12, invalid input)
            printf("Please enter the end month (1-12):\n");
            scanf(" %d", &tasks[i].end_month);

            if (tasks[i].end_month <= 0 || tasks[i].end_month > 12) {
                error();
            }

            // Number of dependencies (0 = skip, else iterate for number of dependencies entered)
            printf("Please enter how many dependencies this task has:\n");
            scanf(" %d", &tasks[i].numbOfDepen);
            if (tasks[i].numbOfDepen > 0) {
                for (j = 0; j < tasks[i].numbOfDepen; j++) {
                    printf("Enter the dependent task:\n");
                    scanf(" %d", &tasks[i].dependencies[j]);
                }

                //dependencies_count(tasks[i].numbOfDepen);
            }


        }


    }

    char edit[5] = "edit";
    char test[5] = "test";
    char quit[5] = "quit";
    char choice[5];

    printf("If you wish to edit the Gantt please type ''edit'' / If you wish to run a test, type ''test'' or to\n"
           "exit, type ''quit'' and then press enter to execute your option.\n");
    scanf(" %s", &choice);

    if (strcmp(choice, edit) == 0) {
        struct Task New_tasks[MAX_TASKS];
        char name[MAX_LENGTH];

        /*
        if (strcmp(name, tasks[i].name) == 0) {
            printf("Please enter the new task name or write its old one\n");
            scanf(" %s", &New_tasks[i].name);

            printf("Start month (1-12):\n");
            scanf(" %d", &New_tasks[i].start_month);

            printf("End month (1-12):\n");
            scanf(" %d", &New_tasks[i].end_month);

            printf("Enter how many dependencies this task has:\n");
            scanf(" %d", &New_tasks[i].numbOfDepen);
            */
        if (tasks[i].numbOfDepen > 0) {
            for (j = 0; j < tasks[i].numbOfDepen; j++) {
                printf("Enter the dependent task:\n");
                scanf(" %d", &New_tasks[i].dependencies[j]);

                // for loop to go through each and every task until input = name of task
                // return i - 1 when done (still increments 1 after the condition statement)

                // this shouldn't work
                if (strcmp(tasks[i].name, name) != 0) {
                    printf("Please enter the new task name or write its old one\n");
                    scanf(" %s", &tasks[i].name);

                    printf("Start month (1-12):\n");
                    scanf(" %d", &tasks[i].start_month);

                    printf("End month (1-12):\n");
                    scanf(" %d", &tasks[i].end_month);

                    printf("Enter how many dependencies this task has:\n");
                    scanf(" %d", &tasks[i].numbOfDepen);
                    if (tasks[i].numbOfDepen > 0) {
                        for (j = 0; j < tasks[i].numbOfDepen; j++) {
                            printf("Enter the dependent task:\n");
                            scanf(" %d", &tasks[i].dependencies[j]);
                        }
                    }
                } else if (strcmp(choice, test) == 0) {
                    printf("test");
                } else if (strcmp(choice, quit) == 0) {
                    printf("quit");
                }


            }
        }
    }
}





/*void print_chart(struct Task tasks[], int numTasks) {
    int months = 12;

    printf("---------------------------------------------------------------------------------------------");
    printf("|%-20s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s", "Task", "Jan", "Feb",
           "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec", "Dependencies");
    printf("---------------------------------------------------------------------------------------------");

    for (int i = 0; i < numTasks; i++) {
        printf("|%-20s|", tasks[i].name);

        for (int j = 0; j < months; j++) {
            if (j>=0 && j<=12)
            {
                printf(" X ");
            }
            else
            {
                printf("   ");
            }
        }

    }
}*/


/*
....................................................................................................
....................................................................................................
...............................................       ..............................................
.........................................''......              .....................................
................................',;::clloodddddolc::;,'....        .................................
..........................  ..':loodxkkO00KKKXXXXKKK0OOxdolc,''..    ...............................
........................    .,:clodkOOO00KKKXXXXNNNNXXXXKKKKKKKko:'.   .............................
........................  .';codddoolldxk0KXNNNNNWNNNNNNXKKKXNNNKOxc.   ............................
....................    ..;codkxlcloxO0KKXNNWWWWWWWWWWWWWNNKO0NWWNKkc.    ..........................
........................;ox0KOoclxKXNNNNWWWWWWWMMMMMMMMWMMMMWNNWMMWN0o'    .........................
.................   ..'cx0KXKkdxOKKNNNNWWWWWWWMMMMMMMMMMMMMMMMWWWMMMWXk;     .......................
....................':ok00KKOxxxkO0KXXNWWWWMWWMMMMMMMMMMMMMMMMMMMMMMWWXx;.    ......................
...................';lxkdldxoccoxO00KXNWWWWWWMMMMMMMMMMWWWWMWWMMMMMWWWNKd,       ...................
..................,cldo:''c:..:oxO000XNNWWWWWWMMMMMMMMWWWWWWWWWMMWWWWWWWXx;..       ................
................';cloc,...:;  'lxk0KKXNNNNWWWWWWWMMWWWWWWWWWWWWWWWNXNNWWWWXOxc'.      ..............
............    .':col:;:;;'  .cxOKXNNWWNWWWWWWWMMMMWWWWWWNNNNXXNXXXXNWNWWWWNXko;.      ............
............     .',;:lddc,.  .cdxxk0XNNNNNXXNNNNXXXXNNWWWNNXXK0O0XXNNWNNWWNNXKOko,      ...........
............     . .cxOkl,.   .'....'cdkkxxolllc:,,,:oO0KXXXXXX0ddOKXXNNNXNWNN0kddd:.    ...........
..............     .lOK0o'       ...   ..'::.     .'lxxxdloxO0KXOlck00O0XNNWWNXOxool,     ..........
.............      .okdoc.        ..     .xXO:.   ...,;;,,,cdOKX0dloddodO0KKXXX0xl:lc.    ..........
.............      .cc,;;,.       ...',..:0WNXkl;,;:lxOOkdodO0KKkoccccclxkxxxkkxddllc'.   ..........
.............. ........''.    ..';cllodookXWWWWWX0000XNNWNNNXKK0xdoc'.'cdxo:;:c,:cc;...   ..........
...................'',;;;.   .:oxO000kdcdKWMWWWNNWWWWWWWWWWNX0Oxc:;'..,ldxdl,''.',;'      ..........
...............  ..';cl:;.    :x000Oxc'.,xXNXKXXOkOKNWMMWWNNX0ko,,;....':clc:,......      ..........
...............   ..,,,,'.    'okOkdl;.  .,;'.,lkOkkxkKNWWNXKKkc',c::;,'..,;,,'          ...........
...............   .....'..     .;::;'.          ,ldoc;ckKXXKKOdc;;llc;;:;......          ...........
......................,::;'.                     .......lkOOkxdxkoldl,... ..           .............
....................,clclc;.                            .:odc;lxxxkOko:'.  ..         ..............
.................'..,;,,,'.                .            ..;ll;;:coxxxxdl'            ...............
..................',,,'....                ..              .lollllooodxx:.          ................
..................',,,,',;;'.       ....'..                .ckOOxdxddxxko;.        .................
......................,cxdc;,,. ...':llodl;',::,,,;;,:c,.'cccdOKK0KK0KXKxc:,.      .................
.....................;loddlcodl:llodxkxollodkO00KKKKK0Oxoooodk0XNXK0O0KXKOkd;.     .................
.................''.,okxoodoxxdddodxkOkddxk0OOKNWWNWNXKKkdodk0XNNNXKKKXXXKOxd;    ..................
................',;codol;:dddxxkkkO0OOxloxdodk0NNNXXXKKXK0kkOkOXNWWXXNNNNKOko:.   ..................
................'':oddoocclcldxkO000Oxddxkdok0KNNNXNXKKXXXXK0OO0XWWWWWWNNXKk,... ...................
................',;cllooloolldxkO0OkxxxxkkxxkO0XNNXXXKKXXXKXXKK00XNMMMMNKKKxc'.  ...................
.....................;lllollddxxxkOkxxdddxxdxOKXKKKXXXKKXXXXK0KK0KNWWWMXOOx,..    ..................
.......               .,;loddddxkkkxxdodddooxk0XKKKXXXK0KXXX00KKKXXK00XK0k'           ..............
                        .:dxddxxkxdooccddoodxk0XK0O0XXK0KXNNK0KKK00o,',,;;.               ..........
                         .'cdxxkkkxoodldxxxxkOKK0OOO0KK0KKXK0Oxodxxc.                          .....
                          .,coxkkkkxxdldxdxxxkO0OO0OxxOOxxxdc,.  .;;.                             ..
                        .:ddc:dkxxxxkxxkdooddxxOX0kdc;;'....
                       ;kXXKdlxkxdxkkkOOkxkkO0KX0l;'..                                             .
                     .oXWWWNOOXKKKK0000K00KKXNNO;.                                   ..           .
                    ,OWMMMMWXXWWWWWWWNNWWWWWMWx.                                   .',.         ..
                  .oXMMMMMMWNWMMMMMMMMMMMMMMNo.                                  ..,;,.      ..'.
                 .xWMMMMMMMMWWMMMMMMMMMMMMMXl.                       ...         .'...     .',;,.
                ,OWMMMMMMMMMWMMMMMMMMMMMMW0:.                       ...         ...      .',,::;''..
              'dKWMMMMMMMMMMMMMMMMMMMMMMWk'             ..          ..        ....     ..,;'........
            .lKWMMMMMMMMMMMMMMMMMMMMMMMWx...           ..............       ....      ...''.
           .dNMMMMMMMMMMMMMMMMMMMMMMMMWx'..           .........'','''...   ....       .','.    .''''
          .xNMMMMMMMMMMMMMMMMMMMMMMMMNd.             ..'.....'''',,,,..   ....         ',.     ..','
         'kWMMMMMMMMMMMMMMMMMMMMMMMMNo.              ..'..''','',,,'.  .......        ..        .'.
        ,kWMMMMMMMMMMMMMMMMMMMMMMMMXl.               ..''''''''',,'.   .','..        ..      ..'..
      .,kWMMMMMMMMMMMMMMMMMMMMMMMWK:.             ....'',,,,,,,,'.  .....'..        ..     ....
     .,xWMMMMMMMMMMMMMMMMMMMMMMMWO,                 ....'',;,;,'.  ..''....         ..   ...  .
    .,dNMMMMMMMMMMMMMMMMMMMMMMMM0;              ...........;;,.  ...''...          ..   ..  ...   .'
*/
