#include "srms.h"

int add_customer(char *name, int phone_no, Database *db) {
    Customer *c = &(db->customers[db->customer_count++]);
    c->phone_no = phone_no;
    strcpy(c->name, name);
    return db->customer_count-1;
}

Reciept* add_reciept(int value, int c, PayMode mode, Database *db) {
    time_t now = time(NULL);
    Reciept* r = &(db->reciepts[db->reciept_count++]);
    r->customer_index= c;
    r->value = value;
    r->time = now;
    r->mode = mode;
    return r;
}

int find_customer_by_phone_no(int phone, Database *db) {
    Customer *cust = NULL;
    for(int i =0; i< db->customer_count; i++) {
        if(phone == db->customers[i].phone_no) {
            cust = &(db->customers[i]);
            return i;
            break;
        }
    }
    return -1;
}