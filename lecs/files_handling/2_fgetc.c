/**
 * C program to read a file and display file contents character by character using fgetc() 
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{

    if (argc != 3) {
        printf("Invalid args");
        exit(0);
    }

    /* File pointer to hold reference to our file */
    FILE * s =fopen(argv[1], "r");
    FILE* d = fopen(argv[2], "w")

    char ch;

    /* 
     * Open file in r (read) mode. 
     * "data/file1.txt" is complete file path to read
     */
    fPtr = fopen("text.txt", "r");


    /* fopen() return NULL if last operation was unsuccessful */
    if(fPtr == NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    /* File open success message */
    printf("File opened successfully. Reading file contents character by character. \n\n");

    do 
    {
        /* Read single character from file */
        ch = fgetc(fPtr);

        /* Print character read on console */
        putchar(ch);

    } while(ch != EOF); /* Repeat this if last read character is not EOF */

    /* Done with this file, close file to release resource */
    fclose(fPtr);

    return 0;
}