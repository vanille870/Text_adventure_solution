#pragma once
#include <iostream>
#include <string>
#include <map>


class InventoryItem
{
public:
	std::string Name;
	std::string CheckMessage;
	bool CanBeUsed = false;
	bool IsDefault = false;

	virtual void UseItem()
	{
		std::cout << CheckMessage << std::endl;
	}
}; 

class ToolItem : public InventoryItem
{
public:
	std::string ToolType;
	std::string FailMessage;
    int Strength;

	ToolItem(std::string InputType, int InputStrength)
	{
		ToolType = InputType;
		Strength = InputStrength;
		CanBeUsed = true;
	}

	void UseItem() override
	{

	}
};

class Key : public InventoryItem
{
public: 
	std::string Door;
};


