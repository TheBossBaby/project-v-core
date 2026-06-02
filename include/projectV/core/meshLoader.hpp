#pragma once

#include "projectV/core/mesh.hpp"

#include <optional>
#include <string_view>

namespace projectv::core
{
    /**
     * @brief Parameters used when loading a mesh.
     */
    struct MeshLoadParams
    {
        /**
         * @brief Path to the mesh asset.
         */
        std::string_view path;

        /**
         * @brief Indicates whether texture coordinates should be vertically flipped.
         */
        bool bFlipUVs = false;

        /**
         * @brief Indicates whether the mesh should be centered about its origin.
         */
        bool bCenterMesh = false;

        /**
         * @brief Indicates whether the mesh should be uniformly scaled to a normalized size.
         */
        bool bNormalizeScale = false;
    };

    /**
     * @brief Defines the interface for loading mesh assets.
     *
     * Implementations may load meshes from files, archives,
     * memory buffers, or other data sources.
     */
    class IMeshLoader
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IMeshLoader() = default;

        /**
         * @brief Loads a mesh using the specified parameters.
         *
         * @param params Mesh loading parameters.
         * @return The loaded mesh on success; otherwise std::nullopt.
         */
        virtual std::optional<Mesh> loadMesh(const MeshLoadParams& params) = 0;
    };
}