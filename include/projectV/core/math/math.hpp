// project-v-core/include/projectv/core/math.hpp
#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

namespace projectv::core::math
{
    using Vector2 = glm::vec2;
    using Vector3 = glm::vec3;
    using Vector4 = glm::vec4;

    using Matrix3 = glm::mat3;
    using Matrix4 = glm::mat4;

    using Quaternion = glm::quat;
}