//***************************************************************
// Description: 
// File Name: stack.h
// Author: Haoran Geng
// Email: 
// Created Time: Tue 28 Feb 2023 04:15:50 PM CST
// Revision history:
//***************************************************************

#ifndef lcthw_Stack_h
#define lcthw_Stack_h

#include <stdlib.h>
// #include "list.h"
#include "darray.h"

// Stack Implementation based on list

typedef DArray Stack;

#define Stack_create() DArray_create(0,1)
#define Stack_destroy DArray_destroy
#define Stack_clear DArray_clear
#define Stack_clear_destroy DArray_clear_destroy

#define Stack_push DArray_push
#define Stack_pop DArray_pop
#define Stack_peek DArray_last

#define Stack_count DArray_count

#define STACK_FOREACH(stack, cur) \
    for (int cur=0; cur<stack->end; cur++) \

#endif

