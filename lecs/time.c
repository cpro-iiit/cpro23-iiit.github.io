#include <stdio.h>
#include <time.h>
 
int main(void)
{
    time_t now = time(NULL);
 
 
    int j;
    for (int i =0; i < 1000000;i++) {
        j++;
    }
    
    time_t later = time(NULL);
 
    double seconds = difftime(later, now);
 
    printf("%.10f seconds have passed since for running code.\n", seconds);
 
    return 0;
}