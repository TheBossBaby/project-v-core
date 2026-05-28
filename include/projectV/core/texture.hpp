#pragma once

#include <cstdint>

namespace projectv::core
{
    enum class TextureFormat
    {
        Unknown = 0,
        R8G8B8A8_UNorm,
        R16G16B16A16_Float,
        D24S8,
        MAX
    };

    enum class TextureUsage : std::uint32_t
    {
        None       = 0,
        Sampled    = 1 << 0,
        RenderTarget = 1 << 1,
        DepthStencil = 1 << 2
    };

    using TextureId = std::uint32_t;

    struct TextureDesc
    {
        std::uint32_t width  = 0;
        std::uint32_t height = 0;
        TextureFormat format = TextureFormat::Unknown;
        TextureUsage  usage  = TextureUsage::Sampled;
    };
    
    struct Texture
    {
        TextureId    id      = 0;    // For bindless: index into a descriptor array later.
        TextureDesc  desc    {};
    };
}