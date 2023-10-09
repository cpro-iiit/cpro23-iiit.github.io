---
marp: true
size: 4:3
---
## Macros, More Intializers in Social Nets


---
## Social Nets
```c
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
    Person* friends[5];
} Person;

typedef struct SocialNet {
    Person members[100];
    int size;
} SocialNet;
```
---

## Social Nets with Macros
```c

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
    Person* friends[MAX_FRIENDS];
} Person;

typedef struct SocialNet {
    Person members[MAX_MEMBERS];
    int size;
} SocialNet;
```

---
## Intitializer

| Name    | Age | Rel Status    |
|---------|-----|---------------|
| Alice   | 24  | Not Mentioned | 
| Bob     | 28  | Maried        | 
| Charlie | 20  | Single        | 


```c
int main()
{
    SocialNet social_net = {
        // Fill here
    };
    print_network(social_net);
    return 0;
}
```

---
## Print Person
```c
void print_person(struct Person p) {
/*  TODO: Write code that prints a person 
    in the following format:
    Alice           24      Not Mentioned
*/
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
```
---
## Finding a person by name

```c
Person* find_person(char* name1, SocialNet *sn) {
    // TODO
}
```
---

## HW: Check Mutual Friends by name
```c
bool check_mutual_friends(char *name1, char *name2, SocialNet *sn) {
 // TODO p and q are mutual friends if q is in the friend list of p
 // and p is in the friend list of q
}
```