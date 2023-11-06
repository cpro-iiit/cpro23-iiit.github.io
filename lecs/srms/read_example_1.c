#include "srms.h"

int main() {
    Database db;
    db.customer_count = db.reciept_count = 0;


    FILE* cust_file = fopen("customers.bin","r");
    if (cust_file == NULL) {
        printf("Invalid file\n");
        return 0;
    }
    fread(&(db.customer_count), sizeof(int), 1, cust_file);
    fread(db.customers, sizeof(Customer), db.customer_count, cust_file);

    fclose(cust_file);


    FILE* rec_file = fopen("reciepts.bin","r");
    if (rec_file == NULL) {
        printf("Invalid file\n");
        return 0;
    }
    fread(&(db.reciept_count), sizeof(int), 1, rec_file);
    fread(db.reciepts, sizeof(Reciept), db.reciept_count, rec_file);

    fclose(rec_file);

    printf("%d %d", db.reciept_count, db.customer_count);
    return 0;

}