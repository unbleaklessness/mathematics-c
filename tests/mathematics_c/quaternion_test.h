#ifndef QUATERNION_TEST_H_
#define QUATERNION_TEST_H_

#include <check.h>

#include "quaternion.h"

START_TEST(Quaternion_equal_1)
    {
        Quaternion *q1 = quaternion_create(3.0f, 1.75f, -4.0f, -5.0f);
        Quaternion *q2 = quaternion_create(3.0f, 1.75f, -4.0f, -5.0f);
        int result = quaternion_equal(q1, q2);

        ck_assert_int_eq(1, result);

        quaternion_destroy(q1);
        quaternion_destroy(q2);
    }
END_TEST

START_TEST(Quaternion_equal_2)
    {
        Quaternion *q1 = quaternion_create(3.0f, 1.75f, -4.1f, -5.0f);
        Quaternion *q2 = quaternion_create(3.0f, 1.75f, -4.0f, -5.0f);
        int result = quaternion_equal(q1, q2);

        ck_assert_int_eq(0, result);

        quaternion_destroy(q1);
        quaternion_destroy(q2);
    }
END_TEST

START_TEST(Quaternion_multiplication)
    {
        Quaternion *q1 = quaternion_create(2.0f, 0.0f, -6.0f, 0.0f);
        Quaternion *q2 = quaternion_create(1.0f, 3.0f, -2.0f, 0.0f);
        Quaternion *result = quaternion_multiply(q1, q2);
        Quaternion *expected = quaternion_create(-10.0f, 6.0f, -10.0f, 18.0f);

        ck_assert_int_eq(1, quaternion_equal(result, expected));

        quaternion_destroy(q1);
        quaternion_destroy(q2);
        quaternion_destroy(result);
        quaternion_destroy(expected);
    }
END_TEST

START_TEST(Quaternion_left_multiplication)
    {
        Quaternion *q1 = quaternion_create(2.0f, 0.0f, -6.0f, 0.0f);
        Quaternion *q2 = quaternion_create(1.0f, 3.0f, -2.0f, 0.0f);
        quaternion_multiply_l(q1, q2);
        Quaternion *expected = quaternion_create(-10.0f, 6.0f, -10.0f, 18.0f);

        ck_assert_int_eq(1, quaternion_equal(q1, expected));

        quaternion_destroy(q1);
        quaternion_destroy(q2);
        quaternion_destroy(expected);
    }
END_TEST

START_TEST(Quaternion_right_multiplication)
    {
        Quaternion *q1 = quaternion_create(2.0f, 0.0f, -6.0f, 0.0f);
        Quaternion *q2 = quaternion_create(1.0f, 3.0f, -2.0f, 0.0f);
        quaternion_multiply_r(q1, q2);
        Quaternion *expected = quaternion_create(-10.0f, 6.0f, -10.0f, 18.0f);

        ck_assert_int_eq(1, quaternion_equal(q2, expected));

        quaternion_destroy(q1);
        quaternion_destroy(q2);
        quaternion_destroy(expected);
    }
END_TEST

START_TEST(Quaternion_conjugate)
    {
        Quaternion *q = quaternion_create(-10.0f, 6.0f, -10.0f, 18.0f);
        Quaternion *result = quaternion_conjugate(q);
        Quaternion *expected = quaternion_create(-10.0f, -6.0f, 10.0f, -18.0f);

        ck_assert_int_eq(1, quaternion_equal(result, expected));

        quaternion_destroy(q);
        quaternion_destroy(result);
        quaternion_destroy(expected);
    }
END_TEST

TCase *create_quaternion_test_case() {
    TCase *t = tcase_create("Quaternion");

    tcase_add_test(t, Quaternion_equal_1);
    tcase_add_test(t, Quaternion_equal_2);
    tcase_add_test(t, Quaternion_multiplication);
    tcase_add_test(t, Quaternion_left_multiplication);
    tcase_add_test(t, Quaternion_right_multiplication);
    tcase_add_test(t, Quaternion_conjugate);

    return t;
}

#endif // QUATERNION_TEST_H_
