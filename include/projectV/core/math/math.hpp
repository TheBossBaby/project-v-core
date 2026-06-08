#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

/**
 * @brief Core math type aliases used across the engine.
 *
 * This namespace provides canonical aliases for common GLM types
 * (vectors, matrices and quaternions) that are used throughout
 * project-v-core and higher-level modules. By using these aliases
 * instead of raw GLM types directly, the rest of the codebase can
 * depend on a stable set of math names while still benefiting from
 * GLM's performance and portability.
 *
 * All types here are simple aliases; no additional behavior is added.
 * They are intended to be used as the standard math types for
 * transforms, camera parameters, mesh data, physics integration,
 * and shader inputs.
 */
namespace projectv::core::math
{
    using Vector2 = glm::vec2;
    using Vector3 = glm::vec3;
    using Vector4 = glm::vec4;

    using Matrix3 = glm::mat3;
    using Matrix4 = glm::mat4;

    using Quaternion = glm::quat;
}