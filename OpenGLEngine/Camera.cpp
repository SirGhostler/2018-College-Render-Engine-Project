#include "Camera.h"
#include <assert.h>

void Camera::setPosition(glm::vec4 position)
{
	m_worldTransform[3] = position;
}

glm::vec4 Camera::getPosition() const
{
	return m_worldTransform[3];
}

void Camera::translate(glm::vec4 positionModifier)
{
	m_worldTransform[3] += positionModifier;
}

const glm::mat4 & Camera::getProjectionMatrix() const
{
	assert((m_HasSetProjectionMatrix) == true);
	return m_projectionMatrix;
}

void Camera::setProjectionMatrix(glm::mat4 projectionMatrix)
{
	m_HasSetProjectionMatrix = true;
	m_projectionMatrix = projectionMatrix;
}
