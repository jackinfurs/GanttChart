/*  COMP10050 Assignment 2
    Group BO:
	    Martina D’Argenzio	22789139
        Jack Dunne		22483576
    https://csgitlab.ucd.ie/jack-dunne626/bo-assignment-2.git
*/

#include <stdio.h>
#include "definitions.h"
// definitions for MAX_LENGTH, EMPTY, MAX_TASKS

struct Task
{
    char name[80];
    int start_month;
    int end_month;
    int dependencies;
};

int main() {
    struct Task tasks[MAX_TASKS];
    int numOfTasks;
    int i, j;

    printf("Welcome to the Gantt Generator\n");


    printf("How many tasks would you like to add ? (1-10)\n");
    scanf("%d", &numOfTasks);

    for (i = 0; i < numOfTasks; i++)
    {
        printf("Please enter the name of task %d:\n", i + 1);
        scanf("%s", tasks[i].name);

        printf("Please enter the start month (1-12):\n");
        scanf("%d", tasks[i].start_month);

        printf("Please enter the end month (1-12):\n");
        scanf("%d", tasks[i].end_month);

        printf("Please enter how many dependencies this task has:\n");
        scanf("%d", tasks[i].dependencies);

    }

}

void print_chart(struct Task tasks[], int numTasks) {
    int months = 12;

    printf("---------------------------------------------------------------------------------------------");
    printf("|%-20s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s|%-10s|-%10s", "Task", "Jan", "Feb",
           "March", "April", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec", "Dependencies");
    printf("---------------------------------------------------------------------------------------------");

    for (int i = 0; i < numTasks; i++)
    {
        printf("|%-20s|", tasks[i].name);

        for (int int j = 0; j < months; j++)
        {
            if ()
        }

    }



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
}
