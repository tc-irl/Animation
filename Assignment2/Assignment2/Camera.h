#ifndef CAMERA_INCLUDED_H
#define CAMERA_INCLUDED_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "GameComponent.h"

class Camera : public GameComponent
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar);
	glm::mat4 GetViewProjection() const;
	virtual void AddToEngine(CoreEngine* engine);

protected:
private:
	glm::mat4 projection;
	glm::vec3 pos;
	glm::vec3 forward;
	glm::vec3 up;
};

#endif