
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
    int count_friends;
    struct Person* friends[5];
} Person;

typedef struct Node {
    Person data;
    struct Node* next;
} Node;

typedef Node* LinkedList;


typedef struct SocialNet {
    LinkedList members;
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
    LinkedList l = social_net.members;
    printf(
        "----------------------------------------------\n"
        "Name\t\tAge \t Rel Status\t\t\tFriends\n"
        "----------------------------------------------\n");
    while (l!=NULL) {
        print_person(l->data);
        l = l->next;
    }
    printf("----------------------------------------------\n");

}

Person* find_person(char* name, SocialNet *sn) {
    // TODO
    LinkedList l = sn->members;
    while(l!= NULL) {
        if (strcmp(l->data.name, name) == 0) {
            return &(l->data);
        }
        l = l->next;
    }
    return NULL;

}

bool check_mutual_friendship(char* name1, char* name2, SocialNet* sn) {
    Person* p = find_person(name1, sn);
    Person* q = find_person(name2, sn);
    bool q_in_fl_of_p = false;
    bool p_in_fl_of_q = false;
    for(int i =0; i< p->count_friends; i++) {
        if (q == p->friends[i]) {
            q_in_fl_of_p = true;
        }
    }
    for(int i =0; i< q->count_friends; i++) {
        if (p == q->friends[i]) {
            p_in_fl_of_q = true;
        }
    }

    if (p_in_fl_of_q && q_in_fl_of_p) {
        return true;
    } else {
        return false;
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


Person* element_at(int pos, LinkedList l) {
    int s = 0;
    while (l != NULL) {
        if (s == pos) return &(l->data);
        l = l->next;
        s ++;
    }
    return NULL;
}

int main()
{
    SocialNet social_net = {
        .members=NULL,
        .size = 0
    };

    Person A = {
        "Alice",
        24,
        Single,
        2
    };
    Person B = {
        "Bob",
        20,
        Engaged,
        0
    };

    Person C = {
        "Charlie",
        26,
        Maried,
        1
    };

    social_net.members = append( A,social_net.members);
    social_net.members = append( B,social_net.members);
    social_net.members = append( C,social_net.members);

    //social_net.members[0].friends[0] =  &(social_net.members[1]);
    // social_net.members[0].friends[1] =  &(social_net.members[2]);
    social_net.members->data.friends[0] = element_at(social_net.members, 1);
    social_net.members->data.friends[1] = element_at(social_net.members, 2);

    // social_net.members[2].friends[0] =  &(social_net.members[1]);
    element_at(social_net.members, 2)->friends[0] = element_at(social_net.members, 0);

    print_network(social_net);
    return 0;
}
