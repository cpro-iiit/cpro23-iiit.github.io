#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node Node;

typedef Node* LinkedList;

typedef struct Person Person;

struct Node {
    struct Person* data;
    struct Node* next;
};

LinkedList append(Person* p, LinkedList l);

int size(LinkedList l);
