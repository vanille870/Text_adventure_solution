#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "InventoryItems_Deca.h"
#include "RandomNumber_Deca.h"


class Inventory
{
public:
	std::map <std::string, InventoryItem*> Map; 
	InventoryItem DefaultInventoryItem;
	int MaxSize;

	void AdditemToInventory(std::string InputItemName, std::string InputLookMessage)
	{
		transform(InputItemName.begin(), InputItemName.end(), InputItemName.begin(), toupper); 

		InventoryItem* newItem = new InventoryItem();

		newItem->Name = InputItemName;
		newItem->CheckMessage = InputLookMessage;
		this->Map[InputItemName] = newItem;
	}

	Inventory(int InputMaxSize)
	{
		MaxSize = InputMaxSize;
		DefaultInventoryItem.Name = "DEFAULT";
		DefaultInventoryItem.IsDefault = true;
	}

	InventoryItem* FindItemInInventory(std::string InputName) 
	{
		auto it = this->Map.find(InputName);

		if (it == Map.end())
		{
			int RandomNumber = MakeRandomNumber(1, 4);

			switch (RandomNumber)
			{

			case 1:
				std::cout << "There's no such Item dummy" << std::endl;
				break;

			case 2:
				std::cout << "Item not found" << std::endl;
				break;

			case 3:
				std::cout << "No such Item" << std::endl;
				break;

			case 4:
				std::cout << "Can't find Item" << std::endl;
				break;
			}


			return &(DefaultInventoryItem); 
		}

		return (it->second);
	}

	void DeleteItemFromInventory(std::string InputItemName)
	{
		auto it = this->Map.find(InputItemName);

		if (it == Map.end())
		{
			int RandomNumber = MakeRandomNumber(1, 4); 

			switch (RandomNumber)
			{

			case 1:
				std::cout << "There's no such Item dummy" << std::endl;
				break;

			case 2:
				std::cout << "Item not found" << std::endl;
				break;

			case 3:
				std::cout << "No such Item" << std::endl;
				break;

			case 4:
				std::cout << "Can't find Item" << std::endl;
				break;
			}
		}

		it = Map.erase(it);
	}
};

Inventory* InitializeInventory();

