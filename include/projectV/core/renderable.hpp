#pragma once

#include <projectV/core/math/math.hpp>
#include <projectV/core/meshHandle.hpp>
#include <projectV/core/graphicsPipelineHandle.hpp>

namespace projectv::core
{
    /**
     * @brief A single item to be drawn by IRenderer::draw().
     */
    struct Renderable {
        /**
         * @brief Mesh to draw.
         */
        MeshHandle             mesh;

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