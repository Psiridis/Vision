#pragma once

#include "Vision/core.h"

namespace Vision
{
	//_______________________________________________________________________//
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMove, MouseScrolled
	};

	//_______________________________________________________________________//
	enum class EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
	
	//_______________________________________________________________________//
    #define EVENT_CLASS_TYPE(type) static  EventType getStaticType() {return EventType::##type; }\
                                   virtual EventType getEventType() const override { return getStaticType(); }

    #define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return static_cast<int>(category); }
	
	//_______________________________________________________________________//
	class VISION_API Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType getEventType()     const = 0;
		virtual int       getCategoryFlags() const = 0;

		inline bool isInCategory(EventCategory category) {
			return (getCategoryFlags() & static_cast<int>(category));
		}

	protected:
		bool m_handled = false;
	};

	//_______________________________________________________________________//
}