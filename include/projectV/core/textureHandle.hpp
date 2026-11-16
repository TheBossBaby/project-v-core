#pragma once

#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Lightweight handle used to reference a texture managed by the engine.
     *
     * A TextureHandle does not own texture data. It stores an index into the
     * engine's texture storage/registry and can be passed around safely without
     * exposing internal texture implementation details.
     *
     * A handle is considered invalid when its index is equal to InvalidIndex.
     * Use isValid() to verify that the handle refers to a valid texture entry
     * before accessing the underlying resource.
     */
    struct TextureHandle
    {
        static constexpr std::uint32_t InvalidIndex = UINT32_MAX;

        std::uint32_t index = InvalidIndex;

        /// @brief Check whether this handle refers to a valid texture.
        [[nodiscard]] bool isValid() const { return index != InvalidIndex; }
    };
}
