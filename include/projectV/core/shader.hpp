#pragma once

#include <cstdint>
#include <string_view>

namespace projectv::core
{
    enum class ShaderStage : std::uint32_t
    {
        Vertex   = 1 << 0,
        Fragment = 1 << 1,
    };

    using ShaderId = std::uint32_t;

    struct ShaderSourceDesc
    {
        std::string_view vertexPath;
        std::string_view fragmentPath;
    };

    struct Shader
    {
        ShaderId        id = 0;          // Can also be used as an index into bindless-like structures.
        ShaderSourceDesc sourceDesc      {};
        ShaderStage     stages = ShaderStage::Vertex | ShaderStage::Fragment;
    };
}