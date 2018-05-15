#include "Camera.h"

class FirstPersonCamera : public Camera
{
public:
	void update(struct GLFWwindow* window, float deltaTime);
};