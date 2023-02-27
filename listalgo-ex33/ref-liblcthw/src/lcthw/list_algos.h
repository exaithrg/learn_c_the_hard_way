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

typedef int (*List_compare)(const void *a, const void *b);

int List_bubble_sort(List *list, List_compare cmp);

List *List_merge_sort(List *list, List_compare cmp);

#endif
