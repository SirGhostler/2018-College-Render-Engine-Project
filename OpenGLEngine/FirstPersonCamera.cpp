#include <glfw/glfw3.h>

#include "FirstPersonCamera.h"

void FirstPersonCamera::update(GLFWwindow * window, float deltaTime) override
{
	if (window == nullptr) return;

	auto& forward getTransform()[2];
	auto& right = getTransform()[0];
	auto& up getTransform()[1];

	auto worldUp = glm::vec4{ 0, 1, 0, 0 };

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		translate
	}
}
