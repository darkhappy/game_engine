/// @file Matrix44d.cpp
/// @brief Matrix44d class implementation.
/// @author Jean-Philippe (me\@darkh.app)

#include "Matrix44d.h"
#include <algorithm>
#include <cmath>

using std::swap;

void Matrix44d::loadIdentity() {
    e11 = e22 = e33 = e44 = 1.0;
    e12 = e13 = e14 = e21 = e23 = e24 = e31 = e32 = e34 = e41 = e42 = e43 = 0.0;
}

void Matrix44d::transpose() {
    swap(e12, e21);
    swap(e13, e31);
    swap(e14, e41);
    swap(e23, e32);
    swap(e24, e42);
    swap(e34, e43);
}

void Matrix44d::loadScale(double x, double y, double z) {
    e11 = x;
    e22 = y;
    e33 = z;

    e12 = e13 = e14 = e21 = e23 = e24 = e31 = e32 = e34 = e41 = e42 = e43 = 0.0;
    e44 = 1.0;
}

void Matrix44d::loadOrthographic(int width, int height) {
    e11 = 2.0 / (double) width;
    e22 = 2.0 / (double) -height;
    e33 = e42 = e44 = 1.0;
    e41 = -1.0;
    e12 = e13 = e14 = e21 = e23 = e24 = e31 = e32 = e34 = e41 = e43 = 0.0;
}

void Matrix44d::loadScale(const Vector3d &scale) {
    loadScale(scale.x, scale.y, scale.z);
}

void Matrix44d::loadXRotation(const double &angle) {
    e22 = e33 = cos(angle);
    e23 = -sin(angle);
    e32 = -e23;

    e11 = e44 = 1.0;
    e12 = e13 = e14 = e21 = e24 = e31 = e34 = e41 = e42 = e43 = 0.0;
}

void Matrix44d::loadYRotation(const double &angle) {
    e11 = e33 = cos(angle);
    e13 = sin(angle);
    e31 = -e13;

    e14 = e24 = e34 = e41 = e42 = e43 = 0.0;
    e44 = 1.0;
}

void Matrix44d::loadZRotation(const double &angle) {
    e11 = e22 = cos(angle);
    e12 = -sin(angle);
    e21 = -e12;

    e14 = e24 = e34 = e41 = e42 = e43 = 0.0;
    e44 = 1.0;
}

void Matrix44d::loadRotationOnAxis(const double &angle, const Vector3d &axis) {
    if (axis.norm() != 1.0) {
        loadRotationOnNormalizedAxis(angle, axis.normalize());
    } else {
        loadRotationOnNormalizedAxis(angle, axis);
    }
}

void Matrix44d::loadRotationOnNormalizedAxis(const double &angle, const Vector3d &axis) {
    double x = axis.x;
    double y = axis.y;
    double z = axis.z;

    double c = cos(angle);
    double s = sin(angle);
    double t = 1.0 - c;

    e11 = c + axis.x * axis.x * t;
    e12 = axis.x * axis.y * t - axis.z * s;
    e13 = axis.x * axis.z * t + axis.y * s;

    e21 = axis.x * axis.y * t + axis.z * s;
    e22 = c + axis.y * axis.y * t;
    e23 = axis.y * axis.z * t - axis.x * s;

    e31 = axis.x * axis.z * t - axis.y * s;
    e32 = axis.y * axis.z * t + axis.x * s;
    e33 = c + axis.z * axis.z * t;

    e14 = e24 = e34 = e41 = e42 = e43 = 0.0;
    e44 = 1.0;
}

Vector3d Matrix44d::operator*(const Vector3d &vector) const {
    double x = e11 * vector.x + e12 * vector.y + e13 * vector.z + e14;
    double y = e21 * vector.x + e22 * vector.y + e23 * vector.z + e24;
    double z = e31 * vector.x + e32 * vector.y + e33 * vector.z + e34;

    return {x, y, z};
}
