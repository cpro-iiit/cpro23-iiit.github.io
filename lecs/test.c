
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
 

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
    int count_friends;
    struct Person* friends[5];
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
    printf("%s\t\t%d\t%s\t\t", p.name, p.age, status_string[p.relstatus]);
    for (int i = 0; i < p.count_friends; i++) {
        printf("%s, ",p.friends[i]->name);
    }
    printf("\n");
}

void print_network(SocialNet social_net) {
    printf(
        "----------------------------------------------\n"
        "Name\t\tAge \t Rel Status\t\t\tFriends\n"
        "----------------------------------------------\n");
    for (int i=0;i <social_net.size; i++) {
        print_person(social_net.members[i]);
    }
    printf("----------------------------------------------\n");

}

// Person* find_person(char* name1, SocialNet *sn) {
//     // TODO
// }


int main()
{
    
    clock_t now = clock();
    SocialNet social_net = {
        {
            {"Alice", 24, NotMentioned},
            {"Bob", 22, Married},
            {"Charlie", 28, Engaged}
        },
        3
    };

    social_net.members[0].friends[0] =  &(social_net.members[1]);
    social_net.members[0].friends[1] =  &(social_net.members[2]);
    social_net.members[0].count_friends = 2;
    social_net.members[2].friends[0] =  &(social_net.members[1]);
    social_net.members[2].count_friends = 1;
    social_net.members[1].count_friends = 0;

    print_network(social_net);

    
    clock_t later = clock();
 
    printf("%d %d %f\n", later, now, ((float)(later-now)/ CLOCKS_PER_SEC));
 
    return 0;
}
