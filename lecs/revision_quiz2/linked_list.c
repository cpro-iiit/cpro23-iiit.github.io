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

    // return l==NULL? 0 : 1+ size(l->next);
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



// assuming a < b
LinkedList swap(LinkedList l, int a, int b) {
   LinkedList head = l;
   Person temp;
   Node* a_ptr;
   Node* b_ptr;
   // Find above
   while(a >= 1) {
    l = l->next;
    a--;
    b--;
   }
   a_ptr = l;
   while(b >= 1) {
    l = l->next;
    b--;
   }
   b_ptr = l;
   temp = a_ptr->data;
   a_ptr->data = b_ptr->data;
   b_ptr->data = temp;
   return head;
}

LinkedList sort(LinkedList l) {
    if (l == NULL || l->next == NULL) {
        return l;
    } else {
        int b = find_index_of_largest_node(l);
        l = swap(l, 0, b);
        l->next = sort(l->next);
        return l;
    }
}

void free_linked_list(LinkedList l) {
    if (l == NULL) {
        return;
    } else {
        LinkedList tail = l->next;
        free(l);
        free_linked_list(tail);
    }
}

LinkedList node_append(Node* n, LinkedList l) {
    if (l == NULL) {
        return n;
    } else {
        l->next = node_append(n, l->next);
        return l;
    }
}

LinkedList reverse_in_place(LinkedList l) {
    if (l == NULL) {
        return l;
    } else {
        LinkedList rev = reverse_in_place(l->next);
        l->next = NULL;
        rev = node_append(l, rev);
        return rev;
    }
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

LinkedList concat(LinkedList l1, LinkedList l2) {
    if (l1 == NULL) {
        return l2;
    } else {
        l1->next = concat(l1->next, l2);
        return l1;
    }
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
    Node l2 = { D, NULL};

    LinkedList l = &first;
    printf("Size of the list is %d\n", size(l));
    print_list(l);
    // l = concat( &l2,l);
    // print_list(l);
    l = swap(l,1,2);
    print_list(l);
    // print_list(insert(D,2,l));

    // printf("Element at 1st position: %s\n", element_at(1,l)->name);
    // printf("Element at 2nd position: %s\n", element_at(2,l)->name);
    // append(D, l);
    // printf("List after appending\n");
    // print_list(l);
    return 0;
}