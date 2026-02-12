#pragma once
#include <memory>

class RayTracer {
public:
    RayTracer();
    RayTracer(int width, int height);
    ~RayTracer();

    void TraceRay();

    void render();

    unsigned char* framebuffer;
    int width, height;
};