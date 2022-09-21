/// @file Matrix44d.h
/// @brief Matrix44d class declaration.
/// @author Jean-Philippe (me\@darkh.app)

#ifndef MATH_LIBRARY_MATRIX44D_H
#define MATH_LIBRARY_MATRIX44D_H

#include "Vector3d.h"
#define e11 elements[0] ///< 1st row, 1st column
#define e12 elements[1] ///< 1st row, 2nd column
#define e13 elements[2] ///< 1st row, 3rd column
#define e14 elements[3] ///< 1st row, 4th column
#define e21 elements[4] ///< 2nd row, 1st column
#define e22 elements[5] ///< 2nd row, 2nd column
#define e23 elements[6] ///< 2nd row, 3rd column
#define e24 elements[7] ///< 2nd row, 4th column
#define e31 elements[8] ///< 3rd row, 1st column
#define e32 elements[9] ///< 3rd row, 2nd column
#define e33 elements[10]///< 3rd row, 3rd column
#define e34 elements[11]///< 3rd row, 4th column
#define e41 elements[12]///< 4th row, 1st column
#define e42 elements[13]///< 4th row, 2nd column
#define e43 elements[14]///< 4th row, 3rd column
#define e44 elements[15]///< 4th row, 4th column

/// @struct Matrix44d
/// @brief A 4x4 matrix of doubles.
struct Matrix44d {
    double elements[16]{};///< The elements of the matrix.

    /// @brief Loads the identity matrix, i.e. a matrix with 1.0 on the diagonal and 0.0 everywhere else.
    void loadIdentity();

    /// @brief Transposes the matrix.
    void transpose();

    /// @brief Loads a scale matrix.
    /// @param x The scale factor on the x-axis, with a default value of 1.0.
    /// @param y The scale factor on the y-axis, with a default value of 1.0.
    /// @param z The scale factor on the z-axis, with a default value of 1.0.
    void loadScale(double x = 1.0, double y = 1.0, double z = 1.0);

    /// @brief Loads an orthographic projection matrix.
    /// @param height The height of the view.
    /// @param width The width of the view.
    void loadOrthographic(int width, int height);

    /// @brief Loads a scale matrix.
    /// @param scale The scale factor on the x, y and z axis.
    void loadScale(const Vector3d &scale);

    /// @brief Loads a rotation matrix around the x-axis.
    /// @param angle The angle of rotation.
    void loadXRotation(const double &angle);

    /// @brief Loads a rotation matrix around the y-axis.
    /// @param angle The angle of rotation.
    void loadYRotation(const double &angle);

    /// @brief Loads a rotation matrix around the z-axis.
    /// @param angle The angle of rotation.
    void loadZRotation(const double &angle);

    /// @brief Loads a rotation matrix around an arbitrary axis.
    /// @param angle The angle of rotation.
    /// @param axis The axis, which is a unit vector. If it is not a unit vector, it will be normalized.
    /// @note If the axis is not normalized, it will take more time to compute the rotation matrix, due to needing to normalize it.
    /// If you know that the axis is already normalized, use loadRotationOnNormalizedAxis instead, as it does not need to check if the axis is normalized
    /// and thus is faster.
    /// @see loadRotationOnNormalizedAxis
    void loadRotationOnAxis(const double &angle, const Vector3d &axis);

    /// @brief Loads a rotation matrix around an arbitrary axis.
    /// @param angle The angle of rotation.
    /// @param axis The axis, which is a unit vector.
    /// @note This method assumes that the axis is normalized. If it is not, the result will be incorrect.
    /// If you are not sure if the axis is normalized, use loadRotationOnAxis instead, as it will normalize the axis if it is not normalized.
    /// @see loadRotationOnAxis
    void loadRotationOnNormalizedAxis(const double &angle, const Vector3d &axis);

    /// @brief Multiplies the matrix by a vector.
    /// @param vector The vector to multiply.
    /// @return The result of the multiplication.
    Vector3d operator*(const Vector3d &vector) const;
};


#endif// MATH_LIBRARY_MATRIX44D_H
