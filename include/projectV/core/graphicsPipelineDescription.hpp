#pragma once

#include "projectV/core/shaderHandle.hpp"

namespace projectv::core
{
    /**
     * @brief Describes a graphics pipeline in terms of shader assets.
     *
     * Shaders are referenced by ShaderHandle rather than raw shader data.
     * The renderer resolves these handles through the engine's shader
     * resource system when creating the backend graphics pipeline.
     *
     * Only the shader stages are described here; fixed-function pipeline
     * state (rasterization, blending, multisampling, ...) is left to the
     * backend's own sensible defaults for now.
     */
    struct GraphicsPipelineDescription
    {
        /**
         * @brief Handle of the vertex shader to use, as returned by ShaderManager::load().
         */
        ShaderHandle vertexShader;

        /**
         * @brief Handle of the fragment shader to use, as returned by ShaderManager::load().
         */
        ShaderHandle fragmentShader;
    };
}
