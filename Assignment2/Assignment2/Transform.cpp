#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera.h"

Transform::Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale)
{
	this->pos = pos;
	this->rot = rot;
	this->scale = scale;

	parentMatrix = glm::mat4(1.0f);
}

glm::mat4 Transform::GetModel() const
{
	glm::mat4 posMat = glm::translate(pos);
	glm::mat4 scaleMat = glm::scale(scale);
	glm::mat4 rotX = glm::rotate(rot.x, glm::vec3(1.0, 0.0, 0.0));
	glm::mat4 rotY = glm::rotate(rot.y, glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 rotZ = glm::rotate(rot.z, glm::vec3(0.0, 0.0, 1.0));
	glm::mat4 rotMat = rotX * rotY * rotZ;

	return posMat * rotMat * scaleMat;
}

glm::mat4 Transform::GetMVP(const Camera& camera) const
{
	glm::mat4 VP = camera.GetViewProjection();
	glm::mat4 M = GetModel();

	return VP * M;
}

glm::vec3* Transform::GetPos()
{
	return &pos;
}

glm::vec3* Transform::GetRot()
{
	return &rot;
}

glm::vec3* Transform::GetScale()
{
	return &scale;
}

void Transform::SetPos(glm::vec3& pos)
{
	this->pos = pos;
}

void Transform::SetRot(glm::vec3& rot)
{
	this->rot = rot;
}

void Transform::SetScale(glm::vec3& scale)
{
	this->scale = scale;
}

glm::mat4 Transform::GetParentMatrix() const
{
	return parentMatrix;
}

glm::mat4 Transform::GetTransformation() const
{
	return GetParentMatrix() * GetModel();
}

void Transform::SetParent(Transform* parent)
{
	this->parent = parent;
}
