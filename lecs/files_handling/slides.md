---
theme: default
class: 
    - lead
    - invert
size: 4:3
paginate: true
marp: true
---
# Comp. Prog.
## File Handling

---

# Opening/Closing a file

```c
/* File pointer to hold reference to our file */
FILE * fPtr;
/* 
* Open file in w (write) mode. "data/file1.txt" 
is complete path to create file
*/
fPtr = fopen("data/file1.txt", "w");
/* fopen() return NULL if last operation 
was unsuccessful */
if(fPtr == NULL)
{
    /* File not created hence exit */
    printf("Unable to create file.\n");
    exit(0);
}
/* Done with this file, close file 
to release resource */
fclose(fPtr);
```

---
# Reading from file

- `fgetc()` – Used to read single character from file.
- `fgets()` – Used to read string from file.
- `fscanf()` – Use this to read formatted input from file.
- `fread()` – Read block of raw bytes from file. Used to read binary files.

---
# Reading

- Open a file using `fopen()` function and store its reference in a `FILE` pointer say `fPtr`.
- You must open file in `r`(read) mode or atleast mode that support read access.

- Read content from file using any of these functions `fgetc()`, `fgets()`, `fscanf()` or `fread()`.
Finally, close the file using `fclose(fPtr)`.

---


# Reading from file, char by char

```c
do {
    /* Read single character from file */
    ch = fgetc(fPtr);
    /* Print character read on console */
    putchar(ch);
} while(ch != EOF); /* Repeat this 
if last read character is not EOF */
```

---
# Reading line by line using `fgets()`

```c
char * fgets(char * str, int num, FILE * stream);
```

```c
char buffer[BUFFER_SIZE];
int totalRead = 0;

/* Repeat this until read line is not NULL */
while(fgets(buffer, BUFFER_SIZE, fPtr) != NULL) 
{
    /* Total character read count */
    totalRead = strlen(buffer);
    /*
     * Trim new line character from last if exists.
     */
    buffer[totalRead - 1] = 
      buffer[totalRead - 1] == '\n' 
                  ? '\0' 
                  : buffer[totalRead - 1];
    /* Print line read on cosole*/
    printf("%s\n", buffer);
}
``` 

---
# Reading numbers from a file
```c
int fscanf( FILE * stream, const char * format, ... );
```

```c
fprintf(fPtrPrime, "%d\n", num);
```