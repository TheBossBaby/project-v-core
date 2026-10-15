#pragma once

#include <cstdint>
#include <vector>

#include <projectV/core/math/math.hpp>
namespace projectv::core
{
    /**
     * @brief Represents a single mesh vertex.
     *
     * The engine uses an Unreal-style coordinate system:
     * - X axis points forward
     * - Y axis points right
     * - Z axis points up
     *
     * World-space units are expressed in centimeters.
     */
    struct Vertex
    {
        /**
         * @brief Vertex color.
         *
         * Components are ordered as R, G, B, A and are
         * expected to be in the range [0.0, 1.0].
         */
        alignas(16) math::Vector4 color;
        
        /**
         * @brief Vertex position.
         *
         * Components are ordered as X, Y, Z.
         */
        alignas(4) math::Vector3 position;

        /**
         * @brief Vertex normal.
         *
         * Components are ordered as X, Y, Z.
         */
        alignas(4) math::Vector3 normal;

        /**
         * @brief Texture coordinates.
         *
         * Components are ordered as U, V.
         */
        alignas(8) math::Vector2 uv;
    };

    static_assert(sizeof(Vertex) == 48, "Vertex layout mismatch detected!");

    /**
     * @brief CPU-side mesh representation.
     *
     * Stores vertex and index data that can be consumed by a
     * rendering backend.
     */
    struct Mesh
    {
        /**
         * @brief Collection of mesh vertices.
         */
        std::vector<Vertex> vertices;

        /**
         * @brief Index buffer defining mesh primitives.
         */
        std::vector<std::uint32_t> indices;
    };
}