//== Includes =======================

#include <gl_core_4_4.h>
#include <glfw/glfw3.h>

#include "Application.h"

//== Functions =======================

int Application::run(std::string windowTile, int windowWidth, int windowHeight, bool isFullscreen, std::string configFilePath)
{
	auto successful = initialise(windowTile, windowWidth, windowHeight, isFullscreen);

	if (!successful)
	{ return -1; }

	if(!onStartup())
	{ shutdown(); return -2; }

	gameLoop();

	onShutdown();
	shutdown();

	return 0;
}

bool Application::initialise(std::string windowTile, int windowWidth, int windowHeight, bool isFullscreen)
{
	if (glfwInit() == false)
	{ return false; }

	//GLFWmonitor* monitor = nullptr;
	//if (isFullscreen)
	//{ monitor = glfwGetPrimaryMonitor(); }

	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, windowTile.c_str(), (isFullscreen ? glfwGetPrimaryMonitor() : nullptr), nullptr);

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		return false;
	}

	m_window = window;
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	m_isFullscreen = isFullscreen;

	return true;
}

void Application::gameLoop()
{
	while (getIsRunning())
	{ 
		auto now = std::chrono::high_resolution_clock::now();
		auto timeTaken = now - m_previousFrameTime;
		m_deltaTime = std::chrono::duration<float>(timeTaken).count();
		m_previousFrameTime = now;

		auto elapsedTime = now - m_applicationStartTime;
		m_elapsedTime = std::chrono::duration<float>(elapsedTime).count();

		update();
		render();

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}
}

void Application::shutdown()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
