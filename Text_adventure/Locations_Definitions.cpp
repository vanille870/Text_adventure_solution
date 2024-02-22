#include <iostream>
#include <vector>
#include "Travel_Declarations.h"
#include "Action_Declarations.h"
#include "Locations_Declarations.h"

void CreateMapOfLocations(LocationMap* InputLocationMap) 
{
    Location forest(0, "forest", "this is a forest");
    InputLocationMap->LoadLocationToMap(forest);
    InputLocationMap->LoadLocationToMap(Location(1, "cave", "This is a cave"));
}