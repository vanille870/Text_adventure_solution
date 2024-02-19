#include <iostream>
#include <utility>
#include "Action_Declarations.h"
#include "Travel_Declarations.h"
#include "Locations_Declarations.h"



LocationMap* InitLocationMap()
{
    LocationMap* locationMapP = new LocationMap();

    CreateMapOfLocations(locationMapP);

    return locationMapP;
}

ActionMap* InitActionMap()
{
    ActionMap* actionMapP = new ActionMap(); 

    CreateMapOfActions(actionMapP);
     
    return actionMapP; 
}

int main()
{
    ActionMap* actionMapP = InitActionMap();
    LocationMap* locationMapP = InitLocationMap();


    EnterAction(actionMapP);

    return 0;
}
