#pragma once

namespace Core
{
    //
    // Key Events
    //
    class KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

    protected:
        KeyEvent(int keycode) : m_KeyCode(keycode)
        {
        }

        int m_KeyCode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, bool isRepeat) : KeyEvent(keycode), m_IsRepeat(isRepeat)
        {
        }

        [[nodiscard]] inline auto IsRepeat() const -> bool { return m_IsRepeat; }
        [[nodiscard]] auto ToString() const -> std::string override
        {
            return std::format("KeyPressedEvent: {} ({})", m_KeyCode, m_IsRepeat);
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        bool m_IsRepeat;
    };

    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode) : KeyEvent(keycode)
        {
        }

        [[nodiscard]] auto ToString() const -> std::string override
        {
            return std::format("KeyReleasedEvent: {}", m_KeyCode);
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };


    //
    // Mouse Events
    //
    class MouseMovedEvent : public Event
    {
        EVENT_CLASS_TYPE(MouseMoved)
    };

    class MouseScrolledEvent : public Event
    {
        EVENT_CLASS_TYPE(MouseScrolled)
    };

    class MouseButtonEvent : public Event
    {
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
