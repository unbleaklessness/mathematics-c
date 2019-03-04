#include <gtest/gtest.h>

#include "matrix.h"

TEST(MATRIX_TEST, 3x3_multiply_on_3x3) {
    matrix<3, 3> m1 { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    matrix<3, 3> m2 { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    matrix<3, 3> m3 = m1 * m2;
}