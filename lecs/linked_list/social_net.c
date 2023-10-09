
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


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
} Person;

typedef struct SocialNet {
    struct Person members[100];
    int size;
} SocialNet;

void print_person(struct Person p) {
    char status_string[][20] = {
        "Not Mentioned",
        "Single",
        "Engaged",
        "Maried"
    };
    printf("%s\t\t%d\t%s", p.name, p.age, status_string[p.relstatus]);
    printf("\n");
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

Person* find_person(char* name1, SocialNet *sn) {
    // TODO
}


int main()
{
    SocialNet social_net = {
        {
            {"Alice", 24, NotMentioned},
            {"Bob", 22, Married},
            {"Charlie", 28, Engaged}
        },
        3
    };
    print_network(social_net);
    return 0;
}
