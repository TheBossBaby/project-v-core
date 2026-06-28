#pragma once

#include <projectV/core/math/math.hpp>

namespace projectv::core
{
    /**
     * @brief Spatial transform data: position, rotation and scale.
     *
     * Uses an Unreal-style coordinate system:
     * - X axis points forward
     * - Y axis points right
     * - Z axis points up
     *
     * World-space units are expressed in centimeters.
     *
     * This is a pure data type and is suitable for use as an ECS
     * component or in any other part of the engine that needs to
     * represent a transform.
     */
    struct Transform
    {
        /**
         * @brief World-space position in centimeters.
         *
         * Components are ordered as X (forward), Y (right), Z (up).
         */
        math::Vector3 position{0.0f, 0.0f, 0.0f};

        /**
         * @brief Rotation angles in degrees.
         *
         * Ordered as:
         * - X: pitch
         * - Y: yaw
         * - Z: roll
         *
         * Intended for developer-friendly editing. For simulation and
         * rendering, convert to quaternions or matrices via helper
         * functions.
         */
        math::Vector3 eulerDegrees{0.0f, 0.0f, 0.0f};

        /**
         * @brief Non-uniform scale along each axis.
         */
        math::Vector3 scale{1.0f, 1.0f, 1.0f};
    };
}