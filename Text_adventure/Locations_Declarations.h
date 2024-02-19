#include <iostream>
#include <string>
#include <map>

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

void CreateMapOfLocations(LocationMap* InputLocationMap);


