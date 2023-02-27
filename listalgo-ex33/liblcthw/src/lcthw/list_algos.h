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

#include <stdlib.h>
#include "list.h"

// function pointer, compare_linklist
typedef int (*comp_ll)(const char *s1, const char *s2);

int List_bubble_sort(List *list, comp_ll cmp);
List* List_merge_sort(List *list, comp_ll cmp);

#endif
