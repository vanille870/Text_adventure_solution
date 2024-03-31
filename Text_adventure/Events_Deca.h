#pragma once
#include "Inventory_Deca.h"
#include "Exits_Deca.h"
#include "WorldObjects_Declarations.h"

class WorldObject;

class Events
{
public:

	virtual void UseFunction(Inventory* InputInventory, std::map<std::string, WorldObject*>* InputObjctMap) 
	{
		std::cout << "wrong function";
	}
};

class ChangeExitOnceE : public Events
{
public: 
	std::string AfterUseMessage; 
	bool ExitOpen;
	bool Triggered;
	Exit* AffectedExit; 
	std::string UseMessage;

	virtual void UseFunction(Inventory* InputInventory, std::map<std::string, WorldObject*>* InputObjctMap) override
	{
		if (Triggered == false)
		{
			std::cout << UseMessage << std::endl;

			AffectedExit->Open = ExitOpen;   

			Triggered = true;

		}

		else
		{
			std::cout << AfterUseMessage << std::endl;
		}
	}
};

class ChangeInventoryE : public Events
{
public: 
	std::string BeforePickUpmessage;
	std::string ItemLookMessage;
	std::string ItemName;
	bool DeleteThis = true;

	void UseFunction(Inventory* InputInventory, std::map<std::string, WorldObject*>* InputObjctMap) override
	{
		char YN;
		bool IsInputting = true;

		while (IsInputting == true)
		{
			std::cout << BeforePickUpmessage << std::endl << "Would you like to pick this up? (y/n)" << std::endl;
			std::cin >> YN;

			if (YN == 'Y' || YN == 'y')
			{
				IsInputting = false;
				InputInventory->AdditemToInventory(ItemName, ItemLookMessage);
				std::cout << ItemName;
				InputObjctMap->erase(ItemName);

				std::cout << "you pick the " << ItemName << " up" << std::endl;
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

class MessageE : public Events 
{
public:
	std::string UseMessage;


	void UseFunction(Inventory* InputInventory, std::map<std::string, WorldObject*>* InputObjctMap) override
	{
		std::cout << UseMessage << std::endl << std::endl;
	}

	MessageE(std::string InputUseMessage)
	{
		UseMessage = InputUseMessage;
	}
};

class DeleteE : public Events
{

};


