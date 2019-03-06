#include "mathematics.h"
#include "matrix_internal.h"
#include "vector_internal.h"
#include "quaternion_internal.h"

#include <string.h>

Vector *matrix_to_vector(const Matrix *m) {

    if (m->c != 1 && m->r != 1) return NULL;

    Vector *v = vector_create(m->r * m->c);
    if (v == NULL) return NULL;

    memcpy(v->d, m->d, m->r * m->c * sizeof(float));

    return v;
}

Matrix *vector_to_vertical_matrix(const Vector *v) {

    Matrix *r = matrix_create(v->s, 1);
    if (r == NULL) return NULL;

    memcpy(r->d, v->d, v->s * sizeof(float));

    return r;
}

Matrix *vector_to_horizontal_matrix(const Vector *v) {

    Matrix *r = matrix_create(1, v->s);
    if (r == NULL) return NULL;

    memcpy(r->d, v->d, v->s * sizeof(float));

    return r;
}

Vector *quaternion_to_vector(const Quaternion *q) {
    Vector *v = vector_create(3);
    if (v == NULL) {
        return NULL;
    }

    v->d[0] = q->x;
    v->d[1] = q->y;
    v->d[2] = q->z;

    return v;
}

Vector *quaternion_vector_multiply(const Quaternion *q, const Vector *v) {
    if (v->s != 3) {
        return NULL;
    }

    Quaternion *qv = quaternion_create(0.0f, v->d[0], v->d[1], v->d[2]);
    if (qv == NULL) {
        return NULL;
    }

    Quaternion *qc = quaternion_conjugate(q);
    if (qc == NULL) {
        quaternion_destroy(qv);
        return NULL;
    }

    quaternion_multiply_r(q, qv);
    quaternion_multiply_l(qv, qc);

    Vector *r = quaternion_to_vector(qv);

    quaternion_destroy(qc);
    quaternion_destroy(qv);

    if (r == NULL) {
        return NULL;
    }

    return r;
}