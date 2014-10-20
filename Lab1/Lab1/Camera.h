#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Init.h"
class Camera
{
public:
	Camera(Init* initW);
	~Camera(void);
	
	void computeMatricesFromInputs();

	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
	void handleMVP(GLuint modelLoc, GLuint viewLoc, GLuint projLoc);

private:

	Init* initW;

	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	// Initial position : on +Z
	glm::vec3 position;
	// Initial horizontal angle : toward -Z
	float horizontalAngle;
	// Initial vertical angle : none
	float verticalAngle;
	// Initial Field of View
	float initialFoV;
	float FoV;
	
	float deltaTime;
	double currentTime;

	float speed;// 3 units / second
	float mouseSpeed;

	glm::vec3 direction, right,up;
};

