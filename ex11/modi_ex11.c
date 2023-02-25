//***************************************************************
// Description: 
// File Name: ex11.c
// Author: Haoran Geng
// Email: 
// Created Time: Sat 25 Feb 2023 08:05:39 PM CST
// Revision history:
//***************************************************************
#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = argc-1;
    while(i >= 0) {
        printf("arg %d: %s\n", i, argv[i]);
        i--;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = 0;  // watch for this
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    // test using while to cp argv to states.
    i = 0;
    while (i<argc && i<num_states){
        states[i] = argv[i];
        i++;
    }
    printf("cp FINISH\n");
    i=0;
    while(i < num_states) {
        printf("state %d: %s\n", i, states[i]);
        i++;
    }

    return 0;
}
