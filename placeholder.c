//
// Created by Martina on 15/03/2023.
//

#include "placeholder.h"
#include "struct.c"

struct Task task1 = {
        .name = "task_1",
        .start_month = 1,
        .end_month = 2,
        .dependencies = 0
};

struct Task task2 = {
       .name = "task_2",
       .start_month = 1,
       .end_month = 4,
       .dependencies = 0
};

struct Task task3= {
        .name = "task_3",
        .start_month = 3,
        .end_month = 5,
        .dependencies = 1
};

struct Task task4 = {
        .name = "task_4",
        .start_month = 2,
        .end_month = 4,
        .dependencies = 2
};

struct Task task5 = {
        .name = "task_5",
        .start_month = 4,
        .end_month = 5,
        .dependencies = 1
};

struct Task task6 = {
        .name = "task_6",
        .start_month = 6,
        .end_month = 7,
        .dependencies = 3,4
};

struct Task task7 = {
        .name = "task_7",
        .start_month = 7,
        .end_month = 7,
        .dependencies = 4
};

struct Task task8 = {
        .name = "task_8",
        .start_month = 8,
        .end_month = 9,
        .dependencies = 6
};

struct Task task9 = {
        .name = "task_9",
        .start_month = 8,
        .end_month = 10,
        .dependencies = 4
};

struct Task task10 = {
        .name = "task_10",
        .start_month = 11,
        .end_month = 12,
        .dependencies = 7,8
};



