// shaderHandle.hpp
#pragma once

#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Lightweight handle used to reference a shader or material.
     *
     * A ShaderHandle does not own GPU resources. It stores an index into
     * the engine's shader storage/registry and can be passed around safely
     * without exposing internal implementation details.
     *
     * A handle is considered invalid when its index is equal to InvalidIndex.
     * Use isValid() to verify that the handle refers to a valid entry before
     * accessing the underlying resource.
     */
    struct ShaderHandle
    {
        static constexpr std::uint32_t InvalidIndex = UINT32_MAX;

        std::uint32_t index{InvalidIndex};

        /// @brief Check whether this handle refers to a valid shader.
        [[nodiscard]] bool isValid() const { return index != InvalidIndex; }
    };
}