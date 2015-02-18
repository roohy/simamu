
#include <stdio.h>
#include <stdlib.h>

extern void matrixMultiplication(int N, double **A, double **B, double **C, int threadCount);
extern double read_timer();

double** Make2DDoubleArray(int arraySizeX, int arraySizeY)
{
  double** theArray;
  theArray = (double**) malloc(arraySizeX*sizeof(double*));
  int i = 0;

  for (i = 0; i < arraySizeX; i++)
    theArray[i] = (double*) malloc(arraySizeY*sizeof(double));
  return theArray;
} 

int main(int argc, char **argv)
{
  int N = 1000;  
  int i = 0, j = 0;

  double **A = Make2DDoubleArray(N, N);
  double **B = Make2DDoubleArray(N, N);
  double **C = Make2DDoubleArray(N, N);
 
  for (i = 0; i < N; i++) {
     for (j = 0; j < N; j++) {
        A[i][j] = drand48() * 1000;
        B[i][j] = drand48() * 1000;
     }
  }

  double seconds = read_timer();
  matrixMultiplication(N, A, B, C, 8);
  double elapse = read_timer() - seconds;
 
  fprintf(stderr, "time: %g\n", elapse);
  // return 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%5.2f ", C[i][j]);
    }
    printf("\n");
  } 

  return 0;
}
