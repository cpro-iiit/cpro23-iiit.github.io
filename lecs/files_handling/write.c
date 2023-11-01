#include <stdio.h>
#include <stdlib.h>



int main() {
    FILE* f;
    f = fopen("text1.txt", "w");


    float pi = 3.14;
    fputs("hello",f);

    fclose(f);

    char buffer[100];
    f = fopen("text1.txt", "r");


    for(int i = 0; i <10;i++) {

        char c = fgetc(f);
        printf("%c\n",c);

    }

    printf("%s", buffer);
    fclose(f);


    return 0;
}