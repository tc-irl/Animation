#ifndef TRANSFORM_INCLUDED_H
#define TRANSFORM_INCLUDED_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "camera.h"

class Transform
{
public:
	Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));

	glm::mat4 GetTransformation() const;

	glm::mat4 GetModel() const;

	glm::mat4 GetMVP(const Camera& camera) const;

	glm::vec3* GetPos();
	glm::vec3* GetRot();
	glm::vec3* GetScale();

	void SetPos(glm::vec3& pos);
	void SetRot(glm::vec3& rot);
	void SetScale(glm::vec3& scale);
	void SetParent(Transform* transform);

	void Update();

protected:
private:

	glm::mat4 GetParentMatrix() const;
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;

	Transform* parent;
	mutable glm::mat4 parentMatrix;
};

#endif