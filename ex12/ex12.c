//***************************************************************
// Description: 
// File Name: ex12.c
// Author: Haoran Geng
// Email: 
// Created Time: Sat 25 Feb 2023 08:13:42 PM CST
// Revision history:
//***************************************************************
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("You only have one argument. You suck.\n");
    } else if(argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else {
        printf("You have too many arguments. You suck.\n");
    }

    return 0;
}
