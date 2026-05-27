#pragma once

#include <string_view>
#include <optional>

#include "projectV/core/mesh.hpp"

namespace projectv::core
{
    struct MeshLoadParams
    {
        std::string_view path;
        bool             bFlipUVs = false;
        bool             bCenterMesh = false;
        bool             bNormalizeScale = false;
        // Later: coordinate-system conversion flags if needed.
    };

    class IMeshLoader
    {
    public:
        virtual ~IMeshLoader() = default;

        // Load a mesh from disk or another source.
        // Returns std::nullopt on failure.
        virtual std::optional<Mesh> loadMesh(const MeshLoadParams& params) = 0;
    };
}
