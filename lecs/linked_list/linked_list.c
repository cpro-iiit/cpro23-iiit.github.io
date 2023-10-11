#include "stdio.h"
#include "stdlib.h"
#define MAX_NAME_LEN 100

typedef struct Person {
    char name[MAX_NAME_LEN];
    int age;
} Person;

typedef struct Node {
    Person data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void print_list(LinkedList l) {
    while(l != NULL) {
        printf("%s\t\t%d\n", l->data.name, l->data.age);
        l = l->next;
    }
}

int size(LinkedList l) {
    int s = 0;
    while (l != NULL) {
        l = l->next;
        s ++;
    }
    return s;
}


LinkedList create_empy_list() {
    return NULL;
}


Person* element_at(int pos, LinkedList l) {
    while (l != NULL && pos != 0) {
        l = l->next;
        pos--;
    }
}


LinkedList append(Person p, LinkedList l) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = p;
    n->next = NULL;
    if (l != NULL) {
        while (l->next != NULL) {
            l = l -> next;
        }
        l -> next = n;
        return l;
    }
    return n;
}

int main() {

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

    LinkedList l = &first;
    printf("%d\n", size(l));
    print_list(l);
    return 0;

}