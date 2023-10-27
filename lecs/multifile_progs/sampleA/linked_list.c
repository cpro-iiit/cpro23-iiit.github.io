
#include "linked_list.h"

LinkedList append(Person* p, LinkedList l) {   
    if (l == NULL) {
        Node* D = (Node *) malloc(sizeof(Node));
        D->data = p;
        D->next = NULL;
        return D;
    } else {
        l->next = append(p, l->next);
    }
    return l;
}

int size(LinkedList l) {
    return l == NULL? 0: 1+size(l->next);
}