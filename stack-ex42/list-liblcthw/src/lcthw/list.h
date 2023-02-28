//***************************************************************
// Description: 
// File Name: list.h
// Author: Haoran Geng
// Email: 
// Created Time: Sun 26 Feb 2023 08:07:23 PM CST
// Revision history:
//***************************************************************
#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

// create a list struct
List *List_create();
// ruin the list
void List_destroy(List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);

// count number of items in linkedlist
#define List_count(A) ((A)->count)
// return first item of the list
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
// return last item of the list
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

// very fast. push item to the last of the list
void List_push(List *list, void *value);
// rm the last item and return it
void *List_pop(List *list);

// very fast. puth item to the first of the list
void List_unshift(List *list, void *value);
// remove the first item and retunr it
void *List_shift(List *list);

void *List_remove(List *list, ListNode *node);

// traverse the list
// -------------------------------------------------------------------------
// example: LIST_FOREACH(list, first, next, cur)
// -------------------------------------------------------------------------
// will be expanded as
// -------------------------------------------------------------------------
// ListNode *_node = NULL;
// ListNode *cur = NULL;
// for(cur = _node = list->first; _node != NULL; cur = _node = _node->next)
// -------------------------------------------------------------------------
// Note: list->first, node->next. 
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif

