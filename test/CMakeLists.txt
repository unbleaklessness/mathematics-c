cmake_minimum_required(VERSION 3.2)

set(MY_TEST_PROJECT_NAME mathematics-test)

project(${MY_TEST_PROJECT_NAME})

add_subdirectory(lib/googletest)

include_directories(${MY_SOURCE_DIR})
include_directories(lib/googletest/googletest/include)

set(MY_TEST_FILES
  main.c
  matrix_test.c
  vector_test.c
)

add_executable(${MY_TEST_PROJECT_NAME} ${MY_TEST_FILES})
target_link_libraries(${MY_TEST_PROJECT_NAME} ${MY_MATHEMATICS_PROJECT_NAME} gtest)
install(TARGETS ${MY_TEST_PROJECT_NAME} DESTINATION ${MY_INSTALL_BINARY_DIR})