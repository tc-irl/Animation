#pragma once
#include <gl/glew.h>
#include "MappedValues.h"


class RenderUtil
{
public:
	RenderUtil(void);
	~RenderUtil(void);

	static void ClearScreen();
	static void InitGraphics();
};

