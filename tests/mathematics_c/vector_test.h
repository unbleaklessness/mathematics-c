#ifndef VECTOR_TEST_H_
#define VECTOR_TEST_H_

#include <check.h>

#include "vector.h"

START_TEST(Vector_addition)
    {
        float v1_arr[3] = { 1, 2, 3 };
        Vector *v1 = vector_from_array(v1_arr, 3);

        float v2_arr[3] = { 5, 6, 7 };
        Vector *v2 = vector_from_array(v2_arr, 3);

        Vector *result = vector_add(v1, v2);

        float expected_arr[3] = { 6, 8, 10 };
        Vector *expected = vector_from_array(expected_arr, 3);

        ck_assert_int_eq(1, vector_equal(result, expected));

        vector_destroy(v1);
        vector_destroy(v2);
        vector_destroy(result);
        vector_destroy(expected);
    }
END_TEST

TCase *create_vector_test_case() {
    TCase *t = tcase_create("Vector");

    tcase_add_test(t, Vector_addition);

    return t;
}

#endif // VECTOR_TEST_H_