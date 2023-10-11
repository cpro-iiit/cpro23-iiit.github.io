
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FRIENDS 5
#define MAX_MEMBERS 100
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
    RelStatus relstatus;
    int count_friends;
    struct Person *friends[MAX_FRIENDS];
} Person;

typedef struct SocialNet {
    Person members[MAX_MEMBERS];
    int size;
} SocialNet;

void print_person(Person p) {
    char status_string[][20] = {
        "Not Mentioned",
        "Single",
        "Engaged",
        "Married"
    };
    printf("%s\t\t%d\t%s\n", p.name, p.age, status_string[p.relstatus]);
}

void print_network(SocialNet social_net) {
    printf(
        "----------------------------------------------\n"
        "Name\t\tAge \t Rel Status\n"
        "----------------------------------------------\n");
    for (int i=0;i <social_net.size; i++) {
        print_person(social_net.members[i]);
    }
    printf("----------------------------------------------\n");
}

int main()
{
    SocialNet social_net = {
     {
            { "Alice",      24,      NotMentioned},
            {"Bob",         28,        Married},
            { "Charlie",    20,    Single}
        },
    3
    };
    print_network(social_net);
    return 0;
}
