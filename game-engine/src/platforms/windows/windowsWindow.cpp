#include<GLFW/glfw3.h>
#include "gmpch.h"

#include "windowsWindow.h"
#include "core/window.h"
#include "core/core.h"

namespace GameEngine {

	static bool s_GLFW_initialized = false;

	Window* Window::create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		init(props);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props) {
		m_data.title = props.title;
		m_data.width = props.width;
		m_data.height = props.height;

		GM_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!s_GLFW_initialized) {
			int success = glfwInit();
			GM_CORE_ASSERT(success, "Could not initialize GLFW");

			s_GLFW_initialized = true;
		}

		m_window = glfwCreateWindow(
			(int)props.width,
			(int)props.height,
			props.title.c_str(),
			nullptr,
			nullptr
		);
		glfwMakeContextCurrent(m_window);
		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_data.vSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return m_data.vSync;
	}

}
