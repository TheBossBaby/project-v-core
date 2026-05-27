#pragma once

#include <cstdint>
#include <vector>

namespace projectv::core
{
    // Unreal-like coordinate system:
    // X forward, Y right, Z up; units in centimeters (you can document this in comments).
    struct Vertex
    {
        float position[3]; // X, Y, Z
        float normal[3];   // NX, NY, NZ
        float color[4];    // RGBA, 0..1
        float uv[2];       // U, V
    };

    struct Mesh
    {
        // Simple CPU-side representation:
        std::vector<Vertex>   vertices;
        std::vector<std::uint32_t> indices;
    };
}