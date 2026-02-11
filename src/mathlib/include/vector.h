#pragma once
#include <cmath>

class Vector3
{
public:
    Vector3();
    Vector3(double x, double y, double z);
    ~Vector3();


    double magnitude() const;
    double lengthSquared() const;
    Vector3 normalize() const;

    // Vector operations
    double dot(const Vector3 &other) const;
    Vector3 cross(const Vector3& other) const;
    Vector3 operator*(const Vector3 &other) const;
    Vector3 operator*(double scalar) const;
    Vector3 operator-(const Vector3 &other) const;
    Vector3 operator+(const Vector3 &other) const;
    
private:
    double x, y, z;
};