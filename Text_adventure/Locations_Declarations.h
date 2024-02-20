#pragma once
#include <iostream>
#include <string>
#include <map>
#include <utility>


class Exit
{
	bool blocked;
	char direction;
	std::string BlockedMessage;
};

class Location
{

public:
	int LocationID;
	std::string LocationName;
	std::string LocationDescription;
	std::pair <char, Exit> ExitPairs[3];
	//std::pair <int, std::string>


	Location(int InputID, std::string InputLocationName, std::string InputDescription)
	{
		LocationName = InputLocationName;
		LocationDescription = InputDescription;
		LocationID = InputID;
	}

	Location()
	{

	}
	
};

class LocationMap
{
public:      std::map<std::string, Location> LocationMap; 
	         std::map<int, Location> LocationExitMap;

			 void LoadLocationToMap(Location InputLocation)
			 {
				 this->LocationMap[InputLocation.LocationName] = InputLocation;
				 this->LocationExitMap[InputLocation.LocationID] = InputLocation;
			 }

			 void LoadToExits(std::string InputName, Location inputLocation1)
			 {

			 }

			 void Exits()
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


