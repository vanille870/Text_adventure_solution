#pragma once
#include <iostream>
#include <map>


class WorldObject
{
public:
	std::string ObjectName;
	std::string LookMessage;
 

	WorldObject(std::string InputObjectName, std::string InputLookMessage)
	{
		ObjectName = InputObjectName;  
		LookMessage = InputLookMessage; 
	}

	WorldObject()
	{

	}

};

class WorldObjectManager
{
public:
	std::map<std::string, WorldObject> ObjectMap; 

	void LoadObjectToMap(WorldObject InputObject) 
	{
		this->ObjectMap[InputObject.ObjectName] = InputObject;
	}
};

void CreateMapOfObjects(WorldObjectManager*);