#pragma once

#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Supported texture formats.
     */
    enum class TextureFormat
    {
        /**
         * @brief Invalid or unspecified texture format.
         */
        Unknown = 0,

        /**
         * @brief 8-bit unsigned normalized RGBA format.
         */
        R8G8B8A8_UNorm,

        /**
         * @brief 16-bit floating-point RGBA format.
         */
        R16G16B16A16_Float,

        /**
         * @brief 24-bit depth and 8-bit stencil format.
         */
        D24S8,

        /**
         * @brief Sentinel value representing the number of texture formats.
         */
        MAX
    };

    /**
     * @brief Intended usage of a texture resource.
     */
    enum class TextureUsage : std::uint32_t
    {
        /**
         * @brief No usage flags specified.
         */
        None = 0,

        /**
         * @brief Texture can be sampled by shaders.
         */
        Sampled = 1 << 0,

        /**
         * @brief Texture can be used as a render target.
         */
        RenderTarget = 1 << 1,

        /**
         * @brief Texture can be used as a depth-stencil target.
         */
        DepthStencil = 1 << 2
    };

    /**
     * @brief Unique identifier for a texture resource.
     */
    using TextureId = std::uint32_t;

    /**
     * @brief Describes a texture resource.
     */
    struct TextureDesc
    {
        /**
         * @brief Texture width in pixels.
         */
        std::uint32_t width = 0;

        /**
         * @brief Texture height in pixels.
         */
        std::uint32_t height = 0;

        /**
         * @brief Texture pixel format.
         */
        TextureFormat format = TextureFormat::Unknown;

        /**
         * @brief Intended usage of the texture.
         */
        TextureUsage usage = TextureUsage::Sampled;
    };

    /**
     * @brief Represents a texture resource.
     */
    struct Texture
    {
        /**
         * @brief Unique identifier of the texture.
         */
        TextureId id = 0;

        /**
         * @brief Texture description.
         */
        TextureDesc desc{};
    };
}