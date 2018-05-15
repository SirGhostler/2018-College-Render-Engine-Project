//== Includes =======================

#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <iostream>

#include <gl_core_4_4.h>
#include <glfw/glfw3.h>

#include <Gizmos.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Application.h"
#include "Camera.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

//== Main =======================

int main()
{
	//if (glfwInit() == false)
	//{
	//	return -1;
	//}

	//GLFWwindow* window = glfwCreateWindow(1280, 720, "My Window!", nullptr, nullptr);

	//if (window == nullptr)
	//{
	//	glfwTerminate();
	//	return -2;
	//}

	//glfwMakeContextCurrent(window);

	//if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	//{
	//	glfwDestroyWindow(window);
	//	glfwTerminate();
	//	return -3;
	//}

	//auto major = ogl_GetMajorVersion();
	//auto minor = ogl_GetMinorVersion();
	//std::cout << "GL: " << major << "." << minor << "\n";

	//aie::Gizmos::create(1000, 1000, 1000, 1000);
	//mat4 view = glm::lookAt(vec3(10, 10, 10), vec3(0), vec3(0, 1, 0));
	//mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.0f, 0.1f, 1000.0f);

	//while (glfwWindowShouldClose(window) == false && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	//{
	//	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	//	glEnable(GL_DEPTH);
	//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	aie::Gizmos::clear();
	//	aie::Gizmos::addTransform(glm::mat4(1));

	//	vec4 white(1);
	//	vec4 black(0, 0, 0, 1);

	//	for (int i = 0; i < 21; ++i)
	//	{
	//		aie::Gizmos::addLine(vec3(-10 + i, 0, 10), vec3(-10 + i, 0, -10), i == 10 ? white : black);
	//		aie::Gizmos::add2DLine(vec3(10, 0, -10 + i), vec3(-10, 0, -10 + i), i == 10 ? white : black);
	//	}

	//	aie::Gizmos::draw(projection * view);

	//	glfwSwapBuffers(window);
	//	glfwPollEvents();
	//}

	//// my code

	//aie::Gizmos::destroy();
	//glfwDestroyWindow(window);
	//glfwTerminate();

	class DemoApplication : public Application
	{
	public:
		virtual bool onStartup() override
		{
			aie::Gizmos::create(10000, 10000, 10000, 10000);

			m_camera.setPosition({ 0, 0, 20, 1 });

			return true;
		}

		virtual void update() override
		{
			aie::Gizmos::clear();

			if (glfwWindowShouldClose(getWindow()))
			{
				setIsRunning(false);
			}

			//m_camera.translate(glm::vec4{ 0, 0, 1, 0 } * getDeltaTime() * 5.0f);

			auto& cameraTransform = m_camera.getTransform();

			auto rot = glm::angleAxis(getDeltaTime(), glm::vec3{ 0, 1, 0 });

			cameraTransform *= glm::mat4_cast(rot);
		}

		virtual void render() override
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			mat4 projection = glm::perspective(glm::pi<float>() * 0.25f, 16 / 9.0f, 0.1f, 1000.0f);

			mat4 view = glm::lookAt(glm::vec3(20, 20, 20), vec3(0), vec3(0, 1, 0));

			aie::Gizmos::draw(projection * view);
		}

		virtual void onShutdown() override
		{
			aie::Gizmos::destroy();
		}

	private:
		Camera m_camera;
	};

	DemoApplication app;
	return app.run("My Window!", 1280, 720, false, "config.ini");
}