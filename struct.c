#include "struct.h"
#include "definitions.h"

// using a struct with name, start/end month, and dependencies
struct Task
{
    char name[MAX_LENGTH];
    int start_month;
    int end_month;
    int dependencies;
};
