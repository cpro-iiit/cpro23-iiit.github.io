#include <stdio.h>
#include <stdlib.h>



int main() {
    FILE* f;
    f = fopen("text1.txt", "a");




    int a[] = {3, 2};
    fwrite(a,sizeof(int),2,f);

    fclose(f);
    return 0;
}