#include <stdio.h>
#include <stdlib.h>



int main()
{
    /* File pointer to hold reference to different files */
    FILE * fPtr;
    fPtr = fopen("text.txt", "r");

    if (fPtr == NULL) {
        printf("Somethings wrong!\n");
        return 0;
    }

    float age;

    fscanf(fPtr,"Age: %f\n", &age);

    // int day;

    // fscanf(fPtr,"day: %d", &day);


    printf("The number is %f\n", age);

    fclose(fPtr);

    return 1;

}