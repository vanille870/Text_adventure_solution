#pragma once
#include <iostream>
#include <map>

class Exit;



class WorldObject
{
public:
	std::string ObjectName;
	std::string LookMessage;
	void(*UseFunction)(Exit, bool);

 
	void DefaultFunction()
	{
		std::cout << "function not set" << std::endl;
	}

	WorldObject(std::string InputObjectName, std::string InputLookMessage) 
	{
		ObjectName = InputObjectName;  
		LookMessage = InputLookMessage; 

		UseFunction = NULL; 
	}

	WorldObject()
	{
		UseFunction = NULL; 
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