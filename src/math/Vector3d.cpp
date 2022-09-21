/// @file Vector3d.cpp
/// @brief Vector3d class implementation.
/// @author Jean-Philippe (me\@darkh.app)

#include "Vector3d.h"
#include <cmath>

Vector3d::Vector3d(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Vector3d::norm() const {
    return sqrt(x * x + y * y + z * z);
}

Vector3d Vector3d::normalize() const {
    double n = norm();
    return {x / n, y / n, z / n};
}

Vector3d Vector3d::operator+(const Vector3d &other) const {
    return {x + other.x, y + other.y, z + other.z};
}

Vector3d Vector3d::operator-(const Vector3d &other) const {
    return {x - other.x, y - other.y, z - other.z};
}

Vector3d Vector3d::operator*(const Vector3d &other) const {
    double detX = y * other.z - z * other.y;
    double detY = z * other.x - x * other.z;
    double detZ = x * other.y - y * other.x;

    return {detX, detY, detZ};
}

double Vector3d::operator%(const Vector3d &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3d Vector3d::operator*(const double &scalar) const {
    return {x * scalar, y * scalar, z * scalar};
}

double Vector3d::angle(const Vector3d &other) const {
    return acos((*this % other) / (norm() * other.norm()));
}