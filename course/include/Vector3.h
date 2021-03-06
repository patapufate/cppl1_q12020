#pragma once
#include <iostream>
#include <cmath>
#include <memory>
#include <utility>

namespace ekumen
{

    class Vector3
    {
    public:
        Vector3();
        explicit Vector3(const double x, const double y, const double z);
        Vector3(const std::initializer_list<double> &list);
        Vector3(const Vector3 &p2);     //copy constructor
        Vector3(Vector3&& other);       //move constructor
        ~Vector3();
        
        const double &x() const { return values[0]; }
        double &x() { return values[0]; }

        const double &y() const { return values[1]; }
        double &y() { return values[1]; }

        const double &z() const { return values[2]; }
        double &z() { return values[2]; }

        double norm() const;
        double dot(const Vector3 &q) const;
        Vector3 cross(const Vector3 &q) const;
        //operator overload
        const double &operator[](const int index) const;
        double &operator[](const int index);

        Vector3 &operator+=(const Vector3 &q);
        Vector3 &operator-=(const Vector3 &q);
        Vector3 &operator=(const Vector3 &r);   // copy assignment
        Vector3 &operator=(Vector3 &&other);    //move assignment

        friend Vector3 operator*(const double &cte, const Vector3 &p);
        friend Vector3 operator*(const Vector3 &p, const double &cte);
        friend Vector3 operator*(const Vector3 &p, const Vector3 &q);
        friend Vector3 operator/(const Vector3 &p, const Vector3 &q);

        friend bool operator==(const Vector3 &p, const Vector3 &q);
        friend bool operator==(const Vector3 &p, const std::initializer_list<double> &list);
        friend bool operator==(const std::initializer_list<double> &list, const Vector3 &p);

        friend bool operator!=(const Vector3 &p, const Vector3 &q);
        friend bool operator!=(const Vector3 &p, const std::initializer_list<double> &list);
        friend bool operator!=(const std::initializer_list<double> &list, const Vector3 &p);

        friend std::ostream &operator<<(std::ostream &os, const Vector3 &p);

        static const Vector3 kUnitX;
        static const Vector3 kUnitY;
        static const Vector3 kUnitZ;
        static const Vector3 kZero;
        static const Vector3 kOnes;

    private:        
        double *values;
        

    };

    Vector3 operator+(const Vector3 &p, const Vector3 &q);
    Vector3 operator-(const Vector3 &p, const Vector3 &q);

} // namespace ekumen
