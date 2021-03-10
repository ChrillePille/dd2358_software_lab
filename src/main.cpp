#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/time.h>
#include <string.h>
#include "cwblas.h"

extern "C" {
    
    #include "matrix.h"

}

double gettime() {
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return tv.tv_sec + 1e-6*tv.tv_usec;
}

int main(int argc, char **argv)
{
  if (argc < 2) {
    fprintf(stderr, "Usage: %s \n", argv[0]);
    exit(-1);
  }
  
  const int m = atoi(argv[1]);

  //float *A = (float *) malloc( m * m * sizeof(float));
  //float *B = (float *) malloc( m * m * sizeof(float));
  //float *C = (float *) malloc( m * m * sizeof(float));
  
  float A[m][m];
  float B[m][m];
  float C[m][m] = {};
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = 1.0f;
      B[i][j] = 2.0f;
    }
  }
  
  double t = gettime();
  for (int i = 0; i < 100; i++)
    // select which function to use
    //c_mat_mul(m, C, A, B);
    my_blas_matmul(m, *C, *A, *B);
  t = gettime() - t;

  printf("%d\t%f\t%E\n", m, t, (100 * 2 * m * m * m) / t);

  //free(*A);
  //free(*B);
  //free(*C);
  return 0;
}