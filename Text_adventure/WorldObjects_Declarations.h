#pragma once
#include <iostream>
#include <map>
#include <vector>
#include "InventoryItems_Deca.h"
#include "Inventory_Deca.h"
#include "Events_Deca.h"

template <typename T>
void TriggerEvents(T InputMap, Inventory* InputInv, std::map<std::string, WorldObject*>* InputObjctMap)
{
	for (Events* Events : InputMap)
	{
		Events->UseFunction(InputInv, InputObjctMap); 
	} 
}; 

template <typename T>
void AddEventToMap(T InputMap, Inventory* InputInv)
{
	for (Events* Events : InputMap)
	{
		Events->UseFunction(InputInv, InputObjctMap);
	}
};


class WorldObject
{
public:
	std::string Name;
	std::string LookMessage;
	std::string UseMessage;
	std::string ObjectType;
	char AffectedExitDirection;
	bool IsDefault;
	bool itemCanBeUsedOn = true;
	int requiredSTR;

	std::vector<Events*> UseEventList; 
	std::vector<Events*> CutItemEvenList;

	WorldObject()
	{
		AffectedExitDirection = 'x';
		Name = "N/A";
		LookMessage = "N/A";
		UseMessage = "N/A";
		IsDefault = false;
		ObjectType = "Normal";
		requiredSTR = 10;
	}

	virtual void ExitChangeFunction(Exit* InputExit)
	{
		std::cout << UseMessage << std::endl; 
    }

	virtual void PickUpObject(Inventory* InputInventory)
	{
		std::cout << "Can't Pick this up" << std::endl;
	}

	void TriggerEvents(Inventory* InputInventory, std::map<std::string, WorldObject*>* InputObjctMap)
	{
		for (Events* Events : UseEventList) 
		{
			Events->UseFunction(InputInventory, InputObjctMap);
		}
	}

	void TriggerCutEvents(Inventory* InputInventory, std::map<std::string, WorldObject*>* InputObjctMap)
	{
		for (Events* Events : CutItemEvenList)
		{
			Events->UseFunction(InputInventory, InputObjctMap);
		}
	}

	void AddEventToMap(Events* InputEvent, std::vector<Events*> InputVector)
	{
		InputVector.push_back(InputEvent);
	}

	void AddExitvent(Exit* InputExit, bool InputExitOpen, std::string InputAfterUseMessage, std::string UseMessage, std::vector<Events*> InputVector)
	{
		ChangeExitOnceE* changeExitOnceEvent = new ChangeExitOnceE();

		changeExitOnceEvent->AfterUseMessage = InputAfterUseMessage; 
		changeExitOnceEvent->ExitOpen = InputExitOpen;
		changeExitOnceEvent->UseMessage = UseMessage;
		changeExitOnceEvent->AffectedExit = InputExit;

		InputVector.push_back(changeExitOnceEvent); 
	}

	void addInventoryEvent(std::string InputName, std::string InputLookMessage, std::string InputBeforePickupMessage, std::vector<Events*> InputVector)
	{
		ChangeInventoryE* changeInventE = new ChangeInventoryE();

		changeInventE->ItemName = InputName;
		changeInventE->ItemLookMessage = InputLookMessage; 
		changeInventE->BeforePickUpmessage = InputBeforePickupMessage;

		InputVector.push_back(changeInventE);
	}

	void AddUseEvent(std::string InputUseMessage, std::vector<Events*> InputVector)
	{
		MessageE* message = new MessageE(InputUseMessage);

		InputVector.push_back(message);
	}

	void CheckItemParams(ToolItem* InputItem)
	{
		if (InputItem->Strength >= requiredSTR)
		{
			TriggerCutEvents();
		}

		else
		{
			std::cout << "epic fail" << std::endl; 
		} 
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

class ItemObject : public ExitChangingObject 
{
public:
	Events Object;

	void ObjectItemEvent(Exit* Inputexit, Inventory* InputInvntory) 
	{
		
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
				InputInventory->AdditemToInventory(Name, LookMessage);

				std::cout << "you pick the " << Name << " up" << std::endl; 
			}

			else if (YN == 'N' || YN == 'n')
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