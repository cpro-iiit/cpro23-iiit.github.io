#include "social_net.h"
#include "stdio.h"

int main()
{
    SocialNet s = { NULL };

    Person A = {"Alice", 23, Single, NULL};
    Person B ={"Bob", 26, Engaged, NULL};
    Person C = {"Charlie", 21, NotMentioned, NULL};
    Person D ={"Don", 28, Married, NULL};

    s.members = append(&A, s.members);
    s.members = append(&B, s.members);
    s.members = append(&C, s.members);
    s.members = append(&D, s.members);

    A.friends = append(&B, A.friends);
    A.friends = append(&C, A.friends);
    B.friends = append(&D, B.friends);
    C.friends = append(&D, C.friends);
    D.friends = append(&A, D.friends);

    printf("List of people between ages 24 to 28:\n");
    print_network(filterby_age(s.members, 24, 28));

    printf("The person with most friends is %s.\n",person_with_most_friends(s.members));

    // For above social network, `friends_triangle(s.members)` 
    // returns `true` and prints
    // -----------------------------
    // Friend Triangles
    // -----------------------------
    // Alice->Bob->Don->Alice
    // Alice->Charlie->Don->Alice
    // Bob->Don->Alice->Bob
    // Charlie->Don->Alice->Charlie
    // Don->Alice->Bob->Don
    // Don->Alice->Charlie->Don
    // -------------------------
    friends_triangle(s.members);

    // For the above social network, `transitive_friendship(s.members)`
    // returns false and prints
    // -----------------------------
    // Links that are not Transitive
    // -----------------------------
    // Alice->Bob->Don, but there is no Alice->Don
    // Alice->Charlie->Don, but there is no Alice->Don
    // Bob->Don->Alice, but there is no Bob->Alice
    // Charlie->Don->Alice, but there is no Charlie->Alice
    // Don->Alice->Bob, but there is no Don->Bob
    // Don->Alice->Charlie, but there is no Don->Charlie
    // -------------------------
    transitive_friendship(s.members);

    return 0;
}