#include <iostream>
#include <vector>
#include "Travel_Declarations.h"
#include "Action_Declarations.h"
#include "Locations_Declarations.h"

void CreateMapOfLocations(LocationMap* InputLocationMap) 
{
    Location forest(0, "forest", "this is a forest");
    InputLocationMap->LoadLocationToMap(forest); 
    InputLocationMap->AddAlwaysClosedExitToLocation("forest", "blocked by falling tree", 'N');
    InputLocationMap->AddAlwaysClosedExitToLocation("forest", "blocked by squirel", 'E'); 
    InputLocationMap->AddAlwaysClosedExitToLocation("forest", "blocked by mr monopoly", 'S');

    InputLocationMap->AddAlwaysOpenExitToLocation("forest", "cave", 'W');

    Location cave(1, "cave", "this is a cave");
    InputLocationMap->LoadLocationToMap(cave);

    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "end of cave", 'N');

    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "cave wall", 'E');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "wet cave wall", 'S');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "end of cave", 'W'); 
    
}