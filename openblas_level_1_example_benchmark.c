#include <cblas.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Number of elements of vectors X and Y.
#define N 1000000

void print_vector(double A[], char name[]) {
    printf("%s = ", name);
    for(int i = 0; i < N; ++i)
        printf("%lf ", A[i]);
    printf("\n");
}

double random_double(double min, double max) {
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

void openblas(double A, double X[], double Y[]) {
    cblas_daxpy(N, A, X, 1, Y, 1);
}

void measure(double A, double X[], double Y[], char fun[], void (*f)(double, double[], double[])) {
    clock_t tic, toc;
    tic = clock();
    f(A, X, Y);
    toc = clock();
    printf("%f (%s)\n", (double)(toc - tic), fun);
}

void naive(double A, double X[], double Y[]) {
    for(int i = 0; i < N; ++i)
        Y[i] = A * X[i] + Y[i];
}

int main() {
    srand(time(NULL));
    double A = 1;
    static double X[N];
    double Y[N];

    for(int i = 0; i < N; ++i) {
        X[i] = random_double(-1337.7331, 1337.7331);
        Y[i] = random_double(-1337.7331, 1337.7331);
    }

    for(int i = 0; i < 8; ++i) {
        measure(A, X, Y, "openblas", openblas);
        measure(A, X, Y, "naive", naive);
    }

    return 0;
}
