#pragma once
#include "event.h"

namespace Vision 
{
	//_______________________________________________________________________//
	class VISION_API WindowResizeEvent : public Event
	{
		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_width(width),
			m_height(height) {}

		inline unsigned int getWidth() const { return m_width; }
		
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)

	private:
		unsigned int m_width;
		unsigned int m_height;
	};

	//_______________________________________________________________________//
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryApplication)
	};

	//_______________________________________________________________________//
}