---
title: "Week - 1"
bookHidden: false
---
# Practice problems for week - 1 (Week of 14 August)

None of the following problems require a knowledge of loops, conditional statements etc.

## Question 1

### Problem Description

Keval has forgotten the password to his I-Pad. The password is a **4-digit** number where each digit takes a value from **0 to 9**. The good thing is that Keval
remembers that his password had exactly two unique digits, and each of these digits appeared exactly twice in the password. Keval also remembers
that `n` digits (where, {{<katex inline>}} 0 \le n \le 10 {{</katex>}}) from 0-9 were definitely not used in the password. 

Find the number of different possible passwords Keval could have.

{{<hint info>}}
Note that the password can start with the digit 0
{{</hint>}}

### Input constraints 

{{<katex block text-center>}}
0 \le n \le 10
{{</katex>}}

### Input format

The only line of input contains a single integer `n`, the number of digits which were not used in the password

### Output Format

Output a single integer that denotes the number of possible password sequences.

### Sample input and output

| Sample Input | Sample Output |
| ------------ | ------------- |
| `1`         | `216`       |

---

## Question 2

### Problem Description

You are given two integers `x` and `y`. Output the minimum integer `z`, such that `x | z = y`. Here, "`|`" denotes the [bitwise-OR operator](https://en.wikipedia.org/wiki/Bitwise_operation#OR)

### Input constraints 

{{<katex block text-center>}}
1 \le x, y \le 10^9
{{</katex>}}

### Input format

The only line of input contains two space-separated integers `x` and `y`

### Output Format

Output a single integer that denotes `z` as described in the problem statement

### Sample input and output

| Sample Input | Sample Output |
| ------------ | ------------- |
| `1 3`         |`2`       |

---

## Question 3

### Problem Description

Reverse a 4-digit number using the modulo operator.

### Input constraints 

The input would be a valid 4-digit number (i.e. no leading zeroes would be present)

### Input format

The only line of input contains a single integer `n`

### Output Format

Output a single integer which denotes the reverse of the `n`. Note that the output may have leading zeroes.

### Sample input and output

| Sample Input | Sample Output |
| ------------ | ------------- |
| `3214`         |`4123`       |
| `5600`         |`0065`       |

---

## Question 4

### Problem Description

Given a time as input in `hh:mm:ss` format, print the total number of minutes which have passed in the day.

### Input format

The only line of input would contain the time in `hh:mm:ss` format (24-hour clock)

### Output Format

Output the total number of minutes that have passed. Note that this may not be an integer.

### Sample input and output

| Sample Input | Sample Output |
| ------------ | ------------- |
| `13:40:30`         |`820.5`       |

---

## Question 5

### Problem Description

*Kishore is a very strange boy. He keeps solving weird problems and is now stuck on one such question. Please help him solve it.*

Given an integer `n`, you need to find the number of **ordered** pairs of integers `(a, b)` such that, {{<katex inline>}} 1 \le a \le b \le n {{</katex>}} and

{{<katex block text-center>}}
\frac{lcm(a, b)}{gcd(a, b)} \le 3
{{</katex>}}

In this problem, `gcd(a, b)` denotes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of the numbers `a` and `b`, and `lcm(a, b)` denotes their [lowest common multiple](https://en.wikipedia.org/wiki/Least_common_multiple).

### Input constraints 

{{<katex block text-center>}}
1 \le n \le 10^8
{{</katex>}}

### Input format

The only line of input contains a single integer `n`

### Output Format

Output a single integer that denotes the number of pairs `(a, b)` that satisfy the given constraints

### Sample input and output

| Sample Input | Sample Output |
| ------------ | ------------- |
| `5`         |`9`       |

---
