#include "Camera.h"

Camera::Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar)
{
	this->pos = pos;
	forward = glm::vec3(0.0f, 0.0f, 1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	projection = glm::perspective(fov, aspect, zNear, zFar);
}

glm::mat4 Camera::GetViewProjection() const
{
	return projection * glm::lookAt(pos, pos + forward, up);
}

void Camera::AddToEngine(CoreEngine* engine)
{
	engine->GetRenderingEngine()->AddCamera(this);
}
