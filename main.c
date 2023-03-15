/*  COMP10050 Assignment 2
    Group BO:
	    Martina D’Argenzio	22789139
        Jack Dunne		    22483576
    https://csgitlab.ucd.ie/jack-dunne626/bo-assignment-2.git
*/

#include <stdio.h>
#include "definitions.h"
#include "struct.h"
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

int main() {
    struct Task tasks[MAX_TASKS];
    int numOfTasks;
    int i, option;

    printf("Welcome to the Gantt Generator\n");
    printf("Would you like to use the test example (1) or create your own Gantt from scratch (2)?\n");
    scanf("%d", &option);
    if (option != 0 && option != 1)
    {
        printf("Invalid options\n");
    }

    if (option == 1)
    {
        // pre-generated
    } else if (option == 2) {

        // Create own series of tasks: using a struct with name, start/end month, and dependencies

        // How many tasks? (0 invalid, else iterate for number of tasks entered)
        printf("How many tasks would you like to add ? (1-10)\n");
        scanf("%d", &numOfTasks); // using scanf, no need to worry about buffer overflow in 1st year project
        if (numOfTasks < 1 || numOfTasks > 10)
        {
            printf("Invalid value\n");
        }

        for (i = 0; i < numOfTasks; i++) {
            // Task name
            printf("Please enter the name of task %d:\n", i + 1);
            scanf("%s", tasks[i].name);

            // Start/end month (input <= 0 or > 12, invalid input)
            printf("Please enter the start month (1-12):\n");
            scanf("%d", &tasks[i].start_month);

               if (tasks[i].start_month <= 0 || tasks[i].start_month > 12)
               {
                   printf("Invalid value\n");
               }

            // Start/end month (input <= 0 or > 12, invalid input)
            printf("Please enter the end month (1-12):\n");
            scanf("%d", &tasks[i].end_month);

                if (tasks[i].end_month <= 0 || tasks[i].end_month > 12)
                {
                    printf("Invalid value\n");
                }

            // Number of dependencies (0 = skip, else iterate for number of dependencies entered)
            printf("Please enter how many dependencies this task has:\n");
            scanf("%d", &tasks[i].dependencies);

        }

    }

}

/*
void print_chart(struct Task tasks[], int numTasks) {
    int months = 12;

    printf("---------------------------------------------------------------------------------------------");
    printf("|%-20s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s", "Task", "Jan", "Feb",
           "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec", "Dependencies");
    printf("---------------------------------------------------------------------------------------------");

    for (int i = 0; i < numTasks; i++) {
        printf("|%-20s|", tasks[i].name);

        for (int int j = 0; j < months; j++) {
            if ()
        }

    }
}
*/

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
