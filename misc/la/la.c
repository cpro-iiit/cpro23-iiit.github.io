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
    // HW1: Write code here to free all memory used by the matrix stored in m
}

Matrix* add_matrix(Matrix* A, Matrix* B) {
   // HW2: write code here to add the matrices A, B and return a new matrix which has the results.
   // A, B should remain unmodified. If dimensions doesnt match should return NULL
}

Matrix* mult_matrix(Matrix* A, Matrix* B) {
   // HW3: write code here to multiply the matrices A, B and return a new matrix which has the results.
   // A, B should remain unmodified. If the dimensions doesnt match it should return NULL
}

Matrix* scalar_mult_matrix(float s, Matrix* M) {
    // HW4: write code here to multiply the matrix A with a scalar s and return a new matrix which has the results.
   // A should remain unmodified.
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
    // HW5: write code to create matrix of the dimension provied in first and second arg
    // and initialize it with the values provided as the remaing args

    return 0;

}