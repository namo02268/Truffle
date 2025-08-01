#pragma once

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include "Utils/Singleton.h"

// TODO: �C�x���g�N���X�̎���

namespace TRUFFLE
{
  class Event
  {
  public:
    virtual ~Event() = default;
  };

  class EventDispatcher : public Singleton<EventDispatcher>
  {
  public:
    friend class Singleton<EventDispatcher>;

    template <typename EventType>
    void Subscribe(std::function<void(const EventType &)> listener)
    {
      auto &listeners = m_handlers[typeid(EventType)];
      listeners.push_back([listener](const Event &e)
                          { listener(static_cast<const EventType &>(e)); });
    }

    template <typename EventType>
    void Dispatch(const EventType &event)
    {
      auto it = m_handlers.find(typeid(EventType));
      if (it != m_handlers.end())
      {
        for (const auto &handler : it->second)
        {
          handler(event);
        }
      }
    }

  private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event &)>>> m_handlers;
  };
}
