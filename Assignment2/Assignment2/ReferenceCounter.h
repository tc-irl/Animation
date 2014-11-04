#ifndef REFERENCECOUNTER_H
#define REFERENCECOUNTER_H

class ReferenceCounter
{
public:

	ReferenceCounter();
	int GetReferenceCount();

	void AddReference();
	bool RemoveReference();
protected:
private:
	int refCount;
};

#endif // REFERENCECOUNTER_H