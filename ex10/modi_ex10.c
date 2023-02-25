//***************************************************************
// Description: 
// File Name: ex10.c
// Author: Haoran Geng
// Email: 
// Created Time: Sat 25 Feb 2023 07:50:30 PM CST
// Revision history:
//***************************************************************
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    // cuz argv[0] will be ./ex10
    printf("argv[0]=%s\n",argv[0]);
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    argv[1] = states[0];
    states[0] = NULL;


    printf("MODI FINISHED\n");
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
