#pragma once

#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Lightweight handle used to reference a mesh managed by the engine.
     *
     * A MeshHandle does not own mesh data. It simply stores an index into the
     * engine's mesh storage/registry and can be passed around safely without
     * exposing internal mesh implementation details.
     *
     * A handle is considered invalid when its index is equal to InvalidIndex.
     * Use isValid() to verify that the handle refers to a valid mesh entry
     * before accessing the underlying resource.
     */
    struct MeshHandle
    {
        static constexpr uint32_t InvalidIndex = UINT32_MAX;

        uint32_t index = InvalidIndex;

        [[nodiscard]] bool isValid() const { return index != InvalidIndex; }
    };
}