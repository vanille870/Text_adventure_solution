#include <iostream>
#include <vector>
#include "Travel_Declarations.h"
#include "Action_Declarations.h"
#include "Locations_Declarations.h"

void CreateMapOfLocations(LocationMap* InputLocationMap) 
{
    InputLocationMap->LoadLocationToMap(Location("forest", "this is a forest"));
    InputLocationMap->LoadLocationToMap(Location("cave", "This is a cave"));
}