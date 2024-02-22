#pragma once
#include <iostream>
#include <string>
#include <map>
#include <utility>


class Exit
{
public:
	bool blocked;
	int ExitNumber;
	std::string BlockedMessage;

	Exit(bool InputClosed, int inputExitNumber, std::string inputBlockedMessage)
	{

	}

	Exit()
	{

	}
};

class Location
{

public:
	int LocationID;
	std::string LocationName;
	std::string LocationDescription;
	std::pair <int, Exit> ExitPairs[3];
	//std::pair <int, std::string>


	Location(int InputID, std::string InputLocationName, std::string InputDescription)
	{
		LocationName = InputLocationName;
		LocationDescription = InputDescription;
		LocationID = InputID;

		for (int i = 0; i == 3; i++)
		{
			Exit exit;
			ExitPairs[i].first = i;
			ExitPairs[i].second = exit;
		}
	}

	Location()
	{

	}
};

class LocationMap
{
public:      std::map<std::string, Location> LocationMap; 

			 void LoadLocationToMap(Location InputLocation)
			 {
				 this->LocationMap[InputLocation.LocationName] = InputLocation;
			 }

			 void LoadToExits(std::string InputName, Location inputLocation1)
			 {

			 }

			 void Exits()
			 {

			 }

			 void AddExitToLocation(int InputLocationID, Location InputLocation, int InputLocationNumber, bool InputExitOpen)
			 {
				 Exit TestExit(InputExitOpen, InputLocationNumber, "test");

				 this->LocationMap["forsest"].ExitPairs[0].second.blocked = InputExitOpen;
			 }

			 void AddExitToLocation(int InputLocationID, Location InputLocation, int InputLocationNumber, bool InputExitOpen, std::string InputExitDescription)
			 {

			 }
};

class Navigator
{
public:
	Location CurrentLocation;

	void ChangeLocation(Location inputLocation1, std::map<std::string, Location>)
	{

	}
};

void CreateMapOfLocations(LocationMap* InputLocationMap);


