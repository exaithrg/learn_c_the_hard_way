//***************************************************************
// Description: 
// File Name: ex14.c
// Author: Haoran Geng
// Email: 
// Created Time: Sat 25 Feb 2023 08:40:47 PM CST
// Revision history:
//***************************************************************
#include <stdio.h>
#include <ctype.h>

// forward declarations
// solve egg/chicken problem
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;

    for(i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }
}

void print_letters(char arg[])
{
    int i = 0;

    for(i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];

        if(isprint(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[])
{
    print_arguments(argc, argv);
    return 0;
}
