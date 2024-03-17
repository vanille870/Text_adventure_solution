#pragma once
#include <iostream>
#include <map>
#include "Exits_Deca.h"

class WorldObject
{
public:
	std::string ObjectName;
	std::string LookMessage;
	std::string UseMessage;
	char AffectedExitDirection;
	bool IsDefault;

	WorldObject(std::string InputObjectName, std::string InputLookMessage, std::string InputUseMssage, char InputAffectedExit)
	{
		ObjectName = InputObjectName;
		LookMessage = InputLookMessage;
		UseMessage = InputUseMssage;
		AffectedExitDirection = 'x';
		IsDefault = false;
	}

	WorldObject(std::string InputObjectName, std::string InputLookMessage, std::string InputUseMssage) 
	{
		ObjectName = InputObjectName;  
		LookMessage = InputLookMessage; 
		UseMessage = InputUseMssage;
		AffectedExitDirection = 'x';
		IsDefault = false;
	}

	WorldObject()
	{
		AffectedExitDirection = 'x';
		ObjectName = "N/A";
		LookMessage = "N/A";
		UseMessage = "N/A";
		IsDefault = false;
	}

	virtual void ExitChangeFunction(Exit* InputExit)
	{
		std::cout << UseMessage << std::endl; 

    }


};

class ExitChangingObject : public WorldObject
{
public:
	std::string AfterUseMessage;
	bool OpenExit;
	bool Triggered;

	void ExitChangeFunction(Exit* InputExit) override   
	{
		if (Triggered == false)
		{
			std::cout << UseMessage << std::endl;

			InputExit->Open = OpenExit; 

			Triggered = true;

		}

		else
		{
			std::cout << AfterUseMessage << std::endl;
		}
	
	}

	ExitChangingObject() 
	{
		AffectedExitDirection = 'x';
		OpenExit = false;
		Triggered = false;
		AfterUseMessage = "default: not set";
		IsDefault = false;
	}

	void ChangeUseMessage(std::string InputUseMessage) 
	{
		UseMessage = InputUseMessage;
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