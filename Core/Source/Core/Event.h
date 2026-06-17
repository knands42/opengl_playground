#pragma once

#include <string>
#include <functional>

namespace Core
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased,
        MouseMoved, MouseScrolled
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { EventType::type; }\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                virtual const char* GetName() const override { return #type; }

    class Event
    {
    public:
        bool Handled = false;

        virtual ~Event() = default;

        [[nodiscard]] virtual auto GetEventType() const -> EventType = 0;
        [[nodiscard]] virtual auto GetName() const -> const char* = 0;
        [[nodiscard]] virtual auto ToString() const -> std::string { return GetName(); }
    };

    class EventDispatcher
    {
        template<typename T>
        using EvenFn = std::function<bool>(T&);
    public:
        EventDispatcher(Event& event) : m_Event(event) {}

        template<typename T>
        auto Dispatch(EvenFn<T> func) -> bool
        {
            if (m_Event.GetEventType() == T::GetStaticType() && !m_Event.Handled)
            {
                m_Event.Handled = func(*(static_cast<T*>(&m_Event)));
                return true;
            }
            return false;
        }

    private:
        Event& m_Event;
    };
}
