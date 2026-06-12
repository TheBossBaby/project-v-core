#pragma once

#include "projectv/core/shader.hpp"

#include <optional>
#include <string>

namespace projectv::core
{
    /**
     * @brief Parameters used when loading a shader.
     */
    struct ShaderLoadParams
    {
        /**
         * @brief Path of the source asset on disk, for debugging/logging.
         */
        std::string path;

        /**
         * @brief Shader stages associated with this shader.
         */
        ShaderStage stage;

        /**
         * @brief Optional debug name used in logs and tools.
         */
        std::string debugName = {};

        /**
         * @brief Indicates whether debug information should be generated.
         */
        bool bDebug = false;
    };

    /**
     * @brief Defines the interface for loading shader resources.
     *
     * Implementations are responsible for loading, compiling, and creating
     * shader resources from the provided source files.
     */
    class IShaderLoader
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IShaderLoader() = default;

        /**
         * @brief Loads a shader using the specified parameters.
         *
         * @param params Shader loading parameters.
         * @return The loaded shader on success; otherwise std::nullopt.
         */
        virtual std::optional<Shader> loadShader(const ShaderLoadParams& params) = 0;
    };
}