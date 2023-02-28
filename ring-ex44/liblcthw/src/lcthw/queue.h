//***************************************************************
// Description: 
// File Name: queue.h
// Author: Haoran Geng
// Email: 
// Created Time: Tue 28 Feb 2023 04:16:08 PM CST
// Revision history:
//***************************************************************

#ifndef lcthw_Queue_h
#define lcthw_Queue_h

#include <stdlib.h>
#include "list.h"

// Stack Implementation based on list

typedef List Queue;

#define Queue_create List_create
#define Queue_destroy List_destroy
#define Queue_clear List_clear
#define Queue_clear_destroy List_clear_destroy

#define Queue_send List_unshift
#define Queue_recv List_pop

#define Queue_peek List_last
#define Queue_count List_count

#define QUEUE_FOREACH(stack, cur) \
	ListNode *cur = stack->first;\
    for (ListNode *_node = stack->first; \
         _node != NULL; \
         cur = _node = _node->next)

#endif
