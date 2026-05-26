#pragma once

#include <cstdint>
#include <string_view>

namespace projectv::core
{
    struct RendererConfig
    {
        std::uint32_t width  = 1280;
        std::uint32_t height = 720;
        bool          bIsVsync  = true;
        std::string_view applicationName = "project-v";
    };

    class IRenderer
    {
    public:
        virtual ~IRenderer() = default;
        
        virtual bool init(const RendererConfig& config) = 0;

        virtual void resize(std::uint32_t width, std::uint32_t height) = 0;

        virtual void beginFrame() = 0;

        virtual void endFrame() = 0;

        virtual void waitIdle() = 0;
    };
}