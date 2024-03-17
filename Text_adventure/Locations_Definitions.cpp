#include <iostream>
#include <vector>
#include "Travel_Declarations.h"
#include "Action_Declarations.h"
#include "Locations_Declarations.h"
#include "ObjectFunctionsDeca.h"

void CreateMapOfLocations(LocationMap* InputLocationMap) 
{

    Location* forest = new Location(0, "forest", "this is a forest");
    InputLocationMap->LoadLocationToMap(forest); 
    InputLocationMap->AddAlwaysClosedExitToLocation("forest", "blocked by fallen tree", 'N'); 
    InputLocationMap->AddAlwaysClosedExitToLocation("forest", "blocked by squirel", 'E'); 
    InputLocationMap->AddAlwaysClosedExitToLocation("forest", "blocked by mr monopoly", 'S'); 

    InputLocationMap->AddExitToLocation("forest", "cave", "Blocked by fallen tree",'W', false); 

    InputLocationMap->AddNormalObject("forest", "ROCK", "a nice smooth rock", "You pick up the rock but nothing was under it"); 
    InputLocationMap->AddExitChangingObject("forest", "TREELOG", "A log blocks the path", "You push the log out of the way", "You already pushed the log out of the way", true, 'W');


    Location* cave = new Location(1, "cave", "this is a cave");
    InputLocationMap->LoadLocationToMap(cave); 
    
    InputLocationMap->AddAlwaysOpenExitToLocation("cave", "forest", 'N');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "Just a cave wall", 'E');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "Just a wett cave wall", 'S');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "end of cave", 'W');

    InputLocationMap->AddNormalObject("cave", "CRYSTAL", "A nice looking crystal", "The crystal is lodged firmly in the wall");
    InputLocationMap->AddNormalObject("cave", "ROCK", "A rock that rocks, a solid find", "You pick up the rock");

}