#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include "macro.h"
#include "matrix.h"
#include "vector.h"
#include "quaternion.h"

MY_LIB_BEGIN_DECLARATIONS

Vector *matrix_to_vector(const Matrix *m);
Matrix *vector_to_vertical_matrix(const Vector *v);
Matrix *vector_to_horizontal_matrix(const Vector *v);

Vector *quaternion_to_vector(const Quaternion *q);
Vector *quaternion_vector_multiply(const Quaternion *q, const Vector *v);

MY_LIB_END_DECLARATIONS

#endif // MATHEMATICS_H_
