#pragma once
#include "gmpch.h"
#include "core/core.h"
#include "events/event.h"

namespace GameEngine {

	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& _title = "Game Engine", unsigned int _width = 1280, unsigned int _height = 720) :
			title(_title),
			width(_width),
			height(_height) {};
	};

	class GAME_ENGINE_API Window {
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFn& cb) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};

}

