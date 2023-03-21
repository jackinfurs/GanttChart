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
Task placeholder[MAX_TASKS] = {{
                                .name = "task_1",
                                .start_month = 1,
                                .end_month = 2,
                                .numbOfDepen = 0,
                                .dependencies = {0}},
                               {"task_2",1,4,0,{0}},
                               {"task_3",3,5,1,{0}},
        {"task_4",2,4,2,{0, 1}},
        {"task_5",4,5,1,{2}},
        {"task_6",6,7,2,{3, 4}},
        {"task_7",7,7,1,{4}},
        {"task_8",8,9,1,{6}},
        {"task_9",8,10,1,{4}},
        {"task_10",11,12,2,{7,8}}};
Task task1 = {
        .name = "task_1",
        .start_month = 1,
        .end_month = 2,
        .numbOfDepen = 0,
        .dependencies = {0}
};

Task task2 = {"task_2",1,4,0,{0}};

Task task3= {"task_3",3,5,1,{0}};

Task task4 = {"task_4",2,4,2,{0, 1}};

Task task5 = {"task_5",4,5,1,{2}};

Task task6 = {"task_6",6,7,2,{3, 4}};

Task task7 = {"task_7",7,7,1,{4}};

Task task8 = {"task_8",8,9,1,{6}};

Task task9 = {"task_9",8,10,1,{4}};

Task task10 = {"task_10",11,12,2,{7,8}};
