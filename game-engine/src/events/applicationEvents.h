#pragma once

#include "event.h"

namespace GameEngine {

	class GAME_ENGINE_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int w, unsigned int h) : m_w(w), m_h(h) {};
		unsigned int getWidth() { return m_w; };
		unsigned int getHeight() { return m_h; };

		std::string toString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent : " << m_w << ", " << m_h;
			return ss.str();
		};

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_w;
		unsigned int m_h;
	};

	class GAME_ENGINE_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class GAME_ENGINE_API AppTickEvent : public Event {
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class GAME_ENGINE_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class GAME_ENGINE_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

}