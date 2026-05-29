#pragma once

#include <cstdint>

#include "projectV/core/window.hpp"

namespace projectv::core
{
    class IApplication
    {
    public:
        virtual ~IApplication() = default;

        // Called once at startup: create window, initialize renderer, load core assets, etc.
        virtual bool init(const WindowDesc& windowDesc) = 0;

        // Main loop: typical structure inside implementation will be:
        // while (bIsRunning) { window.pollEvents(); tick(deltaTime); render(); }
        virtual void run() = 0;

        // Called once before exiting: free resources, shut down subsystems.
        virtual void shutdown() = 0;

    protected:
        // per-frame update logic (ECS, physics, gameplay).
        // Implementation can call this from within run().
        virtual void tick(float deltaTime) = 0;

        // per-frame rendering logic.
        virtual void render() = 0;
    };
}