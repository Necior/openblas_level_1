/*
    This is an example of calculating Y = AX + Y, where:
        * Y is a vector (array containing N elements);
        * X is a vector (array containing N elements);
        * A is a constant (double).

    Sample data is already in the main().
*/

#include <cblas.h>
#include <stdio.h>

// Number of elements of vectors X and Y.
#define N 3

void print_vector(double A[], char name[]) {
    printf("%s = ", name);
    for(int i = 0; i < N; ++i)
        printf("%lf ", A[i]);
    printf("\n");
}

int main() {
    double A = 3;
    double X[N] = {1.3, 2.2, 3.1};
    double Y[N] = {5.0, 4.43, 3.1234};         

    print_vector(X, "X");
    print_vector(Y, "Y");
    printf("Calculating Y = AX + Y.\n");

    cblas_daxpy(N, A, X, 1, Y, 1);

    print_vector(Y, "Y");
    return 0;
}
