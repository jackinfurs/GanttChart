//
// Created by Martina on 15/03/2023.
//

#include "struct.h"

typedef struct
{
    char name[MAX_LENGTH];
    int start_month;
    int end_month;
    int numbOfDepen;
    int dependencies[];
} Task;
Task placeholder[MAX_TASKS] = {
        {"task_1",  1,  2,  0, {0}},
        {"task_2",  1,  4,  0, {0}},
        {"task_3",  3,  5,  1, {0}},
        {"task_4",  2,  4,  2, {0, 1}},
        {"task_5",  4,  5,  1, {2}},
        {"task_6",  6,  7,  2, {3, 4}},
        {"task_7",  7,  7,  1, {4}},
        {"task_8",  8,  9,  1, {6}},
        {"task_9",  8,  10, 1, {4}},
        {"task_10", 11, 12, 2, {7, 8}}
};
