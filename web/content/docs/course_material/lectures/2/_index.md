---
title: "02 Constants, Data Types, Expressions"
bookHidden: false
marp: true
header: 'CS0.101 Computer Programming (Monsoon 24)'
footer: '![width:100px](IIIT_Hyderabad_Logo.jpg)'
---

# C Programming Basics 
_Constants, Data Types, Expressions_


__Girish Varma__

code: https://github.com/cpro-iiit/cpro-iiit.github.io/tree/main/web/content/docs/course_material/lectures/2/code

code in web editor: https://www.programiz.com/online-compiler/7vCJDbICMawSj

---



<div style="max-width: 640px"><div style="position: relative; padding-bottom: 56.25%; height: 0; overflow: hidden;"><iframe src="https://iiitaphyd-my.sharepoint.com/personal/rc-support_iiit_ac_in/_layouts/15/embed.aspx?UniqueId=ffcf6f47-d379-4c7b-bb4d-9c07610ab638&embed=%7B%22ust%22%3Atrue%2C%22hv%22%3A%22CopyEmbedCode%22%7D&referrer=StreamWebApp&referrerScenario=EmbedDialog.Create" width="640" height="360" frameborder="0" scrolling="no" allowfullscreen title="Computer Programming _ SH-2 (09.35AM-10.30AM)-20240807_051307-Meeting Recording.mp4" style="border:none; position: absolute; top: 0; left: 0; right: 0; bottom: 0; height: 100%; max-width: 100%;"></iframe></div></div>



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

# Constants, Datatypes, Expressions

---
## Constants


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

Try out code online:
https://www.programiz.com/online-compiler/7vCJDbICMawSj 

---

## Data Types


| Type             |C Type     |Memory   |
|------------------|:---------:|--------:|
| Integer          |  int      | 32 bits |
| Real Number      |  float    | 32 bits  |
| Character        |  char     |  8 bits |



---

## Expressions
```c
printf("circumference is %f", 2*3.14*5);
```

Try out code online:
https://www.programiz.com/online-compiler/7vCJDbICMawSj 

---

## Reading 


Chapter 2
Computer Science: A Structured Programming Approach Using C    
Behrouz A. Forouzan, Richard F. Gilberg


---


# Thanks
