#include <cblas.h>

void my_blas_matmul(int n, float *c, float *a, float *b) {

    const double alpha = 1.0;
    const double beta = 0.0;
    const int lda = n;
    const int ldb = n;
    const int ldc = n;

    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
	      n, n, n, alpha, a, lda, b, ldb, beta, c, ldc);
}