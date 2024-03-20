#pragma once
#include <iostream>
#include <map>
#include "Exits_Deca.h"
#include "InventoryItems_Deca.h"
#include "Inventory_Deca.h"

class WorldObject
{
public:
	std::string Name;
	std::string LookMessage;
	std::string UseMessage;
	std::string ObjectType;
	char AffectedExitDirection;
	bool IsDefault;

	WorldObject()
	{
		AffectedExitDirection = 'x';
		Name = "N/A";
		LookMessage = "N/A";
		UseMessage = "N/A";
		IsDefault = false;
		ObjectType = "Normal";
	}

	virtual void ExitChangeFunction(Exit* InputExit)
	{
		std::cout << UseMessage << std::endl; 
    }

	virtual void PickUpObject(Inventory* InputInventory)
	{
		std::cout << "Can't Pick this up" << std::endl;
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

	ExitChangingObject* MakeNormalExitChangeObject(std::string InputName, std::string InputLookMessage, std::string InputUseMssage, char AffectedExit)
	{
		Name = InputName;
		LookMessage = InputLookMessage;
		UseMessage = InputUseMssage;
		AffectedExitDirection = AffectedExit;
		IsDefault = false;
		ObjectType = "Exit";

		return this;
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

class InventoryObject : public WorldObject
{
public:
	InventoryItem invItem;
	std::string PickUpmessage;


	void PickUpObject(Inventory* InputInventory) override
	{
		char YN;
		bool IsInputting = true;

		while (IsInputting == true)
		{
			std::cout << PickUpmessage << std::endl
				<< "Would you like to pick this up? (y/n)" << std::endl;
			std::cin >> YN;

			if (YN == 'Y' || YN == 'y')
			{
				IsInputting = false;
			}

			if (YN == 'N' || YN == 'n')
			{
				IsInputting = false;
			}

			else
			{
				std::cout << "Input Y or N" << std::endl;
			}
		}
	}
};

class WorldObjectManager
{
public:
	std::map<std::string, WorldObject> Map; 

	void LoadObjectToMap(WorldObject InputObject) 
	{
		this->Map[InputObject.Name] = InputObject;
	}
};



void CreateMapOfObjects(WorldObjectManager*);