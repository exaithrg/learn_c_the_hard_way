//***************************************************************
// Description: 
// File Name: list_algos.c
// Author: Haoran Geng
// Email: 
// Created Time: Mon 27 Feb 2023 03:00:31 PM CST
// Revision history:
//***************************************************************
#include "list_algos.h"

// Example: bubble sort with function pointer
// int *bubble_sort(int *numbers, int count, compare_cb cmp)
// {
//     int temp = 0;
//     int i = 0;
//     int j = 0;
//     int *target = malloc(count * sizeof(int));
// 
//     if(!target) die("Memory error.");
// 
//     memcpy(target, numbers, count * sizeof(int));
// 
//     for(i = 0; i < count; i++) {
//         for(j = 0; j < count - 1; j++) {
//             if(cmp(target[j], target[j+1]) > 0) {
//                 temp = target[j+1];
//                 target[j+1] = target[j];
//                 target[j] = temp;
//             }
//         }
//     }
// 
//     return target;
// }

int List_bubble_sort(List *list, comp_ll cmp){
    return 0;
}

List *List_merge_sort(List *list, comp_ll cmp){
    return 0;
}
