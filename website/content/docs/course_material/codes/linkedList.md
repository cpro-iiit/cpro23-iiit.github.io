---
title: "Linked List"
---
# Linked list

## Theory

Linked list can be defined as either a node structure doing nothing or one that is pointing to another linked list

See linked: [Recursion]({{< relref "recursion.md" >}})

{{<hint warning>}}
**Warning:** Make sure to always free up memory!
{{</hint>}}

---

## Code

```cpp
typedef struct node {
    struct node* nxt; // will point to the next node in the linked list if any
    int val; // store whatever else you might need
} Node;

int main() {
    // Code here
}
```
