cmake_minimum_required(VERSION 3.0)

set(NAME mathematics_c)

add_library(${NAME} STATIC SHARED mathematics.c matrix.c matrix_internal.h vector.c vector_internal.h quaternion_internal.h quaternion.c)

target_include_directories(${NAME}
        PUBLIC "${PROJECT_SOURCE_DIR}/include/${NAME}"
        PRIVATE "${PROJECT_SOURCE_DIR}/sources/${NAME}")

install(TARGETS ${NAME} DESTINATION "${CMAKE_INSTALL_LIBDIR}")
install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/${NAME}" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")