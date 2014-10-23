#include "Bone.h"


Bone::Bone(void)
{

}

Bone::Bone(string name, glm::vec3 position, float length, int id)
{
	numChildren = 0;
	this->name = name;
	this->position = position;
	this->length = length;
	this->id = id;
	//transform = glm::translate(glm::mat4(1.0f),position);
	//globalTransform = glm::mat4(1.0f);
}


Bone::~Bone(void)
{
}

std::string Bone::getBoneName()
{
	return name;
}

glm::vec3 Bone::getPosition()
{
	return position;
}

int Bone::getNumChildren()
{
	return numChildren;
}

glm::mat4 Bone::calculateGlobalTransform()
{
	if(getBoneName() == "Wrist")
	{
		globalTransform = transform;
		return globalTransform;
	}
	else
	{
		globalTransform = transform * parent->globalTransform;

		return globalTransform;
	}
}

glm::mat4 Bone::getLocalBoneTransform()
{
	return transform;
}

glm::mat4 Bone::getGlobalBoneTransform()
{
	return globalTransform;
}

void Bone::addChild(Bone* child)
{
	children[numChildren] = child;
	numChildren++;
}

void Bone::setParent(Bone* parent)
{
	this->parent = parent;
}

Bone* Bone::getParent()
{
	return parent;
}

void Bone::setBoneTransform(glm::mat4 transform)
{
	this->transform = transform;
}

void Bone::setGlobalBoneTransform(glm::mat4 globalTransform)
{
	this->globalTransform = globalTransform;
}

float Bone::getLength()
{
	return length;
}

