#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

namespace projectv::core
{
    /**
     * @brief Shader stages supported by the rendering backend.
     */
    enum class ShaderStage : std::uint32_t
    {
        None        = 0,
        Vertex      = 1u << 0,
        Fragment    = 1u << 1,
        Geometry    = 1u << 2,
        TessControl = 1u << 3,
        TessEval    = 1u << 4,
        Compute     = 1u << 5
    };

    /**
     * @brief Unique identifier for a shader resource.
     */
    using ShaderId = std::uint32_t;

    /**
     * @brief Represents a shader resource.
     */
    struct Shader
    {
        /**
         * @brief Unique identifier of the shader.
         */
        ShaderId id = 0;

        /**
         * @brief Path of the source asset on disk, for debugging/logging.
         */
        std::string_view path;

        /**
         * @brief Optional debug name used in logs and tools.
         */
        std::string_view debugName;

        /**
         * @brief Shader stages associated with this shader.
         */
        ShaderStage stage = ShaderStage::None;

        /**
         * @brief Raw shader data.
         */
        std::vector<std::uint8_t> data;
    };
}