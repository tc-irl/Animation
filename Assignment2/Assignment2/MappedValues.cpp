#include "MappedValues.h"


MappedValues::MappedValues(void)
{
}


MappedValues::~MappedValues(void)
{
}

void MappedValues::AddVector3f(const std::string& name, glm::vec3 value)
{
	vector3fMap.insert(std::pair<std::string, glm::vec3>(name, value));
}

void MappedValues::AddFloat(const std::string& name, float value)
{
	floatMap.insert(std::pair<std::string, float>(name, value));
}

glm::vec3 MappedValues::GetVector3f(const std::string& name) const
{
	std::map<std::string, glm::vec3>::const_iterator it = vector3fMap.find(name);
	if(it != vector3fMap.end())
		return it->second;

	return glm::vec3(0,0,0);
}

float MappedValues::GetFloat(const std::string& name) const
{
	std::map<std::string, float>::const_iterator it = floatMap.find(name);
	if(it != floatMap.end())
		return it->second;

	return 0;
}
