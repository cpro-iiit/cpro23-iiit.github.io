#include "social_net.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void print_person(Person* p) {
    char status_string[][15] = {
        "Not Mentioned","Single",
        "Married", "Engaged"
    };
    printf("%s\t\t%d\t%s\t\t\t", p->name, p->age, status_string[p->relstatus]);
    LinkedList f = p->friends;
    while (f != NULL) {
        printf("%s, ", f->data->name);
        f = f->next;
    }
    printf("\n");
}

void print_network(LinkedList m) {
    printf(
        "------------------------------------------------------\n"
        "Name\t\tAge\tStatus\t\t\tFriends\n"
        "------------------------------------------------------\n");
    while (m != NULL) {
        print_person(m->data);
        m = m->next;
    }
    printf("------------------------------------------------------\n");
}

Person* find_person(char* name, LinkedList l) {
    // Either find the person with a particular name
    // if not found return NULL
    while(l!= NULL) {
        if (strcmp(l->data->name, name) == 0) {
            return l->data;
        }
        l = l->next;
    }
    return NULL;
}



char* person_with_most_friends(LinkedList l) {
    // Q A1: Return the name of the person with most friends
    // (3 marks)
    int d = 0;
    Node* n = NULL;
    while(l != NULL) {
        int e = size(l->data->friends);
        if (e > d) {
            d = e;
            n = l;
        }
        l = l->next;
    }
    return n==NULL? "" : n->data->name;
}

int popularity(char* name, LinkedList l) {
    // Q B1: Return the number of people who has the person
    // named `name` amoung their friends. (3 marks)
    int count = 0;
    while ( l!= NULL) {
        if (find_person(name, l->data->friends) != NULL) {
            count++;
        }
    }
    return count;
}

LinkedList delete_by_name(char* name, LinkedList l) {
    // Q A2: Delete the person named `name` from l (3 marks)
    if (l == NULL) {
        return NULL;
    } else if (strcmp(name, l->data->name) == 0) {
        Node* tail = l->next;
        free(l);
        return tail;
    } else {
        l->next = delete_by_name(name, l->next);
        return l;
    }
}

LinkedList filterby_age(LinkedList l, int lower, int upper) {
    // Q B2: Return the link list of people in l with age
    // between lower and upper (3 marks)
    LinkedList l2 = NULL;
    while(l != NULL) {
        if (l->data->age >= lower && l->data->age <= upper) {
            l2 = append(l->data, l2);
        }
        l = l->next;
    }
    return l2;
}

bool friends_triangle(LinkedList members) {
    // Q A3: Check if there is a triangle of friends
    // ie there exists X, Y, Z such that
    // Y is a friend of X, Z is a friend of Y, X is a friend of Z
    // ALso print all such triplets (4 marks)
    LinkedList f = members;
    printf(
        "-----------------------------\n"
        "Friend Triangles\n"
        "-----------------------------\n");
    bool found = false;
    while(f != NULL) {
        LinkedList s = f->data->friends;
        while (s != NULL) {
            LinkedList t = s->data->friends;
            while (t != NULL) {
                LinkedList l = t->data->friends;
                while (l != NULL) {
                    if (strcmp(l->data->name, f->data->name)==0) {
                        printf("%s->%s->%s->%s\n", f->data->name, s->data->name, t->data->name, f->data->name);
                        found = true;
                    }
                    l = l->next;
                }
                t = t->next;
            }
            s = s->next;
        }
        f = f->next;
    }
    printf("-------------------------\n");
    return found;
}

bool transitive_friendship(LinkedList members) {
    // Q B3: check if the friendship relation is transitive
    // ie for any X,Y, Z, if Y is a friend of X and 
    // Z is a friend of Y then Z is a friend of X
    // Also print all the links that violates transitivity
    // (4 marks)
    LinkedList f = members;
    printf(
        "-----------------------------\n"
        "Links that are not Transitive\n"
        "-----------------------------\n");
    bool found = false;
    while(f != NULL) {
        LinkedList s = f->data->friends;
        while (s != NULL) {
            LinkedList t = s->data->friends;
            while (t != NULL) {
                if (find_person(t->data->name, f->data->friends) == NULL) {
                    printf("%s->%s->%s, but there is no %s->%s\n", f->data->name, s->data->name, t->data->name, f->data->name,t->data->name);
                    found = true;
                }
                t = t->next;
            }
            s = s->next;
        }
        f = f->next;
    }
    printf("-------------------------\n");
    return !found;
}