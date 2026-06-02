#pragma once

#include <cstdint>
#include <string_view>

namespace projectv::core
{
    /**
     * @brief Shader stages supported by the rendering backend.
     */
    enum class ShaderStage : std::uint32_t
    {
        /**
         * @brief Vertex shader stage.
         */
        Vertex = 1 << 0,

        /**
         * @brief Fragment shader stage.
         */
        Fragment = 1 << 1,
    };

    /**
     * @brief Unique identifier for a shader resource.
     */
    using ShaderId = std::uint32_t;

    /**
     * @brief Describes the source files used to create a shader.
     */
    struct ShaderSourceDesc
    {
        /**
         * @brief Path to the vertex shader source file.
         */
        std::string_view vertexPath;

        /**
         * @brief Path to the fragment shader source file.
         */
        std::string_view fragmentPath;
    };

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
         * @brief Source files used to create the shader.
         */
        ShaderSourceDesc sourceDesc{};

        /**
         * @brief Shader stages associated with this shader.
         */
        ShaderStage stages = ShaderStage::Vertex | ShaderStage::Fragment;
    };
}