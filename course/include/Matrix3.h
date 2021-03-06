#pragma once
#include <iostream>
#include <cmath>
#include "Vector3.h"

namespace ekumen
{

    class Matrix3
    {
    public:
        Matrix3();
        explicit Matrix3(const Vector3 &f1, const Vector3 &f2, const Vector3 &f3);
        Matrix3(const std::initializer_list<double> &list);
        Matrix3(const std::initializer_list<double> &r1, const std::initializer_list<double> &r2, const std::initializer_list<double> &r3);
        Matrix3(const Matrix3 &m);
        Matrix3(Matrix3 &&m);

        double det() const;
        const Vector3 row(const int index) const;
        Vector3 &row(const int index);
        const Vector3 col(const int index) const;

        Matrix3 mul(const Matrix3 &m2) const;
        Matrix3 inverse() const;

        Matrix3 &operator+=(const Matrix3 &q);
        Matrix3 &operator-=(const Matrix3 &q);
        
        Matrix3 &operator=(const Matrix3 &other);   // copy assignment
        Matrix3 &operator=(Matrix3 &&other);    //move assignment

        //operator overload
        const Vector3 &operator[](const int &index) const;
        Vector3 &operator[](const int &index);

        friend bool operator==(const Matrix3 &p, const Matrix3 &q);
        friend bool operator==(const Matrix3 &p, const std::initializer_list<double> &list);
        friend bool operator==(const std::initializer_list<double> &list, const Matrix3 &p);

        friend Matrix3 operator*(const double &cte, const Matrix3 &p);
        friend Matrix3 operator*(const Matrix3 &p, const double &cte);
        friend Matrix3 operator*(const Matrix3 &p, const Matrix3 &q);
        friend Vector3 operator*(const Matrix3 &p, const Vector3 &v);

        friend Matrix3 operator/(const Matrix3 &p, const Matrix3 &q);
        friend Matrix3 operator/(const Matrix3 &p, const double &value);

        friend bool operator!=(const Matrix3 &p, const Matrix3 &q);
        friend bool operator!=(const Matrix3 &p, const std::initializer_list<double> &list);
        friend bool operator!=(const std::initializer_list<double> &list, const Matrix3 &p);

        friend std::ostream &operator<<(std::ostream &os, const Matrix3 &p);
        static const Matrix3 kIdentity;
        static const Matrix3 kZero;
        static const Matrix3 kOnes;

    private:
        Vector3 *row_values = new Vector3[3];
    };

    Matrix3 operator+(const Matrix3 &p, const Matrix3 &q);
    Matrix3 operator-(const Matrix3 &p, const Matrix3 &q);

} // namespace ekumen
