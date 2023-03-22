#include "struct.h"
#include "definitions.h"

struct Task {
    char name[MAX_LENGTH];
    int start_month;
    int end_month;
    int numbOfDepen;
    int dependencies[MAX_TASKS];
};
