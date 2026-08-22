#pragma once

#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Lightweight handle used to reference a renderer-owned graphics pipeline.
     *
     * A GraphicsPipelineHandle does not own any GPU resources. It stores an
     * index into the rendering backend's own pipeline storage/registry (for
     * example RendererResources on the Vulkan backend) and can be passed
     * around safely without exposing backend-specific pipeline types.
     *
     * A handle is considered invalid when its index is equal to InvalidIndex.
     * Use isValid() to verify that the handle refers to a valid entry before
     * using it to draw.
     */
    struct GraphicsPipelineHandle
    {
        static constexpr std::uint32_t InvalidIndex = UINT32_MAX;

        std::uint32_t index{InvalidIndex};

        /// @brief Check whether this handle refers to a valid graphics pipeline.
        [[nodiscard]] bool isValid() const { return index != InvalidIndex; }
    };
}
