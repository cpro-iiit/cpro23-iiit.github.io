---
title: "01 Introduction"
bookHidden: false
marp: true
header: 'CS0.101 Computer Programming (Monsoon 24)'
footer: '![width:100px](IIIT_Hyderabad_Logo.jpg)'
---

# Intro to C Progamming

__Girish Varma__

https://cpro-iiit.github.io/docs/course_material/lectures/2/07_08.pdf

---

## Hello World! C Program

`main.c` file. Try it out at https://www.programiz.com/c-programming/online-compiler/ 
```c
// 1. This line is a comment that is ignored by compiler.

// 2. include standard library for input/output. Allows to print to shell
#include <stdio.h> 

// 3. execution start inside this **function** named main. 
int main() 
{ // start of main function

    // 4. prints to the shell
    printf("Hello, world\n");
    return 0; /* 5. returns integer 0 */

} // end of main function
```

---

## Running the Program

1. Run gcc compiler to get executable file `main`
```gcc main.c -o main```
2. Run the executable `main`
```./main```

---
## What just happened?

![bg right:50% w:600](c_compilation.png)

---
## Using Makefile to do it together

1. Create a file `Makefile` (one time step)
```make
// Makefile
run: 
    gcc main.c -o main
    ./main
```

2. run `make run`

Next time, after you modify `main.c`, only `make run` needs to be done.

---

# Constants, Datatypes, Variables

---
## Constants

https://www.programiz.com/online-compiler/48tOa2UyvDuJH
```c
#include <stdio.h> 
int main() 
{ 
    printf("printing the integer constant %d\n", 1);
    printf("printing the integer constant %d\n", 100);
    
    printf("printing the float constant %f\n", 1.5);
    printf("printing the float constant %f\n", 15.6);

    return 0;
} 
```
---

## Data Types

int
float
char


---

## Variables



---

## Initializers


---

## Expressions

---
## Giving Input: scanf


---

## Reading 



Computer Science: A Structured Programming Approach Using C    
Behrouz A. Forouzan, Richard F. Gilberg


---


# Thanks
