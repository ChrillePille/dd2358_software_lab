#include <gtest/gtest.h>
#include <cstdlib>
#include <ctime>

extern "C" {
    
    //#include "matrix.h"

}

#define bigDIM 100
#define smallDIM 5



TEST(AppTest, Test1) {
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
    //c_mat_mul(smallDIM, c, a, b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_FLOAT_EQ(c[i][j], test_control[i][j]);
        }
    }
}

TEST(AppTest, Test2) {
    // Init
    float a[bigDIM][bigDIM] = {};
    float b[bigDIM][bigDIM];
    float c[bigDIM][bigDIM] = {};
    for (int i = 0; i < bigDIM; i++) {
        for (int j = 0; j < bigDIM; j++) {
            if (i == j) {
                a[i][j] = 1.0f;
            }
            b[i][j] = -100 + float(rand()) /(float(RAND_MAX/200));
        }
    }

    //Compute
    //c_mat_mul(bigDIM, c, a, b);

    // Assert
    for (int i = 0; i < smallDIM; i++) {
        for (int j = 0; j < smallDIM; j++) {
            ASSERT_FLOAT_EQ(c[i][j], b[i][j]);
        }
    }
}

TEST(AppTest, Test3) {
    // Init

    //Compute

    // Assert
}

int main(int argc, char **argv) {
    srand((unsigned int)time(0));  
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}