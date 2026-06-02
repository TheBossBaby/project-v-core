#pragma once

#include <cstdint>
#include <string_view>

namespace projectv::core
{
    /**
     * @brief Describes a window instance.
     */
    struct WindowDesc
    {
        /**
         * @brief Initial window width in pixels.
         */
        std::uint32_t width  = 0;

        /**
         * @brief Initial window height in pixels.
         */
        std::uint32_t height = 0;

        /**
         * @brief Window title displayed by the operating system.
         */
        std::string_view windowName;
    };
    
    /**
     * @brief Defines the interface for a platform window.
     *
     * Implementations are responsible for creating and managing
     * native operating system windows and processing window events.
     */
    class IWindow
    {
    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~IWindow() = default;
        
        /**
         * @brief Initializes the window.
         *
         * @param desc Window creation parameters.
         * @return true if initialization succeeded; otherwise false.
         */
        virtual bool init(const WindowDesc& desc) = 0;

        /**
         * @brief Shuts down the window and releases associated resources.
         */
        virtual void shutdown() = 0;

        /**
         * @brief Resizes the window.
         *
         * @param width New window width in pixels.
         * @param height New window height in pixels.
         */
        virtual void resize(uint32_t width, uint32_t height) = 0;

        /**
         * @brief Processes pending window and input events.
         */
        virtual void pollEvents() = 0;

        /**
         * @brief Determines whether the window has received a close request.
         *
         * @return true if the window should close; otherwise false.
         */
        virtual bool shouldClose() const = 0;
        
        /**
         * @brief Returns the current window width.
         *
         * @return Window width in pixels.
         */
        virtual uint32_t getWidth() const = 0;

        /**
         * @brief Returns the current window height.
         *
         * @return Window height in pixels.
         */
        virtual uint32_t getHeight() const = 0;
    };
}