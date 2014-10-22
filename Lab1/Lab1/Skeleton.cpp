#include "Skeleton.h"

Bone *bones[MAX];
Cylinder *cylinder[MAX];

void Skeleton::setUpBones()
{
	colorTop = glm::vec4(1,1,1,1.0f);
	colorBottom = glm::vec4(0,0,0,1.0f);
	// Initializing bones
	bones[0] = new Bone("Wrist",glm::vec3(0,0,0),1,0);
	cylinder[0] = new Cylinder(glm::vec4(bones[0]->getPosition(),0),1, 0.5f, 0.5f, colorTop, colorBottom,2);
	cylinder[0]->generateObjectBuffer();

	bones[1] = new Bone("Thumb_Lower",glm::vec3(-0.60f,0.5f,0),0.30f,1);
	bones[1]->setParent(bones[0]);

	bones[2] = new Bone("Index_Lower",glm::vec3(-0.35f,1,0),0.35f,2);
	bones[2]->setParent(bones[0]);

	bones[3] = new Bone("Middle_Lower",glm::vec3(-0.07f,1,0),0.4f,3);
	bones[3]->setParent(bones[0]);

	bones[4] = new Bone("Ring_Lower",glm::vec3(.20f,1,0),0.35f,4);
	bones[4]->setParent(bones[0]);


	bones[5] = new Bone("Pinky_Lower",glm::vec3(0.40f,1,0),0.25f,5);
	bones[5]->setParent(bones[0]);

	bones[6] = new Bone("Thumb_Middle",glm::vec3(-0.60f,0.8f,0),0.30f,6);
	bones[6]->setParent(bones[1]);


	bones[7] = new Bone("Index_Middle",glm::vec3(-0.35f,1.35f,0),0.35f,7);
	bones[7]->setParent(bones[2]);

	bones[8] = new Bone("Middle_Middle",glm::vec3(-0.07f,1.4f,0),0.4f,8);
	bones[8]->setParent(bones[3]);

	bones[9] = new Bone("Ring_Middle",glm::vec3(0.20f,1.35f,0),0.35f,9);
	bones[9]->setParent(bones[4]);

	bones[10] = new Bone("Pinky_Middle",glm::vec3(0.40f,1.25f,0),0.25f,10);
	bones[10]->setParent(bones[5]);

	bones[11] = new Bone("Thumb_Upper",glm::vec3(-0.60f,1.1f,0),0.30f,11);
	bones[11]->setParent(bones[6]);

	bones[12] = new Bone("Index_Upper",glm::vec3(-0.35f,1.70f,0),0.35f,12);
	bones[12]->setParent(bones[7]);

	bones[13] = new Bone("Middle_Upper",glm::vec3(-0.07f,1.8f,0),0.4f,13);
	bones[13]->setParent(bones[8]);

	bones[14] = new Bone("Ring_Upper",glm::vec3(0.20f,1.7f,0),0.35f,14);
	bones[14]->setParent(bones[9]);

	bones[15] = new Bone("Pinky_Upper",glm::vec3(0.40f,1.5f,0),0.25f,15);
	bones[15]->setParent(bones[10]);

	for(int i = 1; i < MAX; i++)
	{
		cylinder[i] = new Cylinder(glm::vec4(bones[i]->getPosition(),0),bones[i]->getLength(), 0.05f, 0.05f, colorTop, colorBottom,16);
		cylinder[i]->generateObjectBuffer();
	}

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

}


Skeleton::Skeleton(int numBones)
{
	this->numBones = numBones;
	count = 0;
	swapPositions = true;
	speed = 0.01f;
}

void Skeleton::traverseHierarchy(Bone *bone)
{

	if(bone->getBoneName() == "Wrist")
	{
		bone->setBoneTransform(glm::rotate(glm::mat4(1.0f),0.0f,glm::vec3(1,0,0)));

		transform = bone->getLocalBoneTransform();
		gtransform = bone->calculateGlobalTransform();
		cylinder[bone->id]->update(modelLoc,gtransform);
		cylinder[bone->id]->draw();
	}
	else if(bone->getBoneName() == "Thumb_Lower")
	{
		transform = glm::translate(transform,(bone->getPosition()))
			* glm::rotate(transform,speed,glm::vec3(1,0,0)) 
			* glm::translate(transform,(bone->getParent()->getPosition() - bone->getPosition()));

		bone->setBoneTransform(transform);
		gtransform = bone->calculateGlobalTransform();
		cylinder[bone->id]->update(modelLoc,gtransform);
		cylinder[bone->id]->draw();
	}
	else if(bone->getBoneName() == "Thumb_Middle")
	{
		//transform = glm::translate(transform,bone->getParent()->getPosition() - bone->getPosition());
		transform = glm::rotate(transform,speed,glm::vec3(1,0,0));
		//transform = glm::translate(transform,(bone->getParent()->getPosition() - bone->getPosition()));

		bone->setBoneTransform(transform);
		gtransform = bone->calculateGlobalTransform();
		cylinder[bone->id]->update(modelLoc,gtransform);
		cylinder[bone->id]->draw();
	}

	else if(bone->getBoneName() == "Thumb_Upper")
	{
		//transform = glm::translate(transform,bone->getParent()->getPosition() - bone->getPosition());
		transform = glm::rotate(transform,speed,glm::vec3(1,0,0));
		//transform = glm::translate(transform,(bone->getParent()->getPosition() - bone->getPosition()));

		bone->setBoneTransform(transform);
		gtransform = bone->calculateGlobalTransform();
		cylinder[bone->id]->update(modelLoc,gtransform);
		cylinder[bone->id]->draw();
	}

	if(swapPositions)
	{
		speed += 0.001f;
		if(speed > 0)
		{
			swapPositions = false;
		}
	}
	if(swapPositions == false)
	{
		speed -= 0.001f;
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

void Skeleton::animateHand(GLuint modelLoc)
{
	this->modelLoc = modelLoc;

	traverseHierarchy(bones[0]);
}