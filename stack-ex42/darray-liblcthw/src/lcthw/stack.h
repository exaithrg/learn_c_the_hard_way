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
#include "list.h"

// Stack Implementation based on list

typedef List Stack;

#define Stack_create List_create
#define Stack_destroy List_destroy
#define Stack_clear List_clear
#define Stack_clear_destroy List_clear_destroy

#define Stack_push List_push
#define Stack_pop List_pop
#define Stack_peek List_last

#define Stack_count List_count

#define STACK_FOREACH(stack, cur) \
	ListNode *cur = stack->first;\
    for (ListNode *_node = stack->first; \
         _node != NULL; \
         cur = _node = _node->next)

#endif
