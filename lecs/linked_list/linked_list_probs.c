
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
    int s = 0;
    while (l != NULL) {
        if (s == pos) return &(l->data);
        l = l->next;
        s ++;
    }
    return NULL;
}



LinkedList append(Person p, LinkedList l) {
    Node *n = (Node *) malloc(sizeof(Node));
    n->data = p;
    n->next = NULL;
    Node* i;
    if (i != NULL) {
        while (i->next != NULL) {
            i = i -> next;
        }
        i -> next = n;
        return l;
    }
    return n;
}


LinkedList insert(Person p, int pos, LinkedList l) {
  
    if (pos == 0) {
        Node *n = (Node *) malloc(sizeof(Node));
        n->data = p;
        n->next = l;
        return l;
    } else {
        if (l== NULL) return NULL; // Error
        insert(p, pos-1, l->next);
        return l;
    }
}


LinkedList concat(LinkedList p, LinkedList q) {
    if (p == NULL) return q;
    while(p->next !=NULL) {
        p = p->next;
    }
    p->next = q;
    return p;
}

LinkedList reverse(LinkedList l) {
    int s = size(l);
    LinkedList rev_l = create_empy_list();
    for(int i = 0; i < s; i++) {
        Person* p = element_at(s- i - 1, l);
        printf("%d\t%s\t\n", i,p->name);
        rev_l = append(*p, rev_l);
        print_list(rev_l);
        printf("------\n");
    }
    return rev_l;
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
    // printf("%d\n", size(l));
    // print_list(l);
    LinkedList rev_l = reverse(l);
    print_list(rev_l);
    return 0;

}