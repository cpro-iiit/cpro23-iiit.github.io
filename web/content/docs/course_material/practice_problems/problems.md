---
title: "Problems"
bookHidden: false
---
# Practice Problems


## 1. Cycles in a permutation

Let $\pi:\\{1,\cdots, n\\} \rightarrow \\{1,\cdots, n\\}$ be permutation (that is a one-one onto function). 
The cycle containing 1 is the sequence of numbers
$$1\qquad \pi(1)\qquad \pi(\pi(1))\qquad \pi(\pi(\pi(1)))\qquad \cdots$$
Notice that the sequence is periodic (Why?)  and the period is called the size of the cycle containing 1. Similarly one can define the cycle containing 2, 3 etc. 
Write a program to take $n$ and a permutation of $\\{1,\cdots,n\\}$ as inputs and print all the cycles (you can stop at the period).    

For example:   
For input 4 and permutation 2 3 4 1 (ie $\pi(1) = 2, \pi(2) = 3, \pi(3) = 4, \pi(4) = 1$), it should output 1->2->3->4->1.  
For input 4 and permutation 1 2 3 4, (ie the identity permutation) it should output 1->1, 2->2, 3->3, 4->4.  
For input 4 and permutation 2 1 4 3 (ie $\pi(1) = 2, \pi(2) = 1, \pi(3) = 4, \pi(4) = 3$), it should output 1->2->1, 3->4->3.  



## 2. Cycles in a LinkedList

In a linked list, its possible to have a cycle in the nodes. That is, while iterating through the nodes, a node could be there whose next pointer is pointing to a previous node. 

Write a C program which takes linked list as input and checks if it has a cycle.   

Hint: You can add extra fields into the Node struct, for aiding this program.  

For example:  
On input linked list 1->2->3->4->5->6->3, the program should print true.  
On input linked list 1->2->3->4->5->6->NULL, the program should print false.    

## 3. Bank
Problems in the comments
```c
/* Build a program for managing a bank.
   There should be a database of bank
   accounts and transactions. We should
   be able to add new accounts, 
   new transactions (credit/debit) and 
   compute the balance of a account     */
#include <stdio.h>
#include <string.h>

typedef enum AccountType {
  Savings,
  Current
} AccountType;

typedef enum TransactionType {
  Credit,
  Debit
} TransactionType;

typedef struct Transaction {
  TransactionType type;
  struct BankAccount* account;
  int amount;
} Transaction;

typedef struct BankAccount {
  char name[100];
  int pin;
  AccountType type;
  // passbook is an array of transactions
  // pointers to avoid taking too much memory
  struct Transaction* passbook[1000]; 
  int transactions_count;
} BankAccount;

typedef struct BankDatabase {
  BankAccount accounts[1000];
  Transaction transactions[10000];
  int accounts_count;
  int transactions_count;
} BankDatabase;

// compute the total amount of money 
// with the bank amoung all the accounts
int compute_money_with_bank(
                      BankDatabase* db) {
  int sum = 0;  
  for(int i = 0; 
        i < db->transactions_count; i++) {
    switch(db->transactions[i].type) {
      case Credit:
        sum += db->transactions[i].amount;
        break;
      case Debit:
        sum -= db->transactions[i].amount;
        break;
    }  
  }
  return sum;
}

int compute_balance(BankAccount* acc) {
  // Problem 2 a.) fill in the code to 
  // find the balance of the account 
  // 'acc'.(3 marks)
}

BankAccount* add_bank_account(char* name, 
                    int pin, AccountType type,
                    BankDatabase* db) {
  // Problem 2 b.) fill in the code to add 
  // a new account 'acc' to the bank 
  // database 'db'. The function should 
  // also return a pointer to the bank 
  // account created in 'db'. (3 marks)
}

Transaction* add_transaction(
            TransactionType type, 
            BankAccount *account, 
            int amount, BankDatabase* db) {
  // Problem 2 c.) Fill in the code for 
  // adding a transaction to the system. 
  // The logic should be written such 
  // that the all the other functions in
  //  this program continue to work 
  // correctly. (4 marks)
}

int main() {

  BankDatabase db;
  db.accounts_count = db.transactions_count = 0;
  BankAccount acc = { .pin = 1234, 
                      .transactions_count = 0};
  strcpy(acc.name, "Ivan");
  BankAccount* acc_ptr = add_bank_account(
                 acc.name,acc.pin,acc.type, &db);
  add_transaction(Credit, acc_ptr, 10000, &db);
  add_transaction(Debit, acc_ptr, 2000, &db);
  add_transaction(Credit, acc_ptr, 5000, &db);

  // should print 13000
  printf("Account balance is %d\n", 
         compute_balance(acc_ptr));

  BankAccount acc2 = { .pin = 6897, 
                      .transactions_count = 0};
  strcpy(acc2.name, "Jake");
  BankAccount* acc_ptr2 = add_bank_account(
             acc2.name, acc2.pin,acc2.type, &db);
  add_transaction(Credit, acc_ptr2, 100000, &db);
  add_transaction(Debit, acc_ptr2, 20000, &db);
  add_transaction(Credit, acc_ptr2, 50000, &db);

    // should print 130000
  printf("Account balance is %d\n", 
         compute_balance(acc_ptr2));

  // should print 143000
  printf("Total Money with bank is %d\n", 
         compute_money_with_bank(&db)); 
}
```


## 4. Enumerating Sets

Write a C program which takes $n$, $k$, and some $n$ numbers $a_1,a_2,\cdots,a_n$ as inputs and 
prints all subsets of them of size $k$.   

Example:  
On input $n=4, k =2$ and $2,4,6,8$ it should output  
```
{2, 4}, {2, 6}, {2, 8}, {4, 6}, {4, 8}, {6, 8}
```

## 5. Recursively Enumerating Permutations


Consider all arrangements of $k$ items
   from $n$ objects. For $n=3, k=2$, they
   are $12, 21,13,31,23,32$. The number
   of such arrangements is 
   $$^nP_k = n(n-1)\cdots(n-k+2)(n-k+1).$$ 
   Bellow is a program which when given $n,k$
   as input, prints all arragements of $k$
   items from $n$ objects.         

Problems in the comments:

```c
/* Consider all arrangements of $k$ items
   from $n$ objects. For $n=3, k=2$, they
   are $12, 21,13,31,23,32$. The number
   of such arrangements is 
   $^nP_k = n(n-1)\cdots(n-k+2)(n-k+1).$ 
   Bellow is a program which when given $n,k$
   as input, prints all arragements of $k$
   items from $n$ objects.               */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int** PermList;

int count_arrangements(int n, int k) {
  // Problem 1 a.) write a recursive 
  // function logic here in one line to 
  // compute the number of all arragements 
  // of $k$ items from $n$ objects. (2 marks)
}

PermList create_perm_list(int n, 
                                 int k) {
  int fn = count_arrangements(n, k);
  PermList pl=malloc(fn*sizeof(int *));
  for(int i =0; i < fn ;i++) {
    pl[i] = malloc(n*sizeof(int)); 
  }
  return pl;
}
void destroy_perm_list(PermList pl, 
                       int n, int k) {
  int fn = count_arrangements(n, k);
  for (int i =0; i < fn ;i++) {
    free(pl[i]); 
  }
  free(pl);
}

// given a `small_row` of size `size`
// copies it to `big_row` which has size 
// `size+1`. Also sets the last position 
// in `big_row` to `e`
void insert_and_copy(int* small_row, int size, 
                     int e, int* big_row) {
  for (int i = 0; i < size; i++) {
    big_row[i] = small_row[i];
  }
  big_row[size] = e;
}

// checks if `e` is in the `row` of size `size`
bool find(int e, int* row, int size) {
  for(int i = 0; i < size; i++) {
    if (row[i] == e) {
      return true;
    }
  }
  return false;
}
// find the numbers from $\{1,\ldots, n\}$
// that are not in `row` which is of size `k`
// and puts them in `elements`
void find_elements_not_in_row(int* row, int n, 
                              int k, 
                              int* elements) {
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (find(i+1, row, k) == false) {
      elements[c++] = i+1;
    }
  }
}

PermList enumerate_arrangements(
                        int n, int k) {
  PermList B = create_perm_list(n,k);
  if (k == 1) {
    // Problem 1 b.) write code here for base 
    // case of recursively building list `B` 
    // of all arrangements of $k=1$ items 
    // from $\{1,..,n\}.$ (3 marks)
  } else { 
    // Problem 1 c.) write code here for 
    // recursively building list `B` of all
    //  arrangements of $k$ items from 
    // $\{1,..,n\}.$ (5 marks)
  }
  return B;
}
void print_perm_list(PermList pl, 
                     int n, int k) {
  int fn = count_arrangements(n, k);
  for(int i = 0; i < fn;i++) {
    for (int j =0; j <k; j++) {
      printf("%d ", pl[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int n = 10;
  int k = 5;
  print_perm_list(
        enumerate_arrangements(n, k),n,k);
  return 0;
}
```


## 6. Grades
Problem given in comments. Format of input files is also given bellow the code.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Grade {A,Am,B,Bm,C,Cm} Grade;

typedef struct Student {
  char email[100];
  int assigment1;
  int assigment2;
  int midsem;
  int endsem;
  Grade grade;
} Student;

typedef struct Database {
  Student students[300];
  int count_students;
} Database;

float compute_total_marks(Student s) {
/* Problem 2.1: write code here, for computing the 
total marks for a student and returning it. 
Assume that
assignment marks were out of 100, midsem marks 
were out of 50 and endsem marks were out of 80. 
The best 1 score amoung the 2 assignments will 
only be taken. The weightage for the total marks 
is 30% from assignment, 30% from midsem and 40% 
from endsem. (2 marks)
*/
}

void compute_grades(Database* db) {
/* Problem 2.2: Assume that grades are given as 
follows: >= 90: A, between 90 and 80: Am,
between 70 and 80: B, between 60 and 70: Bm,
between 50 and 60: C, between 40 and 50: Cm.
Write code here to assign grades to each 
student, and save it in the `grade` field of the
`Student`. (2 marks)
*/
}

int main(int argc, char* argv[]) {
  Database db;
  /* Problem 2.3: Suppose the a.out is run with the 
  first argument as the name of the `.csv` file. 
  For example `./a.out marks.csv`. Write code here, 
  that will read all the data from the `.csv` file 
  and populate the Database `db`.  (3 marks)
  */
    
  compute_grades(&db);
  
  /* Problem 2.4: Suppose the a.out is run with the 
  second argument as the name of the `.csv` file for 
  grades. 
  For example `./a.out marks.csv grades.csv`. 
  Write code here, open the file with name given by
  second argument, and write the grades.  (3 marks)
  */
  
}
```

### marks.csv (input file)
```
email,A1,A2,Mid,End
student1@students.iiit.ac.in ,68,72,34,56
student2@students.iiit.ac.in ,90,85,56,48
```


### grades.csv (output file)
```
email,total_marks,grade
student1@students.iiit.ac.in ,70.000000,B
student2@students.iiit.ac.in ,84.599998,A-
```

## 7. Inventory Grouping
Problem given in comments. Format of input files is also given bellow the code.
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Group {
  Diary,
  Vegetables,
  Fruits
} Group;

char group_names[3][100] = {
    "diary",
    "vegetable",
    "fruit"
  };

typedef struct InventoryItem {
  char name[100];
  int quantity;
  int price;
  Group group;
} InventoryItem;

int main(int argc, char* argv[]) {

  InventoryItem inventory[100];

/* Problem 2.1: Suppose the first argument of a.out
contains the csv file of inventories, write code 
here, which reads that file and stores the data in 
the `inventory` array declared above.
*/

/* Problem 2.2: Suppose the second argument of a.out
contains the csv file which has the group name
corresponding to each inventory item, write code here,
which updates the `group` field
in each InventoryItem of the `inventory` array.
*/
 
int grouped_value[3];
/* Problem 2.3: Compute the total value of all
items in a group and store it in the correpsonding
entry of the array `grouped_value`. That is
grouped_value[0] has the total value of all
Diary items. Similarly Vegetables for 1 and Fruits for 2.
*/

/* Problem 2.4: Write down the grouped inventory values
into a file given by the third argument to a.out, in the format
specificed for `grouped_inventory.csv`.
*/

}
```
### inventory.csv (input file)

```
name,quantity,price
onion ,100,15
paneer ,50,100
tomato ,70,10
curd ,30,50
apple ,150,100
orange ,200,150
```
### group.csv (second input file)
```
item,group
curd ,diary
tomato ,vegetable
paneer ,diary
apple ,fruit
onion ,vegetable
orange ,fruit
```
### out.csv (output file)
```
group,value
diary,6500
vegetable,2200
fruit,45000
```

## 8. Checking Bipartiteness
Given a graph $G=(V,E)$, it is said to be bipartite if the vertex set $V$ can be partitioned into two sets $V_1,V_2$ (such that $V_1 \cup V_2 = V$ and $V_1 \cap V_2 = \emptyset$), such that there is no edge in $E$ which has one endpoint in $V_1$ and another endpoint in $V_2$. 

Write a program, which takes a graph as input and checks if it is bipartite.


Note: Runtime of the algorithm doesnt matter, but it should output the correct answer.

## 9. Colorings of a Graph
Given a graph $G=(V,E)$, a *coloring* of the graph using $\{R,G,B\}$ is an assignment of these colors for every vertex, such that there is no edge in $E$ which has the same color in both end points. See [https://en.wikipedia.org/wiki/Graph_coloring](https://en.wikipedia.org/wiki/Graph_coloring).

Write a program, which takes a graph as input and outputs a coloring of the graph with $\{R,G,B\}$ colors.


Note: Runtime of the algorithm doesnt matter, but it should output the correct answer.

## 10. Finding Satisfying Assignments for 2SAT

A Boolean formula consists of 
- Boolean variables denotes by $a,b,c, \cdots, z$ which can take values $0,1$
- not operations which the flip the value  of the variable denoted by $\neg a$.
- or $||$, and $\\&$ operations.  

A *satisfying assignment* to a Boolean formula is an assignment of $0,1$ values to the variables,
such that the formula evaluates to $1$.    See [https://en.wikipedia.org/wiki/Boolean_algebra](https://en.wikipedia.org/wiki/Boolean_algebra)

For example:
$$ (\neg a||c)~\\&~(\neg a||\neg d)~\\&~(b||\neg d)~\\&~(b||\neg e)~\\&~(c||\neg e)~\\&~(\neg a||\neg f)~\\&~(b||\neg f)~\\&~(c||\neg f)~\\&~(d||g)~\\&~(e||g)~\\&~(f||g)$$
The assignment $a = 0, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1$ is a satisfying assignment to the above formula, since if you make this substitution and evaluate the expression, 1 is obtained.  

Note that the Boolean formula above 11 terms in brackets, outside which there is and $\\&$ operation. Inside the bracket a variable or a negated variable is ored $||$ with another one. Formula of this form are called 2SAT.   

Write a program which takes a 2SAT formula as input and outputs/prints a satisfying assignment to the formula.  

Note: The algorithm only needs to be correct.
