
void
matrixMultiplication(int N, double **A, double **B, double **C, int threadCount)
{
   int i = 0, j = 0, k = 0;

   for (i = 0; i < N; i++) {
     for (j = 0; j < N; j++) {
       for (k = 0; k < N; k++) {
         C[i][j] = C[i][j] + A[i][k] * B[k][j];
       }
     }
   }

   return;
}
