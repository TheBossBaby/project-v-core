#pragma once

#include <cstdint>

namespace projectv::core
{
    struct RaytracerConfig
    {
        std::uint32_t width  = 1280;
        std::uint32_t height = 720;
        std::uint32_t maxBounces = 4;
    };

    class IRaytracer
    {
    public:
        virtual ~IRaytracer() = default;

        virtual bool init(const RaytracerConfig& config) = 0;
        
        virtual void resize(std::uint32_t width, std::uint32_t height) = 0;
        
        virtual void render() = 0;

        virtual void waitIdle() = 0;
    };
}