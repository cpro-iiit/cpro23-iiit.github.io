
#include "stdio.h"
int main(int argc, char* argv[]) {
    printf("The number of arguments is %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%d Argument: %s\n", i, argv[i]);    
    }
    return 0;
}