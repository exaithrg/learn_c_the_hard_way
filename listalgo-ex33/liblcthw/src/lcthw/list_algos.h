//***************************************************************
// Description: 
// File Name: list_algos.h
// Author: Haoran Geng
// Email: 
// Created Time: Mon 27 Feb 2023 02:48:42 PM CST
// Revision history:
//***************************************************************

#ifndef lcthw_List_Algos_h
#define lcthw_List_Algos_h

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Reference
// struct ListNode;
// 
// typedef struct ListNode {
//     struct ListNode *next;
//     struct ListNode *prev;
//     void *value;
// } ListNode;
// 
// typedef struct List {
//     int count;
//     ListNode *first;
//     ListNode *last;
// } List;

// function pointer, compare_linklist
typedef int (*comp_ll)(const char *s1, const char *s2);

void swap_list_item(ListNode *first, ListNode *last);
int List_bubble_sort(List *list, comp_ll cmp);
List* List_merge_sort(List *list, comp_ll cmp);

#endif
