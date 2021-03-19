#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <sys/time.h>
#include <string.h>
#include <math.h>
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
  const int select = atoi(argv[2]);

  //float *A = (float *) malloc( m * m * sizeof(float));
  //float *B = (float *) malloc( m * m * sizeof(float));
  //float *C = (float *) malloc( m * m * sizeof(float));
  
  float** A = new float*[m];
  float** B = new float*[m];
  float** C = new float*[m];
  for (int i = 0; i < m; i++) {
    A[i] = new float[m];
    B[i] = new float[m];
    C[i] = new float[m];
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = 1.0f;
      B[i][j] = 2.0f;
      C[i][j] = 0.0f;
    }
  }
  
  double t = gettime();
  for (int i = 0; i < 100; i++) {
    if (select == 1) {
      c_mat_mul(m, *C, *A, *B);
    } else {
      my_blas_matmul(m, *C, *A, *B);
    }
  }
  t = gettime() - t;

  printf("%d\t%f\t%E\n", m, t, 100 * 2 * pow(m, 3) / t);

  delete[] A;
  delete[] B;
  delete[] C;
  return 0;
}