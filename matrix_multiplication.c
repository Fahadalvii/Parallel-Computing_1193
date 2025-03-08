#include <stdio.h>
#include <time.h> 
#include <omp.h>  

int main()
{
    int A[3][3], B[3][3], C[3][3], i, j, k;

    printf("Enter values for first matrix:");
    {
        printf("\nEnter values for 2d array :");
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter values for second matrix:");
    printf("\nEnter values for 2d array :");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }
    printf("\nFirst Matrix:");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", A[i][j]);
        }
    }
    printf("\nSecond Matrix:");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", B[i][j]);
        }
    }
    printf("\n");
    int num_threads = 4; // Adjust based on CPU cores
    omp_set_num_threads(num_threads);

    clock_t start = clock();
    // OpenMP parallelized matrix multiplication
    #pragma omp parallel for private(i, j, k) shared(A, B, C)
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            C[i][j]=0;
            for (k=0;k<3;k++)
            C[i][j]+=A[i][k]*B[k][j];
            
        }
        
    }
    clock_t end = clock();
    printf("\nMultiplication of matrix is:");
    for (int i = 0; i < 3; i++)
    {
        printf("\n");
        for (int j = 0; j < 3; j++)
        printf("%d\t", C[i][j]);
    }
    printf("\n");

    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Parallel Execution Time with OpenMP: %f seconds\n", time_taken);
    return 0;
}