#pragma once

#include "core/window.h"
#include<GLFW/glfw3.h>

namespace GameEngine {

	class WindowsWindow : public Window {

	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_data.width; };
		inline unsigned int getHeight() const override { return m_data.height; };

		inline void setEventCallback(const EventCallbackFn& cb) override { m_data.eventCallback = cb; };
		void setVSync(bool enabled) override;
		bool isVSync() const;

	private:

		virtual void init(const WindowProps& props);
		virtual void shutdown();

		GLFWwindow* m_window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;
			EventCallbackFn eventCallback;
		};

		WindowData m_data;

	};

}