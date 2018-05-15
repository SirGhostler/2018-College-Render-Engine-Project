#pragma once

//== Includes =======================

#include <string>
#include <chrono>

//== Classes =======================

class Application
{
public:
	virtual ~Application() {}

	virtual bool onStartup() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void onShutdown() = 0;

	int run(std::string windowTile,
			int windowWidth, int windowHeight,
			bool isFullscreen,
			std::string configFilePath = "");

	bool initialise(std::string windowTile,
					int windowWidth, int windowHeight,
					bool isFullscreen);

	void gameLoop(); 
	
	void shutdown();

	struct GLFWwindow * getWindow() const { return m_window; }

	int getWindowWidth() const { return m_windowWidth; }
	int getWindowHeight() const { return m_windowHeight; }
	int getIsFullscreen() const { return m_isFullscreen; }
	int getIsRunning() const { return m_isRunning; }
	int setIsRunning(bool value) { m_isRunning = value; }

	float getDeltaTime() const { return m_deltaTime; }
	float getElapsedTime() const { return m_elapsedTime; }

protected:

private:
	GLFWwindow * m_window = nullptr;

	int m_windowWidth = 1280;
	int m_windowHeight = 720;
	bool m_isFullscreen = false;
	bool m_isRunning = true;

	float m_deltaTime = 0.0f;
	float m_elapsedTime = 0.0f;

	std::chrono::high_resolution_clock::time_point m_previousFrameTime;
	std::chrono::high_resolution_clock::time_point m_applicationStartTime;
};