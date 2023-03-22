#ifndef BO_ASSIGNMENT_2_STRUCT_H
#define BO_ASSIGNMENT_2_STRUCT_H

#include "definitions.h"

struct Task {
    char name[MAX_LENGTH];
    int start_month;
    int end_month;
    int numbOfDepen;
    int dependencies[MAX_TASKS];
};

#endif //BO_ASSIGNMENT_2_STRUCT_H
