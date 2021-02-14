#pragma once

#include "event.h"

namespace GameEngine {

	class GAME_ENGINE_API KeyEvent : public Event {
	public:
		inline int getKeyCode() { return m_code; };

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(int code) : m_code(code) {};

		int m_code;
	};

	class GAME_ENGINE_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatcount) :
			KeyEvent(keycode), m_repeatCount(repeatcount) {};

		inline int getRepeatCount() const { return m_repeatCount; };

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_code << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeatCount;
	};

	class GAME_ENGINE_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) :
			KeyEvent(keycode) {};

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_code;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}