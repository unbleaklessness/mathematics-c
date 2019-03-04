cmake_minimum_required(VERSION 3.2)

set(MY_MATHEMATICS_PROJECT_NAME mathematics)

set(MY_MATHEMATICS_H_FILES
        matrix.h
        vector.h
        mathematics.h
        macro.h
        matrix_internal.h
        vector_internal.h)

set(MY_MATHEMATICS_CPP_FILES
        matrix.c
        vector.c
        mathematics.c)

set(MY_MATHEMATICS_FILES
  ${MY_MATHEMATICS_H_FILES}
  ${MY_MATHEMATICS_CPP_FILES})

project(${MY_MATHEMATICS_PROJECT_NAME})

add_library(${MY_MATHEMATICS_PROJECT_NAME} SHARED STATIC ${MY_MATHEMATICS_FILES})

install(TARGETS ${MY_MATHEMATICS_PROJECT_NAME} DESTINATION ${MY_INSTALL_LIBRARY_DIR})
install(FILES ${MY_MATHEMATICS_H_FILES} DESTINATION ${MY_INSTALL_INCLUDE_DIR})