#include <iostream>
#include <cmath>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
//Vector
class Vector3D {
private:
    double x, y, z;
public:
    Vector3D() : Vector3D(0,0,0) {}
    Vector3D (double a, double b, double c) {
    x=a;
    y=b;
    z=c;
}
// Деструктор
    ~Vector3D() {}
    double getLength() const {
        return sqrt( (this->x)*this->x + this->y*this->y + this->z*this->z );
    }

    // Получение координат
    double getX() const {
        return x;
    }
    double getY() const {
        return y;
    }
    double getZ() const {
        return z;
    }

    // Задание координат
    void setX(double a) {
        x = a;
    }
    void setY(double b) {
        y = b;
    }
    void setZ(double c) {
        z = c;
    }
    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector3D& v2) const {
        return x == v2.x && y == v2.y && z == v2.z;
    }
    // Ещё один перегруженный оператор - неравенство векторов
    bool operator!= (const Vector3D& v2) const {
        return x != v2.x && y != v2.y && z != v2.z;
    }
    // Сумма двух векторов, исходные вектора не меняются, возвращается новый вектор
    Vector3D operator+ (const Vector3D& v2) const {
        Vector3D vec;
        vec.x = x + v2.x;
        vec.y = y + v2.y;
        vec.z = z + v2.z;
        return vec;
    }

    // Вычитание векторов, исходные вектора не меняются, возвращается новый вектор
    Vector3D operator- (const Vector3D& v2) const {
        Vector3D vec;
        vec.x = x - v2.x;
        vec.y = y - v2.y;
        vec.z = z - v2.z;
        return vec;
    }

    // Оператор умножения вектора на скаляр, исходный вектор не меняется, возвращается новый вектор
    Vector3D operator* (const double a) const {
        Vector3D vec;
        vec.x = x * (double)a;
        vec.y = y * (double)a;
        vec.z = z * (double)a;
        return vec;
    }

    double operator* (const Vector3D& v) const {
        double s;
        s = x*v.x + y*v.y + z*v.z;
        return s;
    }
    friend Vector3D operator *( double d, const Vector3D &v );
};
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

///////////////////////////////////////////////////////////////////////////////////////

class Matrix3D {
private:
    double a11, a12, a13;
    double a21, a22, a23;
    double a31, a32, a33;
public:
    Matrix3D() : Matrix3D(0,0,0,0,0,0,0,0,0) {}
    Matrix3D(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32, double a33) {
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

    double det(){
        return a11*(a22*a33-a32*a23) - a12*(a21*a33 - a23*a31) + a13*(a21*a32 - a22*a31);
    }
    friend ostream& operator<<(ostream& os, const Matrix3D& m);
    friend istream& operator>>(istream& is, Matrix3D& m);

    Matrix3D operator* (const double a) const {
        Matrix3D m;
        m.a11 = a11*a; m.a12 = a12*a; m.a13 = a13*a;
        m.a21 = a21*a; m.a22 = a22*a; m.a23 = a23*a;
        m.a31 = a31*a; m.a32 = a32*a; m.a33 = a33*a;
        return m;
    }
    friend Matrix3D operator *( double d, const Matrix3D& v );

    Matrix3D operator* (const Matrix3D& m) {
        Matrix3D mat;
        mat.a11 = a11*m.a11 + a12*m.a21 + a13*m.a31;
        mat.a12 = a11*m.a12 + a12*m.a22 + a13*m.a32;
        mat.a13 = a11*m.a13 + a12*m.a23 + a13*m.a33;
        mat.a21 = a21*m.a11 + a22*m.a21 + a23*m.a31;
        mat.a22 = a21*m.a12 + a22*m.a22 + a23*m.a32;
        mat.a21 = a21*m.a13 + a22*m.a23 + a23*m.a33;
        mat.a31 = a31*m.a11 + a32*m.a21 + a33*m.a31;
        mat.a32 = a31*m.a12 + a32*m.a22 + a33*m.a32;
        mat.a33 = a31*m.a13 + a32*m.a23 + a33*m.a33;
        return mat;
    }
    Vector3D operator*(const Vector3D& v) {
        Vector3D vec;
        vec.setX( a11*v.getX() + a12*v.getY() + a13*v.getZ() );
        vec.setY( a21*v.getX() + a22*v.getY() + a23*v.getZ() );
        vec.setZ( a31*v.getX() + a32*v.getY() + a33*v.getZ() );
        return vec;
    }
    Matrix3D operator+(const Matrix3D& m) {
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
    Matrix3D operator-(const Matrix3D& m) {
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

};
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
int main()
{
    // Вектор задан в коде
    Vector3D A(1, 2, 3);
    // Вектор читается из cin
    Vector3D B;
    cin >> B;

    // Базовые операции с векторами
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "A * 3 = " << A * 3 << endl;
    cout << "2 * B = " << 2 * B << endl;
    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << endl;

    // Матрица задана в коде
    Matrix3D C(1, 0, 0, 0, 1, 0, 0, 0, 1);
    // Матрица читается из cin
    Matrix3D D;
    cin >> D;

    // Базовые операции с матрицами
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;
    cout << "C * 3 = " << C * 3 << endl;
    cout << "2 * D = " << 2 * D << endl;
    cout << "C + D = " << C + D << endl;
    cout << "C - D = " << C - D << endl;
    cout << "C * D = " << C * D << endl;

    // Детерминант матрицы
    cout << "det(D) = " << D.det() << endl;

    // Умножение матрицы на вектор
    cout << "D * B = " << D * B << endl;

    return 0;
}