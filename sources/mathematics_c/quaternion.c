#include <stdlib.h>

#include "quaternion.h"
#include "quaternion_internal.h"

Quaternion *quaternion_create(float w, float x, float y, float z) {
    Quaternion *q = (Quaternion*) malloc(sizeof(Quaternion));
    if (q == NULL) {
        return NULL;
    }

    q->w = w;
    q->x = x;
    q->y = y;
    q->z = z;

    return q;
}

void quaternion_destroy(Quaternion *q) {
    free(q);
}

int quaternion_equal(const Quaternion *a, const Quaternion *b) {
    if (a->w == b->w &&
        a->x == b->x &&
        a->y == b->y &&
        a->z == b->z) {
        return 1;
    }
    return 0;
}

Quaternion *quaternion_conjugate(const Quaternion *q) {
    Quaternion *r = quaternion_create(q->w, -q->x, -q->y, -q->z);
    if (r == NULL) {
        return NULL;
    }
    return r;
}

void quaternion_conjugate_l(Quaternion *q) {
    q->x *= -1;
    q->y *= -1;
    q->z *= -1;
}

Quaternion *quaternion_multiply(const Quaternion *a, const Quaternion *b) {
    Quaternion *r = quaternion_create(
            a->w * b->w - a->x * b->x - a->y * b->y - a->z * b->z,
            a->w * b->x + a->x * b->w + a->y * b->z - a->z * b->y,
            a->w * b->y - a->x * b->z + a->y * b->w + a->z * b->x,
            a->w * b->z + a->x * b->y - a->y * b->x + a->z * b->w);
    if (r == NULL) {
        return NULL;
    }
    return r;
}

void quaternion_multiply_l(Quaternion *a, const Quaternion *b) {
    float aw = a->w;
    float ax = a->x;
    float ay = a->y;
    float az = a->z;

    a->w = aw * b->w - ax * b->x - ay * b->y - az * b->z;
    a->x = aw * b->x + ax * b->w + ay * b->z - az * b->y;
    a->y = aw * b->y - ax * b->z + ay * b->w + az * b->x;
    a->z = aw * b->z + ax * b->y - ay * b->x + az * b->w;
}

void quaternion_multiply_r(const Quaternion *a, Quaternion *b) {
    float bw = b->w;
    float bx = b->x;
    float by = b->y;
    float bz = b->z;

    b->w = a->w * bw - a->x * b->x - a->y * by - a->z * bz;
    b->x = a->w * bx + a->x * bw + a->y * bz - a->z * by;
    b->y = a->w * by - a->x * bz + a->y * bw + a->z * bx;
    b->z = a->w * bz + a->x * by - a->y * bx + a->z * bw;
}