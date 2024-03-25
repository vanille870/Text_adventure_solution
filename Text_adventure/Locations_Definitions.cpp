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

    forest->AddAlwaysClosedExit("blocked by fallen tree", 'N');
    forest->AddAlwaysClosedExit("blocked by squirel", 'E');
    forest->AddAlwaysClosedExit("blocked by mr monopoly", 'S');

    forest->AddExit("cave", "Blocked by fallen tree", 'W', false);

    forest->AddNormalObject("ROCK", "a nice smooth rock", "You pick up the rock but nothing was under it");
    forest->AddedExitObject("TREELOG", "A log blocks the path", "You push the log out of the way", "You already pushed the log out of the way", true, 'W');
    forest->AddInventoryObject("BRANCH", "The branch looks pretty sturdy");


    Location* cave = new Location(1, "cave", "this is a cave");
    InputLocationMap->LoadLocationToMap(cave); 
    
    InputLocationMap->AddAlwaysOpenExitToLocation("cave", "forest", 'N');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "Just a cave wall", 'E');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "Just a wett cave wall", 'S');
    InputLocationMap->AddAlwaysClosedExitToLocation("cave", "end of cave", 'W');

    InputLocationMap->AddNormalObject("cave", "CRYSTAL", "A nice looking crystal", "The crystal is lodged firmly in the wall");
    InputLocationMap->AddNormalObject("cave", "ROCK", "A rock that rocks, a solid find", "You pick up the rock");

}