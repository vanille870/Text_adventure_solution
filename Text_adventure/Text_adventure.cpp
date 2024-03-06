#include <iostream>
#include <utility>
#include "Action_Declarations.h"
#include "Travel_Declarations.h"
#include "Locations_Declarations.h"
#include "WorldObjects_Declarations.h"



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

Navigator* InitNavigator(Location inputLocation)
{
    Navigator* NavigatorP = new Navigator();

    NavigatorP->CurrentLocation = inputLocation;

    return NavigatorP;
}

WorldObjectManager* InitManager()
{
    WorldObjectManager* WorldObjectManagerP = new WorldObjectManager();

    CreateMapOfObjects(WorldObjectManagerP);

    return WorldObjectManagerP;
}


int main()
{
    ActionMap* actionMapP = InitActionMap();
    LocationMap* locationMapP = InitLocationMap();
    Navigator* NavigatorP = InitNavigator(locationMapP->LocationMap["forest"]);
    WorldObjectManager* WorldObjectManagerP = InitManager();

    EnterAction(actionMapP, NavigatorP, locationMapP);

    return 0;
}
