//
// Created by Arsen on 10.05.2020.
//
#include "vector3D.h"
using namespace std;
Vector3D::Vector3D() : Vector3D(0,0,0) {}
Vector3D::Vector3D (double a, double b, double c) {
    x=a;
    y=b;
    z=c;
}
// Деструктор
Vector3D::~Vector3D() {}
double Vector3D::getLength() const {
    return sqrt( (this->x)*this->x + this->y*this->y + this->z*this->z );
}

// Получение координат
double Vector3D::getX() const {
    return x;
}
double Vector3D::getY() const {
    return y;
}
double Vector3D::getZ() const {
    return z;
}

// Задание координат
void Vector3D::setX(double a) {
    x = a;
}
void Vector3D::setY(double b) {
    y = b;
}
void Vector3D::setZ(double c) {
    z = c;
}
// Перегруженный оператор - сравнение двух векторов на равенство
bool Vector3D::operator== (const Vector3D& v2) const {
    double eps = 1/1000000;
    return abs(x - v2.x) < eps && abs(y - v2.y) < eps && abs(z - v2.z) < eps;
    //return x == v2.x && y == v2.y && z == v2.z;
}
// Ещё один перегруженный оператор - неравенство векторов
bool Vector3D::operator!= (const Vector3D& v2) const {
    return !(*this == v2);
}
// Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
Vector3D Vector3D::operator+ (const Vector3D& v2) const {
    Vector3D vec;
    vec.x = x + v2.x;
    vec.y = y + v2.y;
    vec.z = z + v2.z;
    return vec;
}

// Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
Vector3D Vector3D::operator- (const Vector3D& v2) const {
    Vector3D vec;
    vec.x = x - v2.x;
    vec.y = y - v2.y;
    vec.z = z - v2.z;
    return vec;
}

// Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
Vector3D Vector3D::operator* (const double a) const {
    Vector3D vec;
    vec.x = x * (double)a;
    vec.y = y * (double)a;
    vec.z = z * (double)a;
    return vec;
}

double Vector3D::operator* (const Vector3D& v) const {
    double s;
    s = x*v.x + y*v.y + z*v.z;
    return s;
}

Vector3D operator *( double d, const Vector3D &v );

Vector3D operator *( double d, const Vector3D &v )
{
    return v * d;
}

// Вывод вектора, ожидается строго в формате (1; 1)
ostream& operator<<(ostream& os, const Vector3D& v) {
    os << "(" << v.getX() << "; " << v.getY() << "; " << v.getZ() << ")";
    return os;
}

// Чтение вектора, читает просто две координаты без хитростей
istream& operator>>(istream& is, Vector3D& v) {
    double a, b, c;
    is >> a >> b >> c;
    v.setX(a);
    v.setY(b);
    v.setZ(c);
    return is;
}

