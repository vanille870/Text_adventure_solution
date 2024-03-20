#pragma once
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <InventoryItems_Deca.h>

class Inventory
{
public:
	std::map <std::string, InventoryItem*> Map; 
	int MaxSize;

	void AdditemToInventory(std::string InputItemName)
	{
		transform(InputItemName.begin(), InputItemName.end(), InputItemName.begin(), toupper); 

		InventoryItem* newItem = new InventoryItem();

		newItem->Name = InputItemName;
		this->Map[InputItemName] = newItem;
	}

	Inventory(int InputMaxSize)
	{
		MaxSize = InputMaxSize;
	}

	void DeleteItemFromInventory()
	{
		//this->Map.erase("HATCHET");
	
	}
};

Inventory* InitializeInventory();

