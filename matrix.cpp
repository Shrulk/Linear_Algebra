//
// Created by Arsen on 10.05.2020.
//
#include "matrix.h"

Matrix3D::Matrix3D() : Matrix3D(0,0,0,0,0,0,0,0,0) {}
Matrix3D::Matrix3D(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
    this -> a11 = a11;
    this -> a12 = a12;
    this -> a13 = a13;
    this -> a21 = a21;
    this -> a22 = a22;
    this -> a23 = a23;
    this -> a31 = a31;
    this -> a32 = a32;
    this -> a33 = a33;
}

double Matrix3D::det(){
    return a11*(a22*a33-a32*a23) - a12*(a21*a33 - a23*a31) + a13*(a21*a32 - a22*a31);
}

ostream& operator<<(ostream& os, const Matrix3D& m);
istream& operator>>(istream& is, Matrix3D& m);

Matrix3D Matrix3D::operator* (const double a) const {
    Matrix3D m;
    m.a11 = a11*a; m.a12 = a12*a; m.a13 = a13*a;
    m.a21 = a21*a; m.a22 = a22*a; m.a23 = a23*a;
    m.a31 = a31*a; m.a32 = a32*a; m.a33 = a33*a;
    return m;
}
Matrix3D operator *( double d, const Matrix3D& v );

Matrix3D Matrix3D::operator* (const Matrix3D& m) {
    Matrix3D mat;
    mat.a11 = a11*m.a11 + a12*m.a21 + a13*m.a31;
    mat.a12 = a11*m.a12 + a12*m.a22 + a13*m.a32;
    mat.a13 = a11*m.a13 + a12*m.a23 + a13*m.a33;

    mat.a21 = a21*m.a11 + a22*m.a21 + a23*m.a31;
    mat.a22 = a21*m.a12 + a22*m.a22 + a23*m.a32;
    mat.a23 = a21*m.a13 + a22*m.a23 + a23*m.a33;

    mat.a31 = a31*m.a11 + a32*m.a21 + a33*m.a31;
    mat.a32 = a31*m.a12 + a32*m.a22 + a33*m.a32;
    mat.a33 = a31*m.a13 + a32*m.a23 + a33*m.a33;
    return mat;
}
Vector3D Matrix3D::operator*(const Vector3D& v) {
    Vector3D vec;
    vec.setX( a11*v.getX() + a12*v.getY() + a13*v.getZ() );
    vec.setY( a21*v.getX() + a22*v.getY() + a23*v.getZ() );
    vec.setZ( a31*v.getX() + a32*v.getY() + a33*v.getZ() );
    return vec;
}
Matrix3D Matrix3D::operator+(const Matrix3D& m) {
    Matrix3D mat;
    mat.a11 = a11+m.a11;
    mat.a12 = a12+m.a12;
    mat.a13 = a13+m.a13;
    mat.a21 = a21+m.a21;
    mat.a22 = a22+m.a22;
    mat.a21 = a21+m.a21;
    mat.a31 = a31+m.a31;
    mat.a32 = a32+m.a32;
    mat.a33 = a33+m.a33;
    return mat;
}
Matrix3D Matrix3D::operator-(const Matrix3D& m) {
    Matrix3D mat;
    mat.a11 = a11-m.a11;
    mat.a12 = a12-m.a12;
    mat.a13 = a13-m.a13;
    mat.a21 = a21-m.a21;
    mat.a22 = a22-m.a22;
    mat.a21 = a21-m.a21;
    mat.a31 = a31-m.a31;
    mat.a32 = a32-m.a32;
    mat.a33 = a33-m.a33;
    return mat;
}

Matrix3D operator *( double d, const Matrix3D& v )
{
    return v * d;
}
istream& operator>>(istream& is, Matrix3D& m) {
    double a, b, c,d,e,f,g,h,i;
    is >> a >> b >> c
       >> d >> e >> f
       >> g >> h >> i;
    m.a11 = a; m.a12 = b; m.a13 = c;
    m.a21 = d; m.a22 = e; m.a23 = f;
    m.a31 = g; m.a32 = h; m.a33 = i;
    return is;
}

ostream& operator<<(ostream& os, const Matrix3D& m) {
    os << m.a11 << " " << m.a12 << " " << m.a13 << endl
       << m.a21 << " " << m.a22 << " " << m.a23 << endl
       << m.a31 << " " << m.a32 << " " << m.a33 << endl;
    return os;
}