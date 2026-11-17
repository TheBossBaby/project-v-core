#pragma once

#include <cstdint>

namespace projectv::core::gpu
{
    struct GpuTextureHandle
    {
        static constexpr uint32_t InvalidIndex = UINT32_MAX;

        uint32_t index = InvalidIndex;

        [[nodiscard]] bool isValid() const { return index != InvalidIndex; }
    };
}