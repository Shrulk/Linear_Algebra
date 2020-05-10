//
// Created by Arsen on 10.05.2020.
//

#ifndef LINEAR_ALGEBRA_MASTER_MATRIX_H
#define LINEAR_ALGEBRA_MASTER_MATRIX_H
#include "vector3D.h"

class Matrix3D {
private:
    double a11, a12, a13;
    double a21, a22, a23;
    double a31, a32, a33;
public:
    Matrix3D();
    Matrix3D(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33);
    double det();
    friend ostream& operator<<(ostream& os, const Matrix3D& m);
    friend istream& operator>>(istream& is, Matrix3D& m);

    Matrix3D operator* (const double a) const;
    friend Matrix3D operator *( double d, const Matrix3D& v );

    Matrix3D operator* (const Matrix3D& m);
    Vector3D operator*(const Vector3D& v);
    Matrix3D operator+(const Matrix3D& m);
    Matrix3D operator-(const Matrix3D& m);
};
Matrix3D operator *( double d, const Matrix3D& v );
istream& operator>>(istream& is, Matrix3D& m);
ostream& operator<<(ostream& os, const Matrix3D& m);
#endif //LINEAR_ALGEBRA_MASTER_MATRIX_H
