#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int myrank, nprocs;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	
	 if(myrank == 0)
	 {
	 	int n = atoi(argv[1]);
		int p = atoi(argv[2]);
	
		int** matrix;
	
		matrix = (int**)malloc(sizeof(int*)*n);
	
		int i, r, j;
		srand(time(NULL));
		for(i = 0; i < n; i++)
		{
			matrix[i] = (int*)malloc(sizeof(int) * n);	
			for(j = 0; j < n; j++)
				matrix[i][j] = rand() % 10 ;
		}
		
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				printf("%d ",matrix[i][j]);
			}
		
			putchar('\n');
		}
		
	
	 }
	 else
	 {
	 	
	 }
    MPI_Finalize();
    return 0;
}
