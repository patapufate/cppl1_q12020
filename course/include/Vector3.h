#pragma once
#include <iostream>
#include "math.h"

namespace ekumen
{

class Vector3
{
public:
    explicit Vector3();
    explicit Vector3(const double x, const double y, const double z);

    double x() const {return values[0];}
    double &x() {return values[0];}
    
    double y() const { return values[1]; }
    double &y() {return values[1];}

    double z() const { return values[2]; }
    double &z() {return values[2];}



    double norm() const;
    double dot(const Vector3 &q) const;
    Vector3 cross(const Vector3 &q) const;
    //operator overload
    const double& operator[](const int index) const;
    double& operator[](const int index);    
    
    friend Vector3 operator+(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator-(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator*(const double &cte, const Vector3 &p);
    friend Vector3 operator*(const Vector3 &p, const double &cte);
    friend Vector3 operator*(const Vector3 &p, const Vector3 &q);
    friend Vector3 operator/(const Vector3 &p, const Vector3 &q);
    friend bool operator==(const Vector3 &p, const Vector3 &q);
    friend bool operator!=(const Vector3 &p, const Vector3 &q);
   
    friend std::ostream &operator<<(std::ostream &os, const Vector3 &p);
         

    static const Vector3 kUnitX;
    static const Vector3 kUnitY;
    static const Vector3 kUnitZ;
    static const Vector3 kZero;

private:

    double *values = new double[3];

};

} // namespace ekumen
