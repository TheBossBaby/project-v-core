#pragma once

#include <cstdint>

namespace projectv::core::gpu
{
    /**
     * @brief Opaque handle to a mesh that has been uploaded to the GPU.
     *
     * Returned by IRenderer::uploadMesh() and referenced by Renderable.
     * Default-constructed handles are invalid.
     */
    struct GpuMeshHandle
    {
        /**
         * @brief Index value that marks a handle as invalid.
         */
        static constexpr uint32_t InvalidIndex = UINT32_MAX;

        /**
         * @brief Backend-defined index of the uploaded mesh.
         */
        uint32_t index = InvalidIndex;

        /**
         * @brief Checks whether this handle refers to an uploaded mesh.
         *
         * Only checks that the handle is not the invalid sentinel; it does
         * not verify that the renderer still holds the mesh.
         *
         * @return true if the handle is valid; otherwise false.
         */
        [[nodiscard]] bool isValid() const { return index != InvalidIndex; }
    };
}