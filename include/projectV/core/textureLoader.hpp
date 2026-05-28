#pragma once

#include <string_view>
#include <optional>

#include "projectV/core/texture.hpp"

namespace projectv::core
{
    struct TextureLoadParams
    {
        std::string_view path;
        bool             bFlipVertical = false;
        bool             bGenerateMipmaps = true;
    };

    class ITextureLoader
    {
    public:
        virtual ~ITextureLoader() = default;

        // Returns a Texture with a valid TextureId and description, or std::nullopt on failure.
        virtual std::optional<Texture> loadTexture(const TextureLoadParams& params) = 0;
    };
}