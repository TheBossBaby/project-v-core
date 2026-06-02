#pragma once

#include <cstdint>

namespace projectv::core
{
    /**
     * @brief Configuration parameters for a raytracer instance.
     */
    struct RaytracerConfig
    {
        /**
         * @brief Initial render target width in pixels.
         */
        std::uint32_t width = 1280;

        /**
         * @brief Initial render target height in pixels.
         */
        std::uint32_t height = 720;

        /**
         * @brief Maximum number of ray bounces per path.
         */
        std::uint32_t maxBounces = 4;
    };

    /**
     * @brief Defines the interface for a raytracing renderer.
     *
     * Implementations are responsible for initializing rendering resources,
     * rendering frames, handling resize events, and synchronizing GPU work.
     */
    class IRaytracer
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IRaytracer() = default;

        /**
         * @brief Initializes the raytracer.
         *
         * @param config Configuration parameters used to initialize the renderer.
         * @return true if initialization succeeded; otherwise false.
         */
        virtual bool init(const RaytracerConfig& config) = 0;

        /**
         * @brief Resizes the render target.
         *
         * @param width New render target width in pixels.
         * @param height New render target height in pixels.
         */
        virtual void resize(std::uint32_t width, std::uint32_t height) = 0;

        /**
         * @brief Renders a frame.
         */
        virtual void render() = 0;

        /**
         * @brief Waits for all pending rendering work to complete.
         *
         * Implementations should block until the renderer is idle.
         */
        virtual void waitIdle() = 0;
    };
}