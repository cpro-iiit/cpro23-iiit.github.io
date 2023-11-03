#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    srand(time(NULL)); // use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0,%d]: %d\n", RAND_MAX, random_variable);

    int x;
    int count[] = { 0,0,0,0,0,0};
    for (int i=0; i < 6000; i++) {
       x = 1+ rand()%6;
    //    printf("%d ", x); 
       count[x-1]++;
    }
    printf("%d %d %d %d %d %d\n", count[0], count[1], count[2], count[3], count[4], count[5]);

}