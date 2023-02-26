//***************************************************************
// Description: 
// File Name: ex31.c
// Author: Haoran Geng
// Email: 
// Created Time: Sun 26 Feb 2023 07:35:38 PM CST
// Revision history:
//***************************************************************
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;

    while(i < 100) {
        usleep(3000);
        /* i++; */
    }

    return 0;
}
