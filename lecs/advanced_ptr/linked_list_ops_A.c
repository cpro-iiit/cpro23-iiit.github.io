#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NAME_LEN 100


typedef enum RelStatus {
    NotMentioned,
    Single,
    Engaged,
    Married
} RelStatus;

typedef struct Person {
    char name[MAX_NAME_LEN];
    int age;
    RelStatus status;
} Person;

typedef struct Node {
    Person data;
    struct Node* next;
} Node;

typedef Node* LinkedList;

void print_list(LinkedList l) {
    char status_string[][15] = {
        "Not Mentioned","Single",
        "Married", "Engaged"
    };
    printf("-----------------------------------\n");
    while (l != NULL) {
        printf("%s\t\t%d\t%s\n",l->data.name, l->data.age, status_string[l->data.status]);
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
    if (l == NULL) {
        // Node D = {{"Raj", 18}, NULL};
        Node* D = (Node *) malloc(sizeof(Node));
        D->data = p;
        D->next = NULL;
        return D;
    } else {
        l->next = append(p, l->next);
    }
    return l;
}

LinkedList insert(Person p, int pos, LinkedList l) {
    if (pos == 0) {
        Node* D = (Node *) malloc(sizeof(Node));
        D->data = p;
        D->next = l;
        return D;
    } else {
        l->next = insert(p, pos-1, l->next);
        return l;
    }
}

LinkedList filterby_age(LinkedList l, int lower, int upper) {
    LinkedList l2 = NULL;
    while(l != NULL) {
        if (l->data.age >= lower && l->data.age <= upper) {
            l2 = append(l->data, l2);
        }
        l = l->next;
    }
    return l2;
}

LinkedList reverse(LinkedList l) {
    int s = size(l);
    LinkedList l2 = NULL;
    for (int i = 0; i < s; i++) {
        l2 = insert(*element_at(s-i-1, l), i, l2);
    }
    return l2;
}

int main() {
    Node third = {
        {"Alice", 22, Single},
        NULL
    };
    Node second = {
        {"Bob", 26, Married},
        &third
    };
    Node first = {
        {"Charlie", 20, Engaged},
        &second
    };
    Person D = {"Raj", 18, NotMentioned};
    Node l2 = { D, NULL};

    LinkedList l = &first;
    printf("Size of the list is %d\n", size(l));
    print_list(l);
    l=reverse(l);
    print_list(l);
    l = insert(D,2,l);
    // Problem1: Write the insert function such that, 
    // we dont need to reassign l to the return value 
    // of the function to update it. That is the
    // line bellow is equivalent to line above
    // insert_v2(D, 2, &l);
    print_list(l);

    // Problem2: Filter the linked list of person
    // who are Single and less than 24 in age.

    print_list(l);
    return 0;
}