#pragma once

#include <core/math/math.hpp>

namespace projectv::core
{
    struct RenderView {
        math::Matrix4 view;
        math::Matrix4 proj;
        math::Matrix4 viewProj;
        math::Vector3 cameraPosition;
        int  viewportWidth;
        int  viewportHeight;
        math::Vector4 clearColor;
    };
}