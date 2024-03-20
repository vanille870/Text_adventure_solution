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
	std::map <std::string, WorldObject*> Map;
	WorldObject DefaultWorldObject;
	//std::pair <int, std::string>


	Location(int InputID, std::string InputLocationName, std::string InputDescription)
	{
		LocationName = InputLocationName;
		LocationDescription = InputDescription;
		LocationID = InputID;

		DefaultWorldObject.LookMessage = ""; 
		DefaultWorldObject.Name = "Default";
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


	WorldObject* FindObjectInLocation(std::string InputName) 
	{
		auto it = this->Map.find(InputName);

		if (it == Map.end())
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

	void AddInventoryObject(std::string InputName, std::string InputLookMessage)
	{
		InventoryObject* NewInventoryObject = new InventoryObject();

		NewInventoryObject->Name = InputName;
		NewInventoryObject->LookMessage = InputLookMessage;

		this->Map[InputName] = NewInventoryObject; 
	}

	void AddNormalObject(std::string InputName, std::string InputLookMessage, std::string InputUseMessage)
	{
		WorldObject* NewWorldObject = new WorldObject();

		NewWorldObject->Name = InputName;
		NewWorldObject->LookMessage = InputLookMessage;
		NewWorldObject->UseMessage = InputUseMessage; 
		NewWorldObject->AffectedExitDirection = 'x';  
		NewWorldObject->IsDefault = false; 
		NewWorldObject->ObjectType = "Normal";

		Map[InputName] = NewWorldObject;
	}

	void AddedExitObject(std::string InputName, std::string InputLookMessage, std::string InputUseMessage, std::string InputSecondUseMessage, bool InputExitOpen, char InputAffctedExitDirection)
	{
		ExitChangingObject* NewExitObject = new ExitChangingObject();
		 
		NewExitObject->Name = InputName; 
		NewExitObject->LookMessage = InputLookMessage;
		NewExitObject->UseMessage = InputUseMessage;
		NewExitObject->AfterUseMessage = InputSecondUseMessage;
		NewExitObject->AffectedExitDirection = InputAffctedExitDirection;
		NewExitObject->IsDefault = false; 
		NewExitObject->ObjectType = "Exit"; 

	}

	void AddExit(std::string InputExitLocation, std::string InputBlockedMessage, char InputExitDirection, bool InputExitOpen)
	{
		Exit* NewExit = new Exit();

		NewExit->ExitDirection = InputExitDirection;
		NewExit->BlockedMessage = InputBlockedMessage;
		NewExit->ExitLocation = InputExitLocation;
		NewExit->Open = InputExitOpen;

		ExitMap[InputExitDirection] = NewExit;
	}

	void AddAlwaysClosedExit(std::string InputBlockedMessage, char InputExitDirection)
	{
		Exit* NewExit = new Exit();

		NewExit->ExitDirection = InputExitDirection;
		NewExit->BlockedMessage = InputBlockedMessage;
		NewExit->Open = false;
		NewExit->ExitLocation = "None, error if shown";

		ExitMap[InputExitDirection] = NewExit; 
	}

	void AddAlwaysOpenExit(std::string InputBlockedMessage, std::string InputExitLocation, char InputExitDirection)
	{
		Exit* NewExit = new Exit();

		NewExit->ExitDirection = InputExitDirection;
		NewExit->BlockedMessage = InputBlockedMessage;
		NewExit->Open = true; 
		NewExit->ExitLocation = InputExitLocation;

		ExitMap[InputExitDirection] = NewExit;
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

			 void AddNormalObject(std::string LocationName, std::string InputName, std::string InputObjectLookMessage, std::string InputUseMessage, char InputExitDir)
			 {
				 WorldObject* worldObject = new WorldObject();  

				 worldObject->Name = InputName;
				 worldObject->LookMessage = InputObjectLookMessage;
				 worldObject->UseMessage = InputUseMessage; 
				 worldObject->AffectedExitDirection = InputExitDir;


				 this->LocationMap[LocationName]->Map[InputName] = worldObject;
			 }

			 void AddNormalObject(std::string LocationName, std::string InputName, std::string InputObjectLookMessage, std::string InputUseMessage)
			 {
				 WorldObject* worldObject = new WorldObject();

				 worldObject->Name = InputName; 
				 worldObject->LookMessage = InputObjectLookMessage;
				 worldObject->UseMessage = InputUseMessage;
				 worldObject->AffectedExitDirection = 'x';


				 this->LocationMap[LocationName]->Map[InputName] = worldObject;
			 }


			 void AddExitChangingObject(std::string LocationName, std::string InputName, std::string InputObjectLookMessage, std::string InputObjectUseMessage, std::string InputUSedMessage, bool InputExitOpen, char InputAffctedExitDirection)
			 {
				 ExitChangingObject* exitChangingObject = new ExitChangingObject(); 

				 exitChangingObject->Name = InputName;
				 exitChangingObject->LookMessage = InputObjectLookMessage;
				 exitChangingObject->UseMessage = InputObjectUseMessage;
				 exitChangingObject->OpenExit = InputExitOpen;
				 exitChangingObject->AffectedExitDirection = InputAffctedExitDirection;

				 this->LocationMap[LocationName]->Map[InputName] = exitChangingObject; 
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


