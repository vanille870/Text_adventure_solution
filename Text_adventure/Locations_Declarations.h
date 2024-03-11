#pragma once
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <random>
#include <WorldObjects_Declarations.h>
#include <RandomNumber_Deca.h>


class Exit
{
public:
	bool Open;
	char ExitDirection;
	std::string BlockedMessage;
	std::string ExitLocation;

	Exit(bool InputIfOpen, int InputExitNumber, std::string InputBlockedMessage)
	{
		Open = InputIfOpen;
		ExitDirection = InputExitNumber;
		BlockedMessage = InputBlockedMessage;
	}

	Exit() 
	{
		Open = false;
		ExitDirection = 'S';
		BlockedMessage = "exit is not set   ";
	}
};

class Location
{

public:
	int LocationID;
	std::string LocationName;
	std::string LocationDescription;
	std::map <char, Exit> ExitMap;
	std::map <std::string, WorldObject> ObjectMap;
	//std::pair <int, std::string>


	Location(int InputID, std::string InputLocationName, std::string InputDescription)
	{
		LocationName = InputLocationName;
		LocationDescription = InputDescription;
		LocationID = InputID;

		Exit exit1;
		ExitMap['N'] = exit1;

		Exit exit2;
		ExitMap['E'] = exit2;

		Exit exit3; 
		ExitMap['S'] = exit3;

		Exit exit4; 
		ExitMap['W'] = exit4;
	}

	Location()
	{
		LocationID = 1;
	}


	std::string FindObjectInLocation(std::string InputObjectName, bool InputGiveObjctName)
	{
		auto it = this->ObjectMap.find(InputObjectName);

		if (it == ObjectMap.end())
		{
			int RandomNumber = MakeRandomNumber(1, 4);

			switch (RandomNumber)
			{
				
			case 1:
				return "There's no such object here dummy";
				break;

			case 2:
				return "Object not found";
				break;

			case 3:
				return "No such object";
				break;

			case 4:
				return "Can't find object";
				break;
			}
		}

		if (InputGiveObjctName == true)
		{
			return (it->second).ObjectName;
		}

		else
		{
			return (it->second).LookMessage;
		}


	}

	std::string FindAndRturn(std::string InputObjectName, bool InputGiveObjctName)
	{
		auto it = this->ObjectMap.find(InputObjectName);

		if (it == ObjectMap.end())
		{
			int RandomNumber = MakeRandomNumber(1, 4);

			switch (RandomNumber)
			{

			case 1:
				return "There's no such object here dummy";
				break;

			case 2:
				return "Object not found";
				break;

			case 3:
				return "No such object";
				break;

			case 4:
				return "Can't find object";
				break;
			}
		}

		if (InputGiveObjctName == true)
		{
			return (it->second).ObjectName;
		}

		else
		{
			return (it->second).LookMessage;
		}


	}
};

class LocationMap
{
public:     
	std::map<std::string, Location> LocationMap; 

			 void LoadLocationToMap(Location InputLocation)
			 {
				 this->LocationMap[InputLocation.LocationName] = InputLocation;
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

			 void AddExitToLocation(std::string LocationName, std::string InputExitLocation, std::string InputBlockedMessage, char InputExitDirction, bool InputExitOpen)
			 {
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].Open = InputExitOpen;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].BlockedMessage = InputBlockedMessage;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitDirection = InputExitDirction; 
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitLocation = InputExitLocation;
			 }

			 void AddObjectToLocation(std::string LocationName, std::string InputObjectName, std::string InputObjectLookMessage)
			 {
				 WorldObject worldObject;

				 worldObject.ObjectName = InputObjectName;
				 worldObject.LookMessage = InputObjectLookMessage;
				 this->LocationMap[LocationName].ObjectMap[InputObjectName] = worldObject;
			 }
};


class Navigator
{
public:
	Location CurrentLocation;

	void ChangeLocation(std::map<std::string, Location> InputMap, char InputExitDirction)
	{

		Exit targetExit = this->CurrentLocation.ExitMap[InputExitDirction];


		if (targetExit.Open == false)
		{
			std::cout << CurrentLocation.ExitMap[InputExitDirction].BlockedMessage << std::endl << std::endl;
		}

		else
		{
			std::string ExitLocationName;

			ExitLocationName = targetExit.ExitLocation;

			this->CurrentLocation = InputMap[ExitLocationName];

			std::cout << "moving to...  " << ExitLocationName <<  std::endl << std::endl; 
		}
	}
};

void CreateMapOfLocations(LocationMap* InputLocationMap);

void test(Exit exit, bool lbool);


