#pragma once
#include <iostream>
#include <string>
#include <map>
#include <utility>


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
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].Open = false;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].BlockedMessage = InputBlockedMessage;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitDirection = InputExitDirction;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitLocation = "No location: error if shown";
			 }

			 //for always open exits
			 void AddAlwaysOpenExitToLocation(std::string LocationName, std::string InputExitLocation, char InputExitDirction)
			 {
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].Open = true;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].BlockedMessage = "Should not be blocked";
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitDirection = InputExitDirction;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitLocation = InputExitLocation;

			 }

			 void AddExitToLocation(std::string LocationName, std::string InputExitLocation, std::string InputBlockedMessage, char InputExitDirction, bool InputExitOpen)
			 {
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].Open = InputExitOpen;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].BlockedMessage = InputBlockedMessage;
				 this->LocationMap[LocationName].ExitMap[InputExitDirction].ExitDirection = InputExitDirction; 
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
			std::cout << "moving..." << std::endl << std::endl;

			std::string ExitLocationName;

			ExitLocationName = targetExit.ExitLocation;

			this->CurrentLocation = InputMap[ExitLocationName];
		}
	}
};

void CreateMapOfLocations(LocationMap* InputLocationMap);


