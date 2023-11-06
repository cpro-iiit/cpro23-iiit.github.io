#include "srms.h"

int main() {
    Database db;
    db.customer_count = db.reciept_count = 0;

    int a = add_customer("Alice",12345,&db);

    add_reciept(1000, a, Cash, &db);
    add_reciept(500, a, UPI, &db);

    int b = add_customer("Bob",5678,&db);

    add_reciept(700, b, Card, &db);
    add_reciept(500, b, UPI, &db);

    FILE* cust_file = fopen("customers.bin","w");
    if (cust_file == NULL) {
        printf("Invalid file\n");
        return 0;
    }
    fwrite(&(db.customer_count), sizeof(int), 1, cust_file);
    fwrite(db.customers, sizeof(Customer), db.customer_count, cust_file);

    fclose(cust_file);


    FILE* rec_file = fopen("reciepts.bin","w");
    if (rec_file == NULL) {
        printf("Invalid file\n");
        return 0;
    }
    fwrite(&(db.reciept_count), sizeof(int), 1, rec_file);
    fwrite(db.reciepts, sizeof(Reciept), db.reciept_count, rec_file);

    fclose(rec_file);

    return 0;

}