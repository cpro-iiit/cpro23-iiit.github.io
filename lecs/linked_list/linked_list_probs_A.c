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
    // int s = 0;
    // while (l != NULL) {
    //     l = l->next;
    //     s ++;
    // }
    // return s;
    // if (l == NULL) {
    //     return 0;
    // } else {
    //     return 1+ size(l->next);
    // }
    return l==NULL? 0 : 1+ size(l->next);
}

Person* element_at(int pos, LinkedList l) {
    // int s = 0;
    // while (l != NULL) {
    //     if (s == pos) return &(l->data);
    //     l = l->next;
    //     s ++;
    // }
    // return NULL;
    if (pos == 0) {
        return &(l->data);
    } else {
        return element_at(pos-1, l->next);
    }
    
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

LinkedList shuffle_inplace(LinkedList l1, LinkedList l2) {
    Node* head = l1;
    Node* temp1;
    Node* temp2;
    while (l1 != NULL && l2 != NULL) {
        temp1 = l1->next;
        temp2 = l2->next;
        l1->next = l2;
        if (temp1 == NULL) {
            break;
        }
        l2->next = temp1;
        l1 = temp1;
        l2 = temp2;
    }
    return head;
}


LinkedList insert(Person p, int pos, LinkedList l) {
    // if (pos == 0) {
    //     Node* D = (Node *) malloc(sizeof(Node));
    //     D->data = p;
    //     D->next = l;
    //     return D;
    // } else {
    //     l->next = insert(p, pos - 1, l->next);
    //     return l;
    // }
    Node* D = (Node *) malloc(sizeof(Node));
    D->data = p;
    if (pos == 0) {
        D->next = l;
        return D;
    } else {
        LinkedList head = l;
        while(pos > 1) {
            l = l->next;
            pos--;
        }
        D->next = l->next;
        l->next = D;
        return head;
    }
}

LinkedList concat(LinkedList l1, LinkedList l2) {
    if (l1 == NULL) return l2;
    else {
        l1-> next = concat (l1->next, l2);
        return l1;
    }
}


LinkedList reverse(LinkedList l) {
    int s = size(l);
    LinkedList l2 = NULL;
    for (int i =0; i < s; i++) {
        l2 = append(*element_at(s-i - 1, l), l2 );
    }
    return l2;
}


int main() {
    
    LinkedList even = NULL;
    for (int i = 0; i< 5; i++) {
        even = append((Person){"A", 2*i}, even);
    }

    LinkedList odd = NULL;
    for (int i = 0; i< 7; i++) {
        odd = append((Person){"B", 2*i+1}, odd);
    }
    
    print_list(even);
    print_list(odd);
    LinkedList S = shuffle(odd, even);
    print_list(S);
    // LinkedList l = &first;
    // printf("Size of the list is %d\n", size(l));
    // printf("Initial List\n");
    // print_list(l);
    // printf("Reversed List\n");
    // l = reverse(l);
    // print_list(l);
    // l = append(D, l);
    // printf("Appended List\n");
    // print_list(l);
    // l = reverse(l);
    // printf("Again Reversed List\n");
    // print_list(l);
    // printf("Element at 1st position: %s\n", element_at(1,l)->name);
    // printf("Element at 2nd position: %s\n", element_at(2,l)->name);
    // append(D, l);
    // printf("List after appending\n");
    // print_list(l);
    return 0;
}