//***************************************************************
// Description: 
// File Name: list_algos.c
// Author: Haoran Geng
// Email: 
// Created Time: Mon 27 Feb 2023 03:00:31 PM CST
// Revision history:
//***************************************************************
#include "../dbg.h"
#include "list.h"
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

void swap_list_item(ListNode *first, ListNode *last){
    void *temp;
    temp = last->value;
    last->value = first->value;
    first->value = temp;
    return;
}

int List_bubble_sort(List *list, comp_ll cmp){
    // pointer list node i and j
    ListNode* plni;
    ListNode* plnj;
    for(plni = list->first; plni != NULL; plni = plni->next){
        for(plnj = list->first; plnj->next != NULL; plnj = plnj->next){
            if(cmp(plnj->value,plnj->next->value)>0){
                swap_list_item(plnj,plnj->next);
            }
        }
    }
#ifdef VERBOSE_PRINT
    int i=0;
    LIST_FOREACH(list,first,next,cur){
        printf("Bubble Node %d: value = %s\n",i,cur->value);
        i++;
    }
#endif
    return 0;
}

// Example: Top-down merge sort from wikipedia
// // Array A[] has the items to sort; array B[] is a work array.
// void TopDownMergeSort(A[], B[], n)
// {
//     CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
//     TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
// }

List *List_merge_sort(List *list, comp_ll cmp){
    int count = list->count;
    List *res = List_copy(list);
    List_top_down_split_merge(res, 0, count, list, cmp);
    List_destroy(res);
    res = List_copy(list);
#ifdef VERBOSE_PRINT
    int i=0;
    LIST_FOREACH(res,first,next,cur){
        printf("Merge Node %d: value = %s\n",i,cur->value);
        i++;
    }
#endif
    return res;
}

// // Split A[] into 2 runs, sort both runs into B[], merge both runs from B[] to A[]
// // iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
// void TopDownSplitMerge(B[], iBegin, iEnd, A[])
// {
//     if (iEnd - iBegin <= 1)                     // if run size == 1
//         return;                                 //   consider it sorted
//     // split the run longer than 1 item into halves
//     iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
//     // recursively sort both runs from array A[] into B[]
//     TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
//     TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
//     // merge the resulting runs from array B[] into A[]
//     TopDownMerge(B, iBegin, iMiddle, iEnd, A);
// }
void List_top_down_split_merge(List *lb, int iBegin, int iEnd, List *la, comp_ll cmp){
    if (iEnd - iBegin <= 1)                     // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    List_top_down_split_merge(la, iBegin,  iMiddle, lb, cmp);  // sort the left  run
    List_top_down_split_merge(la, iMiddle,    iEnd, lb, cmp);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    List_top_down_merge(lb, iBegin, iMiddle, iEnd, la, cmp);
    return;
}

// //  Left source half is A[ iBegin:iMiddle-1].
// // Right source half is A[iMiddle:iEnd-1   ].
// // Result is            B[ iBegin:iEnd-1   ].
// void TopDownMerge(A[], iBegin, iMiddle, iEnd, B[])
// {
//     i = iBegin, j = iMiddle;
//
//     // While there are elements in the left or right runs...
//     for (k = iBegin; k < iEnd; k++) {
//         // If left run head exists and is <= existing right run head.
//         if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
//             B[k] = A[i];
//             i = i + 1;
//         } else {
//             B[k] = A[j];
//             j = j + 1;
//         }
//     }
// }

ListNode* List_locnode(List *list, int pos){
    ListNode* ln;
    int i;
    for(i=0, ln=list->first; i<pos && ln!=NULL; ln = ln->next, i++);
    return ln;
}

void List_top_down_merge(List *la, int iBegin, int iMiddle, int iEnd, List *lb, comp_ll cmp){
    int i = iBegin;
    int j = iMiddle;
    int k = iBegin;
    
    // pointer list node a/b i/j/k
    ListNode* plnai = List_locnode(la, i);
    ListNode* plnaj = List_locnode(la, j);
    ListNode* plnbk = List_locnode(lb, k);

    // While there are elements in the left or right runs...
    while(k<iEnd){
        // If left run head exists and is <= existing right run head.
        // if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
        if (i < iMiddle && (j >= iEnd || cmp(plnai->value, plnaj->value) <= 0)) {
            plnbk->value = plnai->value;
            // B[k] = A[i];
            i = i + 1;
            plnai = plnai->next;
        } else {
            plnbk->value = plnaj->value;
            // B[k] = A[j];
            j = j + 1;
            plnaj = plnaj->next;
        }
        plnbk = plnbk->next;
        k++;
    }
    return;
}

// void CopyArray(A[], iBegin, iEnd, B[])
// {
//     for (k = iBegin; k < iEnd; k++)
//         B[k] = A[k];
// }
List* List_copy(List *srcl){
    List *destl = List_create();    
    LIST_FOREACH(srcl,first,next,cur){
        List_push(destl,cur->value);
    }
    return destl;
}

