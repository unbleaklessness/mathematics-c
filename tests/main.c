#include <check.h>

#include "mathematics_c/matrix_test.h"
#include "mathematics_c/vector_test.h"
#include "mathematics_c/quaternion_test.h"
#include "mathematics_c/mathematics_test.h"

int main(int argc, char **argv) {
    Suite *core_suite = suite_create("Mathematics C test suite");
    SRunner *core_suite_runner = srunner_create(core_suite);

    suite_add_tcase(core_suite, create_matrix_test_case());
    suite_add_tcase(core_suite, create_vector_test_case());
    suite_add_tcase(core_suite, create_quaternion_test_case());
    suite_add_tcase(core_suite, create_mathematics_test_case());

    srunner_run_all(core_suite_runner, CK_ENV);
    int n_failed = srunner_ntests_failed(core_suite_runner);
    srunner_free(core_suite_runner);

    return n_failed;
}