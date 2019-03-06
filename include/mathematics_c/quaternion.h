#ifndef QUATERNION_H_
#define QUATERNION_H_

#include "macro.h"

MY_LIB_BEGIN_DECLARATIONS

typedef struct Quaternion Quaternion;

Quaternion *quaternion_create(float w, float x, float y, float z);
void quaternion_destroy(Quaternion *q);

int quaternion_equal(const Quaternion *a, const Quaternion *b);

Quaternion *quaternion_conjugate(const Quaternion *q);
void quaternion_conjugate_l(Quaternion *q);

Quaternion *quaternion_multiply(const Quaternion *a, const Quaternion *b);
void quaternion_multiply_l(Quaternion *a, const Quaternion *b);
void quaternion_multiply_r(const Quaternion *a, Quaternion *b);

MY_LIB_END_DECLARATIONS

#endif // QUATERNION_H_
