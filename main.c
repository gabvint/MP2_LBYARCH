#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>  

extern double dot_product_asm(double* A, double* B, int n);

double dot_product_c(double* A, double* B, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += A[i] * B[i];
    }
    return sum;
}

int main() {
    printf("Starting main function...\n");
    const int n = 1 << 20; 
    double* A = (double*)_aligned_malloc(sizeof(double) * n, 16);
    double* B = (double*)_aligned_malloc(sizeof(double) * n, 16);
    if (!A || !B) {
        printf("Memory allocation failed! A = %p, B = %p\n", (void*)A, (void*)B);
        return 1;
    }
    // Initialize vectors
    for (int i = 0; i < n; ++i) {
        A[i] = 1.0;
        B[i] = 2.0;
    }

    // Time the C version
    double c_result = 0.0;
    clock_t start = clock();
    for (int i = 0; i < 20; ++i) {
        c_result = dot_product_c(A, B, n);
    }
    clock_t end = clock();
    double c_time = (double)(end - start) / CLOCKS_PER_SEC / 20.0;

    // Time the ASM version
    double asm_result = 0.0;
    start = clock();
    for (int i = 0; i < 20; ++i) {
        asm_result = dot_product_asm(A, B, n);
    }
    end = clock();
    double asm_time = (double)(end - start) / CLOCKS_PER_SEC / 20.0;

    // Output results
    printf("C Result: %f\n", c_result);
    printf("ASM Result: %f\n", asm_result);
    printf("C Average Time: %f sec\n", c_time);
    printf("ASM Average Time: %f sec\n", asm_time);

    _aligned_free(A);
    _aligned_free(B);
    return 0;
}
