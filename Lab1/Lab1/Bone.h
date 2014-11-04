#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <gl/glew.h>
#define MAX 16

using namespace std;

class Bone
{
public:
	Bone(void);
	Bone(string name, glm::vec3 position,int id);
	~Bone(void);

	string getBoneName();
	glm::vec3 getPosition();
	void setPosition(glm::vec3 position);

	glm::mat4 transform;
	glm::mat4 globalTransform;
	glm::mat4 offset;

	int getNumChildren();
	
	void setParent(Bone* parent);
	Bone* getParent();

	void addChild(Bone* child);

	glm::mat4 getLocalBoneTransform();

	glm::mat4 getGlobalBoneTransform();
	void setGlobalBoneTransform(glm::mat4 globalTransform);

	void setBoneTransform(glm::mat4 transform);
	float getLength();

	glm::mat4 calculateGlobalTransform();

	Bone *children[MAX];
	int id;

private:
	string name;
	Bone *parent;
	glm::vec3 position;
	float orientation;
	float length;
	int numChildren;
};

