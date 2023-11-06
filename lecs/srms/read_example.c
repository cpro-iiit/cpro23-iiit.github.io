#include "srms.h"

int main() {
    Database db;
    db.customer_count = db.reciept_count = 0;

    FILE* cus_file = fopen("customers.bin","r");

    fread(&(db.customer_count), sizeof(int), 1, cus_file);

    fread(db.customers, sizeof(Customer), db.customer_count, cus_file);

    for (int i = 0; i < db.customer_count; i++) {
        printf("%s\t%d\n",db.customers[i].name, db.customers[i].phone_no);
    }
    fclose(cus_file);

    FILE* res_file = fopen("reciepts.bin","r");

    fread(&(db.reciept_count), sizeof(int), 1, res_file);

    fread(db.reciepts, sizeof(Reciept), db.reciept_count, res_file);

    for (int i = 0; i < db.reciept_count; i++) {
        printf("%d\t%d\t%f\t%s\n",db.reciepts[i].mode, db.reciepts[i].time, 
        db.reciepts[i].value, db.customers[db.reciepts[i].customer_index].name );
    }
    fclose(cus_file);

    return 0;

}