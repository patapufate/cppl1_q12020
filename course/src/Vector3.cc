#include "Vector3.h"

namespace ekumen
{

Vector3::Vector3(const double x, const double y, const double z)
{
    values[0] = x;
    values[1] = y;
    values[2] = z;
}
Vector3::Vector3()
{
    values[0] = 0.;
    values[1] = 0.;
    values[2] = 0.;
}
Vector3::Vector3(const std::initializer_list<double> &list)
{
    int i = 0;
    for (const auto &v : list)
    {
        values[i] = v;
        i++;
    }
}

Vector3::Vector3(const Vector3 &p2)
{
    x() = p2.x();
    y() = p2.y();
    z() = p2.z();
}

Vector3::~Vector3() {}

double Vector3::norm() const
{
    return sqrt(dot(*this));
}

double Vector3::dot(const Vector3 &q) const
{
    return ((x() * q.x()) + (y() * q.y()) + (z() * q.z()));
}

Vector3 Vector3::cross(const Vector3 &q) const
{
    Vector3 r;
    r.x() = y() * q.z() - z() * q.y();
    r.y() = z() * q.x() - x() * q.z();
    r.z() = x() * q.y() - y() * q.x();
    return r;
}

Vector3 &Vector3::operator+=(const Vector3 &q)
{
    x() += q.x();
    y() += q.y();
    z() += q.z();
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &q)
{
    x() -= q.x();
    y() -= q.y();
    z() -= q.z();
    return *this;
}

Vector3 operator+(const Vector3 &p, const Vector3 &q)
{
    Vector3 r(p.x(), p.y(), p.z());
    return (r += q);
}

Vector3 operator-(const Vector3 &p, const Vector3 &q)
{
    Vector3 r(p.x(), p.y(), p.z());
    return (r -= q);
}

Vector3 operator*(const double &cte, const Vector3 &p)
{
    Vector3 res(cte * p.x(), cte * p.y(), cte * p.z());
    return res;
}

Vector3 operator*(const Vector3 &p, const double &cte)
{
    Vector3 res(cte * p.x(), cte * p.y(), cte * p.z());
    return res;
}

Vector3 operator*(const Vector3 &p, const Vector3 &q)
{
    Vector3 res(p.x() * q.x(), p.y() * q.y(), p.z() * q.z());
    return res;
}

Vector3 operator/(const Vector3 &p, const Vector3 &q)
{
    Vector3 res(p.x() / q.x(), p.y() / q.y(), p.z() / q.z());
    return res;
}

bool operator==(const Vector3 &p, const Vector3 &q)
{
    bool res = (p.x() == q.x()) && (p.y() == q.y()) && (p.z() == q.z());
    return res;
}

bool operator==(const Vector3 &p, const std::initializer_list<double> &list)
{
    Vector3 q(list);
    return (p == q); //res;
}

bool operator!=(const Vector3 &p, const Vector3 &q)
{

    return (!(p == q));
}

bool operator!=(const Vector3 &p, const std::initializer_list<double> &list)
{
    Vector3 q = Vector3(list);
    return (!(p == q));
}

std::ostream &operator<<(std::ostream &os, const Vector3 &p)
{
    os << "(x: " << p.x() << ", y: " << p.y() << ", z: " << p.z() << ")";
    return os;
}

const double &Vector3::operator[](const int index) const
{
    try
    {
        return values[index];
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
}

double &Vector3::operator[](const int index)
{
    try
    {
        return values[index];
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error occurred: " << ex.what() << std::endl;
    }
}

const Vector3 Vector3::kUnitX = Vector3(1., 0., 0.);
const Vector3 Vector3::kUnitY = Vector3(0., 1., 0.);
const Vector3 Vector3::kUnitZ = Vector3(0., 0., 1.);
const Vector3 Vector3::kZero = Vector3(0., 0., 0.);
const Vector3 Vector3::kOnes = Vector3(1., 1., 1.);

} // namespace ekumen
