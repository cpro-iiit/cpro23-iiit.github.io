// https://medium.com/nerd-for-tech/higher-order-functions-in-c-74f6c4b550ee#:~:text=A%20higher%2Dorder%20function%20is,runnable%20code%20chunks%20like%20functions.
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

// typedef bool (*CheckPersonFunction)(Person);


void print_list(LinkedList l) {
    char status_string[][15] = {
        "Not Mentioned","Single",
        "Married", "Engaged"
    };
    printf("-----------------------------------\n");
    while (l->next != NULL) {
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

void insert_v2(Person p, int pos, LinkedList* l) {
    *l = insert(p, pos, *l);
}



LinkedList filterby_age(LinkedList l, int lower, int upper) {
    // Q B2: Return the link list of people in l with age
    // between lower and upper (3 marks)
    LinkedList l2 = NULL;
    while(l->next != NULL) {
        if (l->data.age >= lower && l->data.age <= upper) {
            l2 = append(l->data, l2);
        }
        l = l->next;
    }
    return l2;
}



LinkedList filter_by(LinkedList l, bool (*check_fun_ptr)(Person p)) {
    LinkedList l2 = NULL;
    while(l != NULL) {
        if ((*check_fun_ptr)(l->data) == true) {
            l2 = append(l->data, l2);
        }
        l = l->next;
    }
    return l2;
}

// // With the typedef for CheckPersonFunction we can 
// // simplify the function as
// LinkedList filter_by(LinkedList l, CheckPersonFunction f) {
//     LinkedList l2 = NULL;
//     while(l != NULL) {
//         if ((*f)(l->data) == true) {
//             l2 = append(l->data, l2);
//         }
//         l = l->next;
//     }
//     return l2;
// }



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
    // insert_v2(D, 2, &l);
    print_list(l);
    bool custom_check_fn(Person p) {
        return p.status == Single && p.age < 15 ;
    }
    l = filter_by(l, &custom_check_fn);
    print_list(l);

    printf("\n");
    return 0;
}