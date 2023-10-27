/// Command Line Arguments

#include "stdio.h"

int main(int argc, char* argv[]) {

    printf("The number arguments is %d\n", argc);

    for(int i = 0; i < argc; i++) {
        printf("%d Argument: %s\n", i, argv[i]);
    }

    return 0;
 }

 // Write a program that takes the First Name Last Name Age 
 // as commandline arguments and prints it as follows
 // First Name: <first arg>
 // Last name : <sec arg>
 // Age       : <third arg>
