#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

#define SIZE 700

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int i, j, k;

    
    int num_threads =4; 
    omp_set_num_threads(num_threads);

    // Initialize matrices
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    double start = omp_get_wtime();
    
    // Parallel matrix multiplication with chunking
    #pragma omp parallel for private(i, j, k) schedule(static, 1000000)
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    double end = omp_get_wtime();
    
    printf("Parallel Execution Time: %f seconds using %d threads\n", end - start, num_threads);

    return 0;
}