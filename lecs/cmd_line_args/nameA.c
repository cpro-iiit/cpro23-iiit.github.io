/// Command Line Arguments

#include "stdio.h"

int main(int argc, char* argv[]) {
    
    if (argc != 4) {
        printf("Incorrect number of arguments provided.\n");
        return 0;
    }

    printf("First Name:\t%s\n", argv[1]);
    printf("Last Name :\t%s\n", argv[2]);
    printf("Age       :\t%s\n", argv[3]);
    return 0;
 }

 // Write a program that takes the First Name Last Name Age 
 // as commandline arguments and prints it as follows
 // First Name: <first arg>
 // Last name : <sec arg>
 // Age       : <third arg>
