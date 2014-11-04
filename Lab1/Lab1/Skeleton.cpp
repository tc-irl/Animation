#include "Skeleton.h"

Bone *bones[MAX];
Cylinder *cylinder[MAX];

void Skeleton::setUpBones()
{
	// Initializing bones
	bones[0] = new Bone("Wrist",glm::vec3(0,0,0),0);

	bones[1] = new Bone("Thumb_Lower",glm::vec3(-0.60f,0.3f,0),1);
	bones[1]->setParent(bones[0]);

	bones[2] = new Bone("Index_Lower",glm::vec3(-0.35f,1,0),2);
	bones[2]->setParent(bones[0]);

	bones[3] = new Bone("Middle_Lower",glm::vec3(-0.07f,1,0),3);
	bones[3]->setParent(bones[0]);

	bones[4] = new Bone("Ring_Lower",glm::vec3(.20f,1,0),4);
	bones[4]->setParent(bones[0]);


	bones[5] = new Bone("Pinky_Lower",glm::vec3(0.40f,1,0),5);
	bones[5]->setParent(bones[0]);

	bones[6] = new Bone("Thumb_Middle",glm::vec3(0,0.7,0),6);
	bones[6]->setParent(bones[1]);


	bones[7] = new Bone("Index_Middle",glm::vec3(0,0.7,0),7);
	bones[7]->setParent(bones[2]);

	bones[8] = new Bone("Middle_Middle",glm::vec3(0,0.7,0),8);
	bones[8]->setParent(bones[3]);

	bones[9] = new Bone("Ring_Middle",glm::vec3(0,0.7,0),9);
	bones[9]->setParent(bones[4]);

	bones[10] = new Bone("Pinky_Middle",glm::vec3(0,0.7,0),10);
	bones[10]->setParent(bones[5]);

	bones[11] = new Bone("Thumb_Upper",glm::vec3(0,0.7,0),11);
	bones[11]->setParent(bones[6]);

	bones[12] = new Bone("Index_Upper",glm::vec3(0,0.7,0),12);
	bones[12]->setParent(bones[7]);

	bones[13] = new Bone("Middle_Upper",glm::vec3(0,0.7,0),13);
	bones[13]->setParent(bones[8]);

	bones[14] = new Bone("Ring_Upper",glm::vec3(0,0.7,0),14);
	bones[14]->setParent(bones[9]);

	bones[15] = new Bone("Pinky_Upper",glm::vec3(0,0.7,0),15);
	bones[15]->setParent(bones[10]);

	// Setting the children
	bones[0]->addChild(bones[1]);
	bones[0]->addChild(bones[2]);
	bones[0]->addChild(bones[3]);

	bones[0]->addChild(bones[4]);
	bones[0]->addChild(bones[5]);

	bones[1]->addChild(bones[6]);
	bones[2]->addChild(bones[7]);
	bones[3]->addChild(bones[8]);
	bones[4]->addChild(bones[9]);
	bones[5]->addChild(bones[10]);

	bones[6]->addChild(bones[11]);
	bones[7]->addChild(bones[12]);
	bones[8]->addChild(bones[13]);
	bones[9]->addChild(bones[14]);
	bones[10]->addChild(bones[15]);

	drawHand();

}

Skeleton::Skeleton(int numBones)
{
	this->numBones = numBones;
	count = 0;
	swapPositions = true;
	speed = 0.01f;
}

//function to traverse through the bones, calculating transforms, updating and drawing cylinders.
void Skeleton::traverseHierarchy(Bone *bone)
{
	bone->transform = glm::rotate(bone->offset, speed, glm::vec3(1,0,0));

	if(bone->id == 0)
	{
		cylinder[0]->draw();
	}
	else
	{
		for (int i = 1; i < 16; i++)
		{
			bones[i]->globalTransform = bones[i]->calculateGlobalTransform();
			cylinder[i]->update(modelLoc,bones[i]->globalTransform);
			cylinder[i]->draw();
		}
	}
	if(swapPositions)
	{
		speed += 0.005f;
		if(speed > 55)
		{
			swapPositions = false;
		}
	}
	if(swapPositions == false)
	{
		speed -= 0.005f;
		if(speed < 0)
		{
			swapPositions = true;
		}
	}

	for (int i = 0; i < bone->getNumChildren(); i++)
	{
		traverseHierarchy(bone->children[i]);
	}
}

void Skeleton::drawHand()
{
	glm::vec4 cy_color_up = glm::vec4(1,1,1,1.0f);
	glm::vec4 cy_color_down = glm::vec4(0,0,0,1.0f);

	for(int i = 0; i < 16; i++) 
	{
		if (i == 0)
		{
			cylinder[i] = new Cylinder(2, 1, 1, cy_color_up, cy_color_down,2);
			cylinder[i]->generateObjectBuffer();
		}
		else
		{
			cylinder[i] = new Cylinder(0.7, 0.08f, 0.08f, cy_color_up, cy_color_down,16);
			cylinder[i]->generateObjectBuffer();
		}
	}
}

void Skeleton::animateHand(GLuint modelLoc)
{
	this->modelLoc = modelLoc;

	traverseHierarchy(bones[0]);
}
