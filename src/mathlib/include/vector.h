#pragma once

class Vector3
{
public:
    Vector3();
    Vector3(double x, double y, double z);
    ~Vector3();

    // dot product
    double dot(const Vector3 &other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
private:
    double x, y, z;
};