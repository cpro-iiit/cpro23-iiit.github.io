---
title: "01 Introduction"
bookHidden: false
marp: true
header: 'CS0.101 Computer Programming (Monsoon 24)'
footer: '![width:100px](IIIT_Hyderabad_Logo.jpg)'
---

# Welcome to CS0.101 Computer Programming

__Girish Varma__



---
## What this Course is about?

![bg right:50% w:500](code_spell.jpeg)

- Genie needs to be instructed precisely, otherwise it will not respond!

- It will precisely do, what you told it to do! If you meant something else and that was your problem.

- Genie only understand a language, which has no scope for confusion/ambiguity.

---

---
## How to ace this course?

12 Weeks Course (excluding exam/holiday/prep weeks) ​

| Session          |Time (hrs) |Marks (%)|
|------------------|:---------:|--------:|
| 3 Lectures       |  3 x 1    | -       |
| 1 Tutorial       |  1 x 1    | -       |
| 1 Lab            |  1 x 3    |    2    |
| Reading/Practice |  3        |         |
| Assignment       |  3        | 2.5     |


Total Time per week: 13 hrs  
Total Problem solving per week: 3 (Lab) + 2 (Tut) + 2 (Assgn) 2 (Practice) = 9

---
## Evaluation

| Component        |Marks (%)  |                |
|------------------|:---------:|---------------:|
| Lab              |  10 x 2   | Best 10 of *   |
| Assignments      |   6 x 5   | 6 in No.       |
| Mid Term         |   8 + 12  | Written + Lab  |
| End Sem          |  10 + 20  | Written + Lab  |


80% marks for programming problem solving.  
Solve 100 problems over the entire course.

---
## Websites

Course Website: https://cpro-iiit.github.io/
All lecture/lab/tutorial material is posted. Additional information, links to other courses/tutorials on the web.

Autolab Problem Server: https://pingala.iiit.ac.in/
All lab/assignment/tutorials problems released here. More about this in the lab.


---
## Basic Computer Organisation

![bg right:60% w:600](computer_organization.png)

---


---
## Programming Languages

![bg right:50% w:600](high-low-langs.png)

---

---
## Hello World! C Program
`main.c` file
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

1. Create a file `Makefile`
```make
// Makefile
run: 
    gcc main.c -o main
    ./main
```
2. run `make run`

---
## Tresure Hunt/Dumb charades!

- Dont be afraid to make guesses!
- Dont be afraid to try out guesses! 
- Failed guess gives clues. Learn from them!
- You will eventually learn to make more clever guesses.

---
## Reading 

Chapter 1 upto Section 1.4,  
Chapter 2 upto Section 2.2
Computer Science: A Structured Programming Approach Using C    
Behrouz A. Forouzan, Richard F. Gilberg


---

# Thanks
