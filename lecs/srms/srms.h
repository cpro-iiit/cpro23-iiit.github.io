#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Customer {
    char name[100];
    int phone_no;
} Customer;

typedef enum PayMode {
    Cash = 0,
    Card = 1,
    UPI = 2
} PayMode;

typedef struct Reciept {
    time_t time;
    float value;
    // Customer *customer;
    int customer_index;
    PayMode mode;
} Reciept;

typedef struct Database {
    Customer customers[100];
    Reciept reciepts[1000];
    int customer_count;
    int reciept_count;
} Database;

int add_customer(char *name, int phone_no, Database *db);

Reciept* add_reciept(int value, int c, PayMode mode, Database *db);

int find_customer_by_phone_no(int phone, Database *db);