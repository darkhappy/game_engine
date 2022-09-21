/// @file Vector3d.h
/// @brief Vector3d class definition.
/// @author Jean-Philippe (me\@darkh.app)

#ifndef MATH_LIBRARY_VECTOR3D_H
#define MATH_LIBRARY_VECTOR3D_H

/// @struct Vector3d
/// @brief A 3D vector of doubles.
struct Vector3d {
    double x;///< The x-component of the vector.
    double y;///< The y-component of the vector.
    double z;///< The z-component of the vector.

    /// @param x The x-component of the vector.
    /// @param y The y-component of the vector.
    /// @param z The z-component of the vector.
    Vector3d(double x, double y, double z);

    /// @brief Calculates the norm of the vector.
    /// @return The norm of the vector.
    [[nodiscard]] double norm() const;

    /// @brief Calculates a normalized version of the vector.
    /// @return A normalized version of the vector.
    [[nodiscard]] Vector3d normalize() const;

    /// @brief Calculates the sum of two vectors.
    /// @param other The other vector.
    /// @return The sum of the two vectors.
    Vector3d operator+(const Vector3d &other) const;

    /// @brief Calculates the difference of two vectors.
    /// @param other The other vector.
    /// @return The difference of the two vectors.
    Vector3d operator-(const Vector3d &other) const;

    /// @brief Calculates the cross product of two vectors.
    /// @param other The other vector.
    /// @return The cross product of the two vectors.
    Vector3d operator*(const Vector3d &other) const;

    /// @brief Calculates the dot product of two vectors.
    /// @param other The other vector.
    /// @return The dot product of the two vectors.
    double operator%(const Vector3d &other) const;

    /// @brief Calculates the product of a vector and a scalar.
    /// @param scalar The scalar.
    /// @return The product of the vector and the scalar.
    Vector3d operator*(const double &scalar) const;

    /// @brief Calculates the angle between two vectors.
    /// @param other The other vector.
    /// @return The angle between the two vectors.
    [[nodiscard]] double angle(const Vector3d &other) const;
};


#endif// MATH_LIBRARY_VECTOR3D_H
