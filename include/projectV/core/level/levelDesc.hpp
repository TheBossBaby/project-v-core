#pragma once

#include <optional>
#include <string>
#include <variant>
#include <vector>

#include <projectV/core/transform.hpp>

namespace projectv::core
{
    /**
     * @brief Asset-level description of a named graphics pipeline.
     *
     * Unlike GraphicsPipelineDescription, which carries shader bytecode for
     * IRenderer::createGraphicsPipeline(), this struct only references shader
     * assets by path. It is intended to be read from level/asset data; the
     * shaders must be loaded before the pipeline can be created.
     *
     * Pipelines are declared in LevelDesc::pipelineList. StaticMeshDesc and
     * SkyboxDesc refer to a pipeline through its name.
     */
    struct PipelineDesc
    {
        /**
         * @brief Name used by other descriptors to reference this pipeline.
         *
         * Must be unique within a LevelDesc.
         */
        std::string name;

        /**
         * @brief Path to the vertex shader asset, relative to the assets root..
         */
        std::string vertexShaderPath;

        /**
         * @brief Path to the fragment shader asset, relative to the assets root..
         */
        std::string fragmentShaderPath;
    };

    /**
     * @brief Asset-level description of a static mesh to load and render.
     *
     * Pairs a mesh asset on disk with the graphics pipeline used to draw it.
     * Used as the payload of an EntityDesc.
     */
    struct StaticMeshDesc
    {
        /**
         * @brief Path to the mesh asset, relative to the assets root.
         */
        std::string meshPath;

        /**
         * @brief Name of the pipeline used to render this mesh.
         *
         * Must match the PipelineDesc::name of a pipeline declared in
         * LevelDesc::pipelineList.
         */
        std::string pipelineName;
    };

    /**
     * @brief Asset-level description of a skybox.
     *
     * Pairs a cubemap texture asset with the graphics pipeline used to draw it.
     * Used as the payload of an EntityDesc.
     */
    struct SkyboxDesc
    {
        /**
         * @brief Path to the cubemap asset, relative to the assets root.
         */
        std::string cubemapPath;

        /**
         * @brief Name of the pipeline used to render the skybox.
         *
         * Must match the PipelineDesc::name of a pipeline declared in
         * LevelDesc::pipelineList.
         */
        std::string pipelineName;
    };

    /**
     * @brief Asset-level description of a single entity in a level.
     *
     * Combines an optional world placement with a type-specific payload.
     * The alternative held by #data decides what kind of entity this is.
     */
    struct EntityDesc
    {
        /**
         * @brief Name of the entity, for identification and debugging.
         */
        std::string name;

        /**
         * @brief Placement of the entity in the world.
         *
         * Leave empty for entities that are not placed in the world, such
         * as a skybox.
         */
        std::optional<Transform> transform;

        /**
         * @brief Type-specific payload of the entity.
         *
         * - StaticMeshDesc: a static mesh drawn at #transform.
         * - SkyboxDesc: a skybox drawn behind the rest of the level.
         */
        std::variant<StaticMeshDesc, SkyboxDesc> data;
    };

    /**
     * @brief Asset-level description of a complete level.
     *
     * Root of the level data: lists the pipelines a level needs and the
     * entities placed in it. Entities reference pipelines by name, so every
     * name used in #entityList must be declared in #pipelineList.
     */
    struct LevelDesc
    {
        /**
         * @brief Pipelines available to the entities of this level.
         */
        std::vector<PipelineDesc> pipelineList;

        /**
         * @brief Entities that make up this level.
         */
        std::vector<EntityDesc> entityList;
    };
}
