#include <check.h>

#include "matrix_test.h"
#include "vector_test.h"

int main(int argc, char **argv) {
    Suite *core_suite = suite_create("Core");
    SRunner *core_suite_runner = srunner_create(core_suite);

    suite_add_tcase(core_suite, create_matrix_test_case());
    suite_add_tcase(core_suite, create_vector_test_case());

    srunner_run_all(core_suite_runner, CK_ENV);
    int n_failed = srunner_ntests_failed(core_suite_runner);
    srunner_free(core_suite_runner);

    return n_failed;
}