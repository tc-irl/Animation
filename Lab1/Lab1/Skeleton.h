#pragma once
#include "Bone.h"
#include "cylinder.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>
#include <iostream>

class Skeleton
{
public:
	Skeleton(int numBones);
	~Skeleton(void);

	void traverseHierarchy(Bone* bone);
	void setUpBones();
	Bone* root;
	int numBones; 
	glm::vec4 colorTop, colorBottom;
	void animateHand(GLuint modelLoc);

private:
	int count;
	bool swapPositions;
	float speed;
	GLuint modelLoc;
	glm::mat4 transform,gtransform;
};

