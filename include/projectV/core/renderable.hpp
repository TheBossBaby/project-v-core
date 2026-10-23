#pragma once

#include <projectV/core/math/math.hpp>
#include <projectV/core/gpu/gpuMeshHandle.hpp>
#include <projectV/core/graphicsPipelineHandle.hpp>

namespace projectv::core
{
    /**
     * @brief A single item to be drawn by IRenderer::draw().
     */
    struct Renderable {
        /**
         * @brief GPU Mesh to draw.
         */
        gpu::GpuMeshHandle gpuMesh;

        /**
         * @brief Pipeline to draw with, as returned by IRenderer::createGraphicsPipeline().
         */
        GraphicsPipelineHandle graphicsPipelineHandle;

        /**
         * @brief Object-to-world transform.
         */
        math::Matrix4          modelMatrix;
    };
}