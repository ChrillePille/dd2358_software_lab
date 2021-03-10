#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>
#include "cwblas.h"

extern "C" {
    
    #include "matrix.h"

}

#define bigDIM 100
#define smallDIM 5

TEST(AppTest, NaiveTest1) {
    float a[smallDIM][smallDIM];
    float b[smallDIM][smallDIM];
    float c[smallDIM][smallDIM] = {};
    float test_control[smallDIM][smallDIM] = {{5.0, 10.0, 15.0, 20.0, 25.0}, 
                                              {10.0, 20.0, 30.0, 40.0, 50.0}, 
                                              {15.0, 30.0, 45.0, 60.0, 75.0}, 
                                              {20.0, 40.0, 60.0, 80.0, 100.0}, 
                                              {25.0, 50.0, 75.0, 100.0, 125.0}};
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            a[i][j] = float(i) + 1.0f;
            b[i][j] = float(j) + 1.0f;
        }
    }

    //Compute
    c_mat_mul(smallDIM, *c, *a, *b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_FLOAT_EQ(test_control[i][j], c[i][j]);
        }
    }
}

TEST(AppTest, NaiveTest2) {
    // Init
    float a[bigDIM][bigDIM] = {};
    float b[bigDIM][bigDIM];
    float c[bigDIM][bigDIM] = {};
    for (int i = 0; i < bigDIM; i++) {
        for (int j = 0; j < bigDIM; j++) {
            if (i == j) {
                a[i][j] = 1.0f;
            }
            b[i][j] = -100.0f + float(rand()) /(float(RAND_MAX/200.0f));
        }
    }

    //Compute
    c_mat_mul(bigDIM, *c, *a, *b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_FLOAT_EQ(b[i][j], c[i][j]);
        }
    }
}

TEST(AppTest, NaiveTest3) {
    // Init
    float a[smallDIM][smallDIM] = {{4.0f, 5.0f, 2.0f, 6.0f, 4.0f}, 
                                   {3.0f, 1.0f, 3.0f, -8.0f, 2.0f}, 
                                   {4.0f, 6.0f, 8.0f, -3.0f, 5.0f}, 
                                   {0.0f, 2.0f, 0.0f, 3.0f, 5.0f}, 
                                   {1.0f, 2.0f, 3.0f, 4.0f, 5.0f}};
    float b[smallDIM][smallDIM] = {{293/1242.0f, 103/414.0f, (-23)/108.0f, (-589)/2484.0f, 67/414.0f}, 
                                   {14/621.0f, (-41)/207.0f, 13/54.0f, 347/1242.0f, (-95)/207.0f}, 
                                   {(-13)/138.0f, (-3)/46.0f, 1/12.0f, (-61)/276.0f, 11/46.0f}, 
                                   {29/621.0f, (-11)/207.0f, (-1)/27.0f, (-62)/621.0f, 25/207.0f}, 
                                   {(-1)/27.0f, 1/9.0f, (-2)/27.0f, 4/27.0f, 1/9.0f}};
    float c[smallDIM][smallDIM] = {};
    float test_control[smallDIM][smallDIM] = {};
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            if (i == j) {
                test_control[i][j] = 1.0f;
            }
        }
    }

    //Compute
    c_mat_mul(smallDIM, *c, *a, *b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_NEAR(test_control[i][j], c[i][j], 1e-6);
        }
    }
}

TEST(AppTest, DISABLED_BLASTest1) {
    float a[smallDIM][smallDIM];
    float b[smallDIM][smallDIM];
    float c[smallDIM][smallDIM] = {};
    float test_control[smallDIM][smallDIM] = {{5.0, 10.0, 15.0, 20.0, 25.0}, 
                                              {10.0, 20.0, 30.0, 40.0, 50.0}, 
                                              {15.0, 30.0, 45.0, 60.0, 75.0}, 
                                              {20.0, 40.0, 60.0, 80.0, 100.0}, 
                                              {25.0, 50.0, 75.0, 100.0, 125.0}};
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            a[i][j] = float(i) + 1.0f;
            b[i][j] = float(j) + 1.0f;
        }
    }

    //Compute
    my_blas_matmul(smallDIM, *c, *a, *b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_FLOAT_EQ(test_control[i][j], c[i][j]);
        }
    }
}

TEST(AppTest, DISABLED_BLASTest2) {
    // Init
    float a[bigDIM][bigDIM] = {};
    float b[bigDIM][bigDIM];
    float c[bigDIM][bigDIM] = {};
    for (int i = 0; i < bigDIM; i++) {
        for (int j = 0; j < bigDIM; j++) {
            if (i == j) {
                a[i][j] = 1.0f;
            }
            b[i][j] = -100.0f + float(rand()) /(float(RAND_MAX/200.0f));
        }
    }

    //Compute
    my_blas_matmul(bigDIM, *c, *a, *b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_FLOAT_EQ(b[i][j], c[i][j]);
        }
    }
}

TEST(AppTest, DISABLED_BLASTest3) {
    // Init
    float a[smallDIM][smallDIM] = {{4.0f, 5.0f, 2.0f, 6.0f, 4.0f}, 
                                   {3.0f, 1.0f, 3.0f, -8.0f, 2.0f}, 
                                   {4.0f, 6.0f, 8.0f, -3.0f, 5.0f}, 
                                   {0.0f, 2.0f, 0.0f, 3.0f, 5.0f}, 
                                   {1.0f, 2.0f, 3.0f, 4.0f, 5.0f}};
    float b[smallDIM][smallDIM] = {{293/1242.0f, 103/414.0f, (-23)/108.0f, (-589)/2484.0f, 67/414.0f}, 
                                   {14/621.0f, (-41)/207.0f, 13/54.0f, 347/1242.0f, (-95)/207.0f}, 
                                   {(-13)/138.0f, (-3)/46.0f, 1/12.0f, (-61)/276.0f, 11/46.0f}, 
                                   {29/621.0f, (-11)/207.0f, (-1)/27.0f, (-62)/621.0f, 25/207.0f}, 
                                   {(-1)/27.0f, 1/9.0f, (-2)/27.0f, 4/27.0f, 1/9.0f}};
    float c[smallDIM][smallDIM] = {};
    float test_control[smallDIM][smallDIM] = {};
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            if (i == j) {
                test_control[i][j] = 1.0f;
            }
        }
    }

    //Compute
    my_blas_matmul(smallDIM, *c, *a, *b);
    
    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_NEAR(test_control[i][j], c[i][j], 1e-6);
        }
    }
}

int main(int argc, char **argv) {
    srand((unsigned int)time(0));  
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}