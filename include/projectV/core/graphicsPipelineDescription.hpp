#pragma once

#include <span>
#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Describes a graphics pipeline in terms of its shader bytecode.
     *
     * Shader code is passed as non-owning byte spans. The bytes are only
     * borrowed for the duration of the IRenderer::createGraphicsPipeline()
     * call; the caller remains the owner and may release the memory once
     * that call returns. Implementations must not retain the spans.
     *
     * Only the shader stages are described here; fixed-function pipeline
     * state (rasterization, blending, multisampling, ...) is left to the
     * backend's own sensible defaults for now.
     */
    struct GraphicsPipelineDescription
    {
        /**
         * @brief Vertex shader bytecode in the format expected by the backend.
         *
         * Borrowed only during createGraphicsPipeline(); owned by the caller.
         */
        std::span<const std::uint8_t> vertexShaderCode;

        /**
         * @brief Fragment shader bytecode in the format expected by the backend.
         *
         * Borrowed only during createGraphicsPipeline(); owned by the caller.
         */
        std::span<const std::uint8_t> fragmentShaderCode;
    };
}
