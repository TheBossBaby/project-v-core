#pragma once

#include <string_view>
#include <optional>

#include "projectV/core/texture.hpp"

namespace projectv::core
{
    /**
     * @brief Parameters used when loading a texture.
     */
    struct TextureLoadParams
    {
        /**
         * @brief Path to the texture asset.
         */
        std::string_view path;

        /**
         * @brief Indicates whether the texture should be vertically flipped during loading.
         */
        bool bFlipVertical = false;

        /**
         * @brief Indicates whether mipmaps should be generated for the texture.
         */
        bool bGenerateMipmaps = true;
    };

    /**
     * @brief Defines the interface for loading texture resources.
     *
     * Implementations are responsible for reading texture data,
     * creating texture resources, and populating texture metadata.
     */
    class ITextureLoader
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~ITextureLoader() = default;

        /**
         * @brief Loads a texture using the specified parameters.
         *
         * @param params Texture loading parameters.
         * @return The loaded texture on success; otherwise std::nullopt.
         */
        virtual std::optional<Texture> loadTexture(const TextureLoadParams& params) = 0;
    };
}