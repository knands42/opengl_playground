#pragma once

#include "Event.h"

namespace Core
{
    class WindowClosedEvent : public Event
    {
    public:
        WindowClosedEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
    };

    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(const uint32_t width, const uint32_t height) : m_Width(width), m_Height(height) {}

        [[nodiscard]] inline auto GetWidth() const -> uint32_t { return m_Width; }
        [[nodiscard]] inline auto GetHeight() const -> uint32_t { return m_Height; }

        [[nodiscard]] auto ToString() const -> std::string override
        {
            return std::format("WindowResizeEvent: {} x {}", m_Width, m_Height);
        }

        EVENT_CLASS_TYPE(WindowResize)
    private:
        uint32_t m_Width, m_Height;
    };
};