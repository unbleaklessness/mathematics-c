#ifndef MATHEMATICS_TEST_H_
#define MATHEMATICS_TEST_H_

#include <check.h>

#include "mathematics.h"

START_TEST(Quaternion_vector_multiplication)
    {
        Quaternion *q = quaternion_create(3.0f, 1.0f, -4.0f, -5.0f);

        float v_arr[3] = { 3.0f, 5.0f, -2.0f };
        Vector *v = vector_from_array(v_arr, 3);

        Vector *result = quaternion_vector_multiply(q, v);

        float expected_arr[3] = { 85.0f, -187.0f, 238.0 };
        Vector *expected = vector_from_array(expected_arr, 3);

        ck_assert_int_eq(1, vector_equal(result, expected));

        quaternion_destroy(q);
        vector_destroy(v);
        vector_destroy(result);
        vector_destroy(expected);
    }
END_TEST

TCase *create_mathematics_test_case() {
    TCase *t = tcase_create("Mathematics");

    tcase_add_test(t, Quaternion_vector_multiplication);

    return t;
}

#endif // MATHEMATICS_TEST_H_
