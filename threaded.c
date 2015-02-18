#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
void
matrixMultiplication(int N, double **A, double **B, double **C, int threadCount)
{
	omp_set_nested(1);
   int i = 0, j = 0, k = 0,tid;
   #pragma omp parallel private(i,j,k,tid) shared(A,B,C) num_threads(threadCount)
   {

   			tid= omp_get_thread_num();
   			int tid2;
   		#pragma omp for 	
   		for(int i = 0 ; i< N ; i++){
   			#pragma omp parallel private(j,k,tid2) shared(A,B,C,tid,i) num_threads(threadCount)
   			{
   				#pragma omp for 
   				for(int j = 0; j < N; j++)
   				{

					for (k = 0; k < N; k++) {
        				 C[i][j] = C[i][j] + A[i][k] * B[k][j];
       				}  
   					
	   				
   				}
   			}



   		}


   } 
   return;
}
