---
title: "Lab - 2"
bookHidden: false
---
# Lab 2 (Week of 21 August)

## Question 1

### Problem Description

Given an integer which has `n` digits, print `YES` if it is divisible by 3, and `NO` otherwise.

{{<hint info>}}
Note: The input number will not contain any leading zeroes.
{{</hint>}}

<!-- [Link to problem on OJ]() -->

### Input constraints 

{{<katex block text-center>}}
0 \le n \le 1000
{{</katex>}}

### Input format

The first line of input contains a single integer `n` denoting the number of digits.

The second line of input contains the integer which is `n` digit long.

### Output Format

Output `YES` if the number is divisible by 3 and `NO` otherwise.

### Sample input and output


| Sample Input | Sample Output |
| ------------ | ------------- |
| `10` <br> `1234567890` | `YES`       |
| `2` <br> `22` | `NO`       |

---

## Question 2

### Problem Description

You are given three non-negative integers `x`, `y` and `k` where {{<katex block text-center>}}
0 \le k \le 31{{</katex>}}. 
Replace the first `k` bits (from the right) of `x` with the first `k` bits of `y` and print the new value of `x`. In other words, replace the `k` least significant bits of `x` with the corresponding bits from `y`.

<!-- [Link to problem on OJ]() -->

### Input constraints 

{{<katex block text-center>}}
0 \le x,y \le 2^{31}
{{</katex>}}
<br>
{{<katex block text-center>}}
0 \le k \le 31
{{</katex>}}

### Input format

The only line of input contains 3 space-separated integers `x`, `y` and `k`.

### Output Format

Output a single integer denoting the new value of `x`

### Sample input and output

| Sample Input | Sample Output |
| ------------ | ------------- |
| `11` `22` `3`| `14`          |

---
