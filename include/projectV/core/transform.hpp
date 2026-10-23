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

        /**
         * @brief Builds the model matrix as Translation * Rotation * Scale.
         *
         * Rotation is composed as yaw (about Z/up), then pitch (about
         * Y/right), then roll (about X/forward), using right-handed
         * GLM rotation conventions.
         */
        math::Matrix4 toMatrix() const
        {
            const math::Vector3 radians = glm::radians(eulerDegrees);

            const math::Quaternion roll  = glm::angleAxis(static_cast<float>(radians.z), math::Vector3{1.0f, 0.0f, 0.0f});
            const math::Quaternion pitch = glm::angleAxis(static_cast<float>(radians.x), math::Vector3{0.0f, 1.0f, 0.0f});
            const math::Quaternion yaw   = glm::angleAxis(static_cast<float>(radians.y), math::Vector3{0.0f, 0.0f, 1.0f});
            const math::Quaternion rotation = yaw * pitch * roll;

            math::Matrix4 model = glm::translate(math::Matrix4{1.0f}, position);
            model *= glm::mat4_cast(rotation);
            model = glm::scale(model, scale);
            return model;
        }
    };
}