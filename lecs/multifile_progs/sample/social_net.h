#include "linked_list.h"
#include "stdbool.h"

typedef enum RelStatus {
    NotMentioned,
    Single,
    Engaged,
    Married
} RelStatus;

typedef struct Person {
    char name[100];
    int age;
    RelStatus relstatus;
    LinkedList friends;
} Person;

typedef struct SocialNet {
    LinkedList members;
} SocialNet;

void print_person(Person* p);

void print_network(LinkedList m);

Person* find_person(char* name, LinkedList l);

char* person_with_most_friends(LinkedList l);

int popularity(char* name, LinkedList l);

LinkedList delete_by_name(char* name, LinkedList l);

LinkedList filterby_age(LinkedList l, int lower, int upper);

bool friends_triangle(LinkedList members);

bool transitive_friendship(LinkedList members) ;