---
title: "Practice problems"
bookHidden: false
---
# Practice Problems


## 1. Cycles in a permutation

Let $\pi:\\{1,\cdots, n\\} \rightarrow \\{1,\cdots, n\\}$ be permutation (that is a one-one onto function). 
The cycle containing 1 is the sequence of numbers
$$1\qquad \pi(1)\qquad \pi(\pi(i))\qquad \pi(\pi(\pi(1)))\qquad \cdots$$
Notice that the sequence is periodic (Why?)  and the period is called the size of the cycle containing 1. Similarly one can define the cycle containing 2, 3 etc. 
Write a program to take $n$ and a permutation of $\\{1,\cdots,n\\}$ as inputs and print all the cycles (you can stop at the period).    

For example:   
For input 4 and perumutation 2 3 4 1, it should output 1->2->3->4->1.  
For input 4 and perumutation 1 2 3 4, it should output 1->1, 2->2, 3->3, 4->4.  
For input 4 and perumutation 2 1 4 3, it should output 1->2->1, 3->4->3.  



## 2. Cycles in a LinkedList

In a linked list, its possible to have a cycle in the nodes. That is, while iterating through the nodes, a node could be there whose next pointer is pointing to a previous node. 

Write a C program which takes linked list as input and checks if it has a cycle.   

For example:  
On input linked list 1->2->3->4->5->6->3, the program should print true.  
On input linked list 1->2->3->4->5->6->NULL, the program should print false.    




