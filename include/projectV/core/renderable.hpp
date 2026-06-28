#pragma once

#include <projectV/core/math/math.hpp>
#include <projectV/core/meshHandle.hpp>

namespace projectv::core
{
    struct Renderable {
        MeshHandle    mesh;       
        math::Matrix4 modelMatrix;
    };
}