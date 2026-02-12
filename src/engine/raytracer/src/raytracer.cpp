#include <windows.h>
#include <raytracer.h>
#include <memory>

RayTracer::RayTracer(int width, int height) : width(width), height(height) {
    framebuffer = new unsigned char[width * height * 4];
}

RayTracer::RayTracer()
{
    width = 800;
    height = 800;

    framebuffer = new unsigned char[width * height * 4];
}

RayTracer::~RayTracer()
{
    delete[] framebuffer;
}

void RayTracer::render() {
}