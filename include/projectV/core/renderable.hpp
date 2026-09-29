#pragma once

#include <projectV/core/math/math.hpp>
#include <projectV/core/meshHandle.hpp>
#include <projectV/core/shaderHandle.hpp>

namespace projectv::core
{
    struct Renderable {
        MeshHandle    mesh;
        ShaderHandle  vertexShader;
        ShaderHandle  fragmentShader;
        math::Matrix4 modelMatrix;
    };
}