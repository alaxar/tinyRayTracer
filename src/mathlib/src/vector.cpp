#include "../include/Vector.h"
#include <windows.h>

Vector3::Vector3() {
    x, y, z = 0.0f;
}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}
Vector3::~Vector3() {}