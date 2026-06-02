#pragma once

#include <cstdint>
#include <vector>

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
         * @brief Vertex position.
         *
         * Components are ordered as X, Y, Z.
         */
        float position[3];

        /**
         * @brief Vertex normal.
         *
         * Components are ordered as X, Y, Z.
         */
        float normal[3];

        /**
         * @brief Vertex color.
         *
         * Components are ordered as R, G, B, A and are
         * expected to be in the range [0.0, 1.0].
         */
        float color[4];

        /**
         * @brief Texture coordinates.
         *
         * Components are ordered as U, V.
         */
        float uv[2];
    };

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