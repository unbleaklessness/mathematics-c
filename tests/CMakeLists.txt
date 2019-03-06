cmake_minimum_required(VERSION 3.0)

set(NAME mathematics_c_test)

add_executable(${NAME} main.c mathematics_c/matrix_test.h mathematics_c/vector_test.h)

target_include_directories(${NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(${NAME} mathematics_c check m rt pthread subunit)