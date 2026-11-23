#pragma once

namespace bk
{
    class Event
    {
    public:
        virtual ~Event() = default;
        std::string getName() const { return m_name; };
    
    protected:
        Event(const std::string name) : m_name(name) {};

        const std::string m_name;
    };
}
