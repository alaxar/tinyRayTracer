#pragma once
#include <cmath>

class Vector3
{
public:
    Vector3();
    Vector3(double x, double y, double z);
    ~Vector3();

    // dot product
    double dot(const Vector3 &other) const;

    double magnitude() const;
    double lengthSquared() const;
    
private:
    double x, y, z;
};