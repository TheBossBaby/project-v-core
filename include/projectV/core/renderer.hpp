#pragma once

#include <cstdint>
#include <string_view>
#include <vector>

#include <projectV/core/graphicsPipelineDescription.hpp>
#include <projectV/core/graphicsPipelineHandle.hpp>
#include <projectV/core/renderView.hpp>
#include <projectV/core/renderable.hpp>
#include <projectV/core/window.hpp>

namespace projectv::core
{
    /**
     * @brief Configuration parameters for a renderer instance.
     */
    struct RendererConfig
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
         * @brief Indicates whether vertical synchronization is enabled.
         */
        bool bIsVsync = true;

        /**
         * @brief Name of the application presented to the rendering backend.
         */
        std::string_view applicationName = "project-v";
    };

    /**
     * @brief Defines the interface for a rendering backend.
     *
     * Implementations are responsible for managing rendering resources,
     * presenting frames, handling resize events, and synchronizing GPU work.
     */
    class IRenderer
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IRenderer() = default;

        /**
         * @brief Initializes the renderer.
         *
         * @param config Configuration parameters used to initialize the renderer.
         * @return true if initialization succeeded; otherwise false.
         */
        virtual bool init(const RendererConfig& config, core::IWindow& inWindow) = 0;

        /**
         * @brief Resizes the render target.
         *
         * @param width New render target width in pixels.
         * @param height New render target height in pixels.
         */
        virtual void resize(std::uint32_t width, std::uint32_t height) = 0;

        /**
         * @brief Begins rendering a frame.
         *
         * Implementations typically acquire the next render target and
         * prepare command recording.
         */
        virtual void beginFrame(const RenderView& renderView) = 0;

        
        virtual void draw(const std::vector<Renderable>& items) = 0;

        /**
         * @brief Creates a graphics pipeline from a shader-level description.
         *
         * Implementations resolve the shader handles referenced by
         * @p description (for example through the engine's ShaderManager)
         * and build whatever backend-specific pipeline object corresponds
         * to them, keeping ownership of it internally.
         *
         * @param description Shader stages the pipeline is built from.
         * @return A handle identifying the created pipeline, or an invalid
         *         handle if creation failed (for example if a referenced
         *         shader handle could not be resolved).
         */
        virtual GraphicsPipelineHandle createGraphicsPipeline(const GraphicsPipelineDescription& description) = 0;

        /**
         * @brief Ends rendering a frame.
         *
         * Implementations typically submit recorded work and present the
         * rendered image.
         */
        virtual void endFrame() = 0;

        /**
         * @brief Waits for all pending rendering work to complete.
         *
         * Implementations should block until the renderer is idle.
         */
        virtual void waitIdle() = 0;
    };
}