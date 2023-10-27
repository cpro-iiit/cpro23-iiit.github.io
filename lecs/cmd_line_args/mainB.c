/// Command Line Arguments

#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("The number of arguments is %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("%d Argument: \t%s\n", i, argv[i]);
    }

    return 0;
}

// Write a program that takes 3 commandline arguments
// and prints its as follows
// First Name: <first arg>
// Last Name : <sec arg>
// Age       : <third arg>