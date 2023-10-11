---
marp: true
size: 4:3
---
# Linked Lists


---
## HW: Mutual Friendships in Social Nets
```c
bool check_mutual_friends(char *name1, char *name2, SocialNet *sn) {
 // TODO p and q are mutual friends if q is in the friend list of p
 // and p is in the friend list of q
}
```
---

## Problem: Large Arrays!
```c
typedef struct SocialNet {
    Person members[MAX_MEMBERS];
    int size;
} SocialNet;
```

---
### Linked List: A array that grows according to needs


---

## Linked List: Code
```c
typedef struct Node {
    Person data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

Node third = {
    {"Alice", 22},
    NULL
};
Node second = {
    {"Bob", 26},
    &third
};
Node first = {
    {"Charlie", 20},
    &second
};

```

---
## Size of a Liniked List
```c
int size(LinkedList l) {
    int s = 0;
    while (l != NULL) {
        l = l->next;
        s ++;
    }
    return s;
}
```
---
## Printing elements of a linked list

```c
void print_list(LinkedList l) {
    // TODO
}
```
---

## Find the element at the ith position
```c
Person* element_at(int pos, LinkedList l) {
    // TODO
}
```
---
## Append element to end of the list
```c
LinkedList append(Person p, LinkedList l) {
    // TODO
}
```
---
## Insert element at a position in the list
```c
LinkedList insert(Person p, int pos, LinkedList l) {
    // TODO
}
```

---
## Concatenate 2 lists
```c
LinkedList concat(LinkedList l1, LinkedList l2) {
    // TODO
}
```


---
## Reverse a list
```c
LinkedList reverse(LinkedList l) {
    // TODO
}
```