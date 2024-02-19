#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Locations_Declarations.h"



class ActionMap
{
public: 
	map<string, int> Map;

	  void LoadActionToMap(int InputActionID, std::string InputActionName)
	  {
		  this->Map[InputActionName] = InputActionID;
	  }
};

void CreateMapOfActions(ActionMap*);

int ReturnActionID(std::string);

void EnterAction(ActionMap*, Navigator*);

void DisplayHelp();
