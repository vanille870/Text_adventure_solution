#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Location
{

public:
	string LocationName;
	string LocationDescription;

	Location(string InputLocationName, string InputDescription)
	{
		LocationName = InputLocationName;
		LocationDescription = InputDescription;
	}

	Location()
	{

	}
	
};

class LocationMap
{
	public:  std::map<string, Location> LocationMap; 
		  Location loc[3];

			 void LoadLocationToMap(Location InputLocation)
			 {
				 this->LocationMap[InputLocation.LocationName] = InputLocation;
			 }

			 void LoadToExits(Location InputName, Location inputLocation1)
			 {

			 }
};

class Navigator
{
public:
	Location CurrentLocation;
};

void CreateMapOfLocations(LocationMap* InputLocationMap);


