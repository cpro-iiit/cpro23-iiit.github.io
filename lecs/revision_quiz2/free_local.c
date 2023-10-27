#include "stdlib.h" 

int i = 100;

int main() {
    int* j = &i;
    free(j);
    return 0;
}