#pragma once
#include <string>
#define MAX 6

using namespace std;
class Bone
{
public:
	Bone(void);
	~Bone(void);

	string getBoneName();

private:
	string name;
	Bone *parent;
	Bone *children[MAX];
};

