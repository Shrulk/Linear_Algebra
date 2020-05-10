//
// Created by Arsen on 10.05.2020.
//

#ifndef LINEAR_ALGEBRA_MASTER_VECTOR3D_H
#define LINEAR_ALGEBRA_MASTER_VECTOR3D_H
#include <iostream>
#include <cmath>
using namespace std;
//Vector
class Vector3D {
private:
    double x, y, z;
public:
    Vector3D();
    Vector3D (double a, double b, double c);
    // Деструктор
    ~Vector3D();
    double getLength() const;
    // Получение координат
    double getX() const;
    double getY() const;
    double getZ() const;
    // Задание координат
    void setX(double a);
    void setY(double b);
    void setZ(double c);
    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector3D& v2) const;
    // Ещё один перегруженный оператор - неравенство векторов
    bool operator!= (const Vector3D& v2) const;
    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector3D operator+ (const Vector3D& v2) const;
    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector3D operator- (const Vector3D& v2) const;
    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector3D operator* (double a) const;
    double operator* (const Vector3D& v) const;
    friend Vector3D operator *( double d, const Vector3D &v );
};
Vector3D operator *( double d, const Vector3D &v );
// Вывод вектора, ожидается строго в формате (1; 1)
ostream& operator<<(ostream& os, const Vector3D& v);
// Чтение вектора, читает просто две координаты без хитростей
istream& operator>>(istream& is, Vector3D& v);
#endif //LINEAR_ALGEBRA_MASTER_VECTOR3D_H
