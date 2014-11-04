#include "ReferenceCounter.h"


ReferenceCounter::ReferenceCounter(void)
{
	refCount = 1;
}

int ReferenceCounter::GetReferenceCount()
{
	return refCount;
}

void ReferenceCounter::AddReference()
{
	refCount++;
}

bool ReferenceCounter::RemoveReference()
{
	refCount--;
	return refCount == 0;
}




