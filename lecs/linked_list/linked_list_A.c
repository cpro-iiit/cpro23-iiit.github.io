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
    printf("-----------------------------------\n");
    while (l != NULL) {
        printf("%s\t\t%d\n",l->data.name, l->data.age);
        l = l->next;   
    }
    printf("-----------------------------------\n");
}

int size(LinkedList l) {
    int s = 0;
    while (l != NULL) {
        l = l->next;
        s ++;
    }
    return s;
}

Person* element_at(int pos, LinkedList l) {
    int s = 0;
    while (l != NULL) {
        if (s == pos) return &(l->data);
        l = l->next;
        s ++;
    }
    return NULL;
}

LinkedList append(Person p, LinkedList l) {

    // Node D = {{"Raj", 18}, NULL};
    Node* D = (Node *) malloc(sizeof(Node));
    D->data = p;
    D->next = NULL;
    if (l == NULL) return D;
    while (l->next != NULL) {
        l = l->next;
    }
    l->next = D;
    return l;
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
    Person D = {"Raj", 18};

    LinkedList l = &first;
    printf("Size of the list is %d\n", size(l));
    print_list(l);
    printf("Element at 1st position: %s\n", element_at(1,l)->name);
    printf("Element at 2nd position: %s\n", element_at(2,l)->name);
    append(D, l);
    printf("List after appending\n");
    print_list(l);
    return 0;
}