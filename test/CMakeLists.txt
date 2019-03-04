cmake_minimum_required(VERSION 3.2)

set(MY_TEST_PROJECT_NAME mathematics-test)

project(${MY_TEST_PROJECT_NAME})

include_directories(${MY_SOURCE_DIR})

set(MY_TEST_FILES
        main.c
        matrix_test.h
        vector_test.h
)

add_executable(${MY_TEST_PROJECT_NAME} ${MY_TEST_FILES})
target_link_libraries(${MY_TEST_PROJECT_NAME} mathematics check m rt pthread subunit)
install(TARGETS ${MY_TEST_PROJECT_NAME} DESTINATION ${MY_INSTALL_BINARY_DIR})