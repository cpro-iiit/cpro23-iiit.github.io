---
title: "Tutorial - 1"
bookHidden: false
---
# Tutorial 1 (Week of 14 August)

## Theory

### Introduction to how compilation works in C

We all know that computer is incapable of reading and understanding the code we write in its native form. This means that the code needs to be converted in a form which the
machine can understand. The machine only understands Binary code. Thus, there should be a process by which the code we write can be converted to
Binary form. This process is known as compilation. You can think of compilation to be similar to translation (For eg: Let’s say you know English but you are
with someone who only understands French. This situation would require a translator! This is exactly what a compiler does. It acts as a translator!).

There are various stages in which the code is converted from C-language into binary for the computer to understand it:

1. **Preprocessing**:  All headers files starting with “#include” are processed in this phase. (Several other forms of processing including the removal of comments also happen at this stage). This generates a .i file 
2. **Compiling**: For now, assume it to be an intermediate process of conversion from .i to .s file. The .s file (known as an assembly file) is a set of commands which our machine knows to execute.
3. **Assembly**: Code is converted into machine-understandable code by the assembler. The file output is known as .o/.obj file. 
4. **Linking**: links library files(eg: stdio.h, math.h etc) to the object file to produce the a.out file, which is a binary executable of the program that was supplied as input.

Finally, we execute the `a.out` file to get the desired output.

{{<hint info>}}
Note: At this stage of the course, it is fine if the process is not entirely clear. It would become more clear in future courses (CSO for CXX students for example). The previous section just acts as a glimpse into compilation as a process being a series of smaller sub-processes.
{{</hint>}}

### Return values of `scanf` and `printf` function

`scanf()` and `printf()` are both part of the standard I/O library in C. They are used for taking input from the user, printing output etc. It's important to notice that these functions have a certain return value.

`scanf()` function returns the number of inputs that have been read.

**Example:**

```cpp
int a;
int rval = scanf("%d", &a);
printf("%d", rval);
```

The above snippet of code would print `1` as its output. This is because it's reading only `1` argument. If the number of arguments increases, then the return value would change similarly.

Similarly, `printf()` function returns the number of characters written.

```cpp
int rval = printf("Hello world!");
printf("%d", rval);
```

The above snippet would print `12` as its output.

---

