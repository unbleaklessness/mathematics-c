#include <gtest/gtest.h>

#include "matrix.h"

TEST(Matrix_test, Test_3x3_multiply_on_3x3) {
    float m1_arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Matrix *m1 = matrix_from_array(m1_arr, 3, 3);
    float m2_arr[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    Matrix *m2 = matrix_from_array(m2_arr, 3, 3);
    Matrix *m3 = matrix_multiply(m1, m2);

    EXPECT_EQ(1, matrix_equal(m1, m2));

    matrix_destroy(m1);
    matrix_destroy(m2);
    matrix_destroy(m3);
}