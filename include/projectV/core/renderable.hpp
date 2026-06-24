#pragma once

#include <core/math/math.hpp>
#include <core/meshHandle.hpp>

namespace projectv::core
{
    struct Renderable {
        MeshHandle    mesh;       
        math::Matrix4 modelMatrix;
    };
}