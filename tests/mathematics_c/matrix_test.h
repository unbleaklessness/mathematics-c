#ifndef MATRIX_TEST_H_
#define MATRIX_TEST_H_

#include <check.h>

#include "matrix.h"

START_TEST(Matrix_equal_1)
    {
        float m1_arr[4] = { 1, 2, 3, 4 };
        Matrix *m1 = matrix_from_array(m1_arr, 2, 2);

        float m2_arr[4] = { 1, 2, 3, 4 };
        Matrix *m2 = matrix_from_array(m2_arr, 2, 2);

        ck_assert_int_eq(1, matrix_equal(m1, m2));

        matrix_destroy(m1);
        matrix_destroy(m2);
    }
END_TEST

START_TEST(Matrix_equal_2)
    {
        float m1_arr[4] = { 1, 2, 3, 4 };
        Matrix *m1 = matrix_from_array(m1_arr, 2, 2);

        float m2_arr[4] = { 4, 3, 2, 1 };
        Matrix *m2 = matrix_from_array(m2_arr, 2, 2);

        ck_assert_int_ne(1, matrix_equal(m1, m2));

        matrix_destroy(m1);
        matrix_destroy(m2);
    }
END_TEST

START_TEST(Matrix_equal_3)
    {
        float m1_arr[6] = { 1, 2, 3, 4, 5, 6 };
        Matrix *m1 = matrix_from_array(m1_arr, 2, 3);

        float m2_arr[6] = { 1, 2, 3, 4, 5, 6 };
        Matrix *m2 = matrix_from_array(m2_arr, 3, 2);

        ck_assert_int_ne(1, matrix_equal(m1, m2));

        matrix_destroy(m1);
        matrix_destroy(m2);
    }
END_TEST

START_TEST(Multiply_3x3_on_3x3)
    {
        float m1_arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        Matrix *m1 = matrix_from_array(m1_arr, 3, 3);

        float m2_arr[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
        Matrix *m2 = matrix_from_array(m2_arr, 3, 3);

        Matrix *result = matrix_multiply(m1, m2);

        float expected_arr[9] = { 30, 24, 18, 84, 69, 54, 138, 114, 90 };
        Matrix *expected = matrix_from_array(expected_arr, 3, 3);

        ck_assert_int_eq(1, matrix_equal(result, expected));

        matrix_destroy(m1);
        matrix_destroy(m2);
        matrix_destroy(result);
        matrix_destroy(expected);
    }
END_TEST

START_TEST(Multiply_2x3_on_3x2)
    {
        float m1_arr[6] = { 1, 2, 3, 4, 5, 6 };
        Matrix *m1 = matrix_from_array(m1_arr, 2, 3);

        float m2_arr[6] = { 1, 2, 3, 4, 5, 6 };
        Matrix *m2 = matrix_from_array(m2_arr, 3, 2);

        Matrix *result = matrix_multiply(m1, m2);

        float expected_arr[4] = { 22, 28, 49, 64 };
        Matrix *expected = matrix_from_array(expected_arr, 2, 2);

        ck_assert_int_eq(1, matrix_equal(result, expected));

        matrix_destroy(m1);
        matrix_destroy(m2);
        matrix_destroy(result);
        matrix_destroy(expected);
    }
END_TEST

TCase *create_matrix_test_case() {
    TCase *t = tcase_create("Matrix");

    tcase_add_test(t, Matrix_equal_1);
    tcase_add_test(t, Matrix_equal_2);
    tcase_add_test(t, Matrix_equal_3);
    tcase_add_test(t, Multiply_3x3_on_3x3);
    tcase_add_test(t, Multiply_2x3_on_3x2);

    return t;
}

#endif // MATRIX_TEST_H_