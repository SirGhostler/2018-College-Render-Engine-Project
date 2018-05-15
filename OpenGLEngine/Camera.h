#pragma once

//== Includes =======================

#pragma warning (push)
#pragma warning (disable:4201)
#pragma warning (disable:4310)
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#pragma warning (pop)

//== Classes =======================

class Camera
{
public:
	virtual ~Camera() {}

	void setPosition(glm::vec4 position);

	glm::vec4 getPosition() const;

	void translate(glm::vec4 positionModifier);

	glm::mat4 getViewMatrix() const { return glm::inverse(m_worldTransform); }

	const glm::mat4& getTransform() const { return m_worldTransform; }
	glm::mat4& getTransform() { return m_worldTransform; }

	const glm::mat4& getProjectionMatrix() const;
	void setProjectionMatrix(glm::mat4 projectionMatrix);

	virtual void update(struct GLFWwindow* window, float deltaTime) {}

protected:

private:
	glm::mat4 m_worldTransform = glm::mat4(1);
	glm::mat4 m_projectionMatrix = glm::mat4(1);

	bool m_HasSetProjectionMatrix = false;
};