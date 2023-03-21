#include "definitions.h"

/*struct Dependencies
{
    int dep1;
    int dep2;
    int dep3;
    int dep4;
    int dep5;
    int dep6;
    int dep7;
    int dep8;
    int dep9;
    int dep10;
};*/

// using a struct with name, start/end month, and dependencies
struct Task
{
    char name[MAX_LENGTH];
    int start_month;
    int end_month;
    int numbOfDepen;
    int dependencies [];
};
