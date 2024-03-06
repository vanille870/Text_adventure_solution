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

    InputLocationMap->AddObjectToLocation("forest", "Rock", "a nice smooth rock");
    InputLocationMap->AddObjectToLocation("forest", "Well", "you peer down the well and see only the void");


    Location cave(1, "cave", "this is a cave");
    InputLocationMap->LoadLocationToMap(cave);
    
    InputLocationMap->AddAlwaysOpenExitToLocation("cave", "forest", 'N');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "blocked by squirel", 'E');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "blocked by mr monopoly", 'S');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "end of cave", 'W');

    InputLocationMap->AddObjectToLocation("cave", "Crystal", "final fantasy reference");
    InputLocationMap->AddObjectToLocation("cave", "rock", "A rock that rocks, a solid find");
}