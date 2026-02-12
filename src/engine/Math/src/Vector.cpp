#include <Vector.h>
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

Vector3 Vector3::normalize() const {
    double len = lengthSquared();

    if(len == 0.0)
        return Vector3(0.0f, 0.0f, 0.0f);

    double invertedLength = 1.0 / std::sqrt(len);

    return Vector3(x * invertedLength, y * invertedLength, z * invertedLength);
}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator*(const Vector3& other) const {    // component wise (hadamard product)
    return Vector3(x * other.x, y * other.y, z * other.z);
}
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z * other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::cross(const Vector3& other) const {
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}