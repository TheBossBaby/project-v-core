#pragma once

#include <optional>

#include "projectv/core/shader.hpp"

namespace projectv::core
{
    struct ShaderLoadParams
    {
        ShaderSourceDesc source;
        bool             bDebug = false;     // e.g., compile with debug info.
    };

    class IShaderLoader
    {
    public:
        virtual ~IShaderLoader() = default;

        virtual std::optional<Shader> loadShader(const ShaderLoadParams& params) = 0;
    };
}