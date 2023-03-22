//
// Created by dynam on 22/03/2023.
//

#ifndef BOASSIGNMENT2_STRUCT_H
#define BOASSIGNMENT2_STRUCT_H

#define MAX_LENGTH  32
#define MAX_TASKS   10

enum months {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
};

struct Task {
    char name[MAX_LENGTH];
    int startMonth;
    int endMonth;
    int numOfDepen;
    int dependencies[MAX_TASKS];
};

#endif //BOASSIGNMENT2_STRUCT_H
