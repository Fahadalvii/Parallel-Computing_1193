#include <stdio.h>
#include <omp.h>

#define SIZE 520

int main()
{
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int i, j, k;

    printf("matrices with sample values"); 
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            A[i][j] = i + j;  
            B[i][j] = i - j;  
        }
    }

    
    double start = omp_get_wtime();
    
    // Matrix multiplication
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    
    double end = omp_get_wtime();

    
    double time_taken = end - start;
    printf("Sequential Execution Time: %f seconds\n", time_taken);

    return 0;
}