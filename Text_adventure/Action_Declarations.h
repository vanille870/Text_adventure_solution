#pragma once
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "Locations_Declarations.h"
#include "Inventory_Deca.h"



class ActionMap
{
public: 
	std::map<std::string, int> Map;

	  void LoadActionToMap(int InputActionID, std::string InputActionName)
	  {
		  this->Map[InputActionName] = InputActionID;
	  }
};

void CreateMapOfActions(ActionMap*);

int ReturnActionID(std::string);

void EnterAction(ActionMap* InputActionMapP, Navigator* InputNavigator, LocationMap* InputLocationMap, Inventory* InputInvntory);

void DisplayHelp();


