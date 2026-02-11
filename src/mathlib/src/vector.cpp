#include "../include/Vector.h"
#include <windows.h>

Vector3::Vector3() {
    x, y, z = 0.0f;
}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
Vector3::~Vector3() {}

double Vector3::dot(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

double Vector3::magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3::lengthSquared() const {
    return x*x + y*y + z*z;
}