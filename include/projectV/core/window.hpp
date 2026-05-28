#pragma once

#include <cstdint>
#include <string_view>

namespace projectv::core
{
    struct WindowDesc
    {
        std::uint32_t width  = 0;
        std::uint32_t height = 0;
        std::string_view windowName;
    };
    
    class IWindow
    {
    public:
        virtual ~IWindow() = default;
        
        virtual bool init(const WindowDesc& desc) = 0;

        virtual void shutdown() = 0;

        virtual void resize(uint32_t width, uint32_t height) = 0;

        virtual void pollEvents() = 0;

        virtual uint32_t getWidth() const = 0;

        virtual uint32_t getHeight() const = 0;
    };
}