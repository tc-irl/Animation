#pragma once
#include <map>
#include <glm/glm.hpp>

class MappedValues
{
public:
	void AddVector3f(const std::string& name, glm::vec3 value); 
	void AddFloat(const std::string& name, float value);
	
	glm::vec3 GetVector3f(const std::string& name) const;

	float GetFloat(const std::string& name) const;

protected:
private:
	std::map<std::string, glm::vec3> vector3fMap;
	std::map<std::string, float> floatMap;
};

