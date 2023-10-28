#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix {
    int        num_rows;
    int        num_cols;
    float**     data;
} Matrix;


Matrix* create_matrix(int r, int c) {
    Matrix* m = (Matrix*) malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (float**) calloc(r, sizeof(float*));
    for (int i =0; i < c; i++) {
        m->data[i] = (float*) calloc(c, sizeof(float));
    }
    return m;
}

void destroy_matrix(Matrix* m) {
    // HW
}

Matrix* add_matrix(Matrix* A, Matrix* B) {
   // HW
}

Matrix* mult_matrix(Matrix* A, Matrix* B) {
   // HW
}

Matrix* scalar_mult_matrix(float s, Matrix* M) {
    // HW
}

void print_matrix(Matrix* m) {
    for (int i = 0; i < m->num_rows; i++) {
        for (int j = 0; j < m->num_cols; j++) {
            printf("%f\t", m->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    // row size will be provided as the first arg
    // col size will be provided as the second arg
    // remaining row size * column size args will be the entries 
    // of the matrix in row major order

    Matrix* m = create_zero_matrix(3,3);
    print_matrix(m);
    // write code to create matrix of the dimension provied in first and second arg
    // and initialize it with the values provided as the remaing args

    return 0;

}