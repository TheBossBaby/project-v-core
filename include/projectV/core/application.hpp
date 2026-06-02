#pragma once

#include <cstdint>

#include "projectV/core/window.hpp"

namespace projectv::core
{
    /**
     * @brief Defines the lifecycle of an application.
     *
     * Implementations are responsible for initializing engine subsystems,
     * executing the main loop, and releasing resources during shutdown.
     */
    class IApplication
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IApplication() = default;

        /**
         * @brief Initializes the application.
         *
         * Called once during startup to create the main window,
         * initialize subsystems, and load required resources.
         *
         * @param windowDesc Description of the window to create.
         * @return true if initialization succeeded; otherwise false.
         */
        virtual bool init(const WindowDesc& windowDesc) = 0;

        /**
         * @brief Executes the application's main loop.
         *
         * Implementations typically process events, update application
         * state, and render frames until the application exits.
         */
        virtual void run() = 0;

        /**
         * @brief Shuts down the application.
         *
         * Called once before application termination to release resources
         * and shut down subsystems.
         */
        virtual void shutdown() = 0;

    protected:
        /**
         * @brief Updates application state for a single frame.
         *
         * @param deltaTime Time elapsed since the previous frame, in seconds.
         */
        virtual void tick(float deltaTime) = 0;

        /**
         * @brief Renders a single frame.
         */
        virtual void render() = 0;
    };
}