#pragma once
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <random>
#include "WorldObjects_Declarations.h"
#include "RandomNumber_Deca.h"
#include "Exits_Deca.h"

class Location
{

public:
	int LocationID;
	std::string LocationName;
	std::string LocationDescription;
	std::map <char, Exit*> ExitMap;
	std::map <std::string, WorldObject*> ObjectMap;
	WorldObject DefaultWorldObject;
	//std::pair <int, std::string>


	Location(int InputID, std::string InputLocationName, std::string InputDescription)
	{
		LocationName = InputLocationName;
		LocationDescription = InputDescription;
		LocationID = InputID;

		DefaultWorldObject.LookMessage = ""; 
		DefaultWorldObject.ObjectName = "Default";
		DefaultWorldObject.IsDefault = true;

		Exit* exit1 = new Exit();  
		ExitMap['N'] = exit1;  

		Exit* exit2 = new Exit(); 
		ExitMap['E'] = exit2;

		Exit* exit3 = new Exit(); 
		ExitMap['S'] = exit3;

		Exit* exit4 = new Exit(); 
		ExitMap['W'] = exit4;
	}

	Location()
	{
		LocationID = 1;
	}


	WorldObject* FindObjectInLocation(std::string InputObjectName) 
	{
		auto it = this->ObjectMap.find(InputObjectName);

		if (it == ObjectMap.end())
		{
			int RandomNumber = MakeRandomNumber(1, 4);

			switch (RandomNumber)
			{
				
			case 1:
				std::cout << "There's no such object here dummy" << std::endl;
				break;

			case 2:
				std::cout << "Object not found" << std::endl;
				break;

			case 3:
				std::cout << "No such object" << std::endl;
				break;

			case 4:
				std::cout << "Can't find object" << std::endl;
				break;
			}

			
			return &(this->DefaultWorldObject); 
		}

		return (it->second);
	
	}
};

class LocationMap
{
public:     
	std::map<std::string, Location*> LocationMap; 

			 void LoadLocationToMap(Location* InputLocation)
			 {
				 this->LocationMap[InputLocation->LocationName] = InputLocation;
			 }

			 //for always closed exits
			 void AddAlwaysClosedExitToLocation(std::string LocationName, std::string InputBlockedMessage, char InputExitDirction)
			 {
				 AddExitToLocation(LocationName, "No location: error if shown", InputBlockedMessage, InputExitDirction, false);
			 }

			 //for always open exits
			 void AddAlwaysOpenExitToLocation(std::string LocationName, std::string InputExitLocation, char InputExitDirction)
			 {
				 AddExitToLocation(LocationName, InputExitLocation, "should not be blocked", InputExitDirction, true);

			 }

			 void AddExitToLocation(std::string InputLocationName, std::string InputExitLocation, std::string InputBlockedMessage, char InputExitDirection, bool InputExitOpen)
			 {
				 Exit* tempExit;
				 Location* tempLoc; 

				 tempLoc = this->LocationMap[InputLocationName];
				 tempExit = tempLoc->ExitMap[InputExitDirection];

				 tempExit->Open = InputExitOpen; 
				 tempExit->BlockedMessage = InputBlockedMessage;
				 tempExit->ExitDirection = InputExitDirection;
				 tempExit->ExitLocation = InputExitLocation; 

				 /*this->LocationMap[LocationName].ExitMap[InputExitDirction].Open = InputExitOpen;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].BlockedMessage = InputBlockedMessage;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitDirection = InputExitDirction;  
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitLocation = InputExitLocation;*/
			 }

			 void AddNormalObject(std::string LocationName, std::string InputObjectName, std::string InputObjectLookMessage, std::string InputUseMessage, char InputExitDir)
			 {
				 WorldObject* worldObject = new WorldObject();  

				 worldObject->ObjectName = InputObjectName;
				 worldObject->LookMessage = InputObjectLookMessage;
				 worldObject->UseMessage = InputUseMessage; 
				 worldObject->AffectedExitDirection = InputExitDir;


				 this->LocationMap[LocationName]->ObjectMap[InputObjectName] = worldObject;
			 }

			 void AddNormalObject(std::string LocationName, std::string InputObjectName, std::string InputObjectLookMessage, std::string InputUseMessage)
			 {
				 WorldObject* worldObject = new WorldObject();

				 worldObject->ObjectName = InputObjectName; 
				 worldObject->LookMessage = InputObjectLookMessage;
				 worldObject->UseMessage = InputUseMessage;
				 worldObject->AffectedExitDirection = 'x';


				 this->LocationMap[LocationName]->ObjectMap[InputObjectName] = worldObject;
			 }

			 void AddExitChangingObject(std::string LocationName, std::string InputObjectName, std::string InputObjectLookMessage, std::string InputObjectUseMessage, std::string InputUSedMessage, bool InputExitOpen, char InputAffctedExitDirection)
			 {
				 ExitChangingObject* exitChangingObject = new ExitChangingObject(); 

				 exitChangingObject->ObjectName = InputObjectName;
				 exitChangingObject->LookMessage = InputObjectLookMessage;
				 exitChangingObject->UseMessage = InputObjectUseMessage;
				 exitChangingObject->OpenExit = InputExitOpen;
				 exitChangingObject->AffectedExitDirection = InputAffctedExitDirection;

				 this->LocationMap[LocationName]->ObjectMap[InputObjectName] = exitChangingObject; 
			 }
};


class Navigator
{
public:
	Location CurrentLocation;

	void ChangeLocation(std::map<std::string, Location*> InputMap, char InputExitDirction)
	{

		Exit* targetExit = this->CurrentLocation.ExitMap[InputExitDirction];


		if (targetExit->Open == false)
		{
			std::cout << CurrentLocation.ExitMap[InputExitDirction]->BlockedMessage << std::endl << std::endl; 
		}

		else
		{
			std::string ExitLocationName;

			ExitLocationName = targetExit->ExitLocation; 

			this->CurrentLocation = *InputMap[ExitLocationName]; 

			std::cout << "moving to...  " << ExitLocationName <<  std::endl << std::endl; 
		}
	}
};

void CreateMapOfLocations(LocationMap* InputLocationMap);

void test(Exit exit, bool lbool);


