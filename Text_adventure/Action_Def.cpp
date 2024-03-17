#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <map>
#include "Action_Declarations.h"
#include "Travel_Declarations.h"
#include "Locations_Declarations.h"
#include "WorldObjects_Declarations.h"

using namespace std;

void CreateMapOfActions(ActionMap* InputActionMapP)
{
	InputActionMapP->LoadActionToMap(1, "TRAVEL");
	InputActionMapP->LoadActionToMap(1, "T");
	InputActionMapP->LoadActionToMap(1, "MOVE");

	InputActionMapP->LoadActionToMap(2, "HELP");
	InputActionMapP->LoadActionToMap(2, "CONTROLS");

	InputActionMapP->LoadActionToMap(3, "LOOKAROUND");
	InputActionMapP->LoadActionToMap(3, "LA");
	InputActionMapP->LoadActionToMap(3, "LOCATION");

	InputActionMapP->LoadActionToMap(4, "LOOKOBJECT");
	InputActionMapP->LoadActionToMap(4, "LOOKATOBJECT");
	InputActionMapP->LoadActionToMap(4, "LO");

	InputActionMapP->LoadActionToMap(5, "USEOBJECT");
	InputActionMapP->LoadActionToMap(5, "UO");

	InputActionMapP->LoadActionToMap(6, "OBJECTS");
	InputActionMapP->LoadActionToMap(6, "LOCATIONOBJECTS");


	//Invalid action = 0
	//move to another area = 1

	/*ActionMapClass::ActionMap["TRAVEL"] = 1;
	ActionMapClass::ActionMap["GOTO"] = 1;
	ActionMapClass::ActionMap["MOVETO"] = 1;
	ActionMapClass::ActionMap["WALK"] = 1;
	ActionMapClass::ActionMap["PROCEED"] = 1;
	ActionMapClass::ActionMap["MOVE"] = 1;

	ActionMapClass::ActionMap["HELP"] = 2;

	ActionMapClass::ActionMap["LOOK"] = 3;
	ActionMapClass::ActionMap["LOOKAROUND"] = 3;*/
}

void DisplayHelp()
{
	cout << "List of actions you can do, actions are not case sensitive and you can use abbreviations and some synonyms" << endl << endl

		 << "-Help- (H)" << endl << "Displays this" << endl << endl

	     << "-Travel- (T)" << endl << "Move to another area" << endl << endl

		 << "-ObjectList- (OL)" << endl <<"Prints a list of objects in the current location" << endl << endl

	     << "-LookAround- (LA)" << endl << "Take a look around your current location" << endl << endl

	     << "-UseObject- (UO)" << endl << "Attempt to use an object" << endl << endl

	     << "-LookObject- (LO)" << endl << "Look at an object" << endl << endl;
}

void DisplayObjectsInLocation(Navigator* InputNavigator)
{
	Location tempLoc = InputNavigator->CurrentLocation;
	std::map<std::string, WorldObject*> tempMap = tempLoc.ObjectMap;
	std::map<std::string, WorldObject*>::iterator it = tempMap.begin();

	for (it; it != tempMap.end(); ++it)
	{
		std::cout << it->second->ObjectName << endl;
	}
}

void DisplayLocationDescription(Navigator* InputNavigator)
{

	cout << "current location:" << endl;
	cout << InputNavigator->CurrentLocation.LocationDescription << endl << endl;
}

void LookAtObject( Navigator* InputNavigator)
{
	std::string tempString;

	cout << "what are you looking at?" << endl << endl;
	cin >> tempString;

	transform(tempString.begin(), tempString.end(), tempString.begin(), toupper); 

	cout << InputNavigator->CurrentLocation.FindObjectInLocation(tempString)->LookMessage << endl;
}

void UseObject(Navigator* InputNavigator)
{
	std::string tempString;
	WorldObject* tempObjectP;
	Exit* tempExitP; 

	cout << "what are you trying to use?" << endl << endl;
	cin >> tempString;

	transform(tempString.begin(), tempString.end(), tempString.begin(), toupper); 

	tempObjectP = InputNavigator->CurrentLocation.FindObjectInLocation(tempString);
	tempExitP = InputNavigator->CurrentLocation.ExitMap[tempObjectP->AffectedExitDirection];

	if (tempObjectP->IsDefault == false)
	{
		tempObjectP->ExitChangeFunction(tempExitP);

	}






	//cout << InputNavigator->CurrentLocation.ExitMap[tempObject->AffectedExitDirection]->BlockedMessage;

	//tempObject->ExitChangeFunction(tempExit);

	//tempExit = InputNavigator->CurrentLocation.ExitMap[tempObject->AffectedExitDirection];

	//tempObject->UseFunction(InputNavigator->CurrentLocation.ExitMap[tempObject->AffectedExitDirection], tempObject->OpenExit);
}


void EnterAction(ActionMap* InputActionMapP, Navigator* InputNavigator, LocationMap* InputLocationMap)
{
	string Action;

	std::cout << "What do you want to do?" << endl;
	cin >> Action;
	transform(Action.begin(), Action.end(), Action.begin(), toupper);

	switch (InputActionMapP->Map[Action])
	{
	case 1:
		cout << "moving now" << endl;
		PickDirection(InputNavigator, InputLocationMap);

		break;

	case 2:
		DisplayHelp();

		break;

	case 3:
		DisplayLocationDescription(InputNavigator);

		break;

	case 4:
		LookAtObject(InputNavigator);

		break;

	case 5:
		UseObject(InputNavigator);
		break;

	case 6:
		DisplayObjectsInLocation(InputNavigator);
		break;

	default:
		cout << "Not a valid action, enter again" << endl << endl;
		//EnterAction(InputActionMapP);

	}

	EnterAction(InputActionMapP, InputNavigator, InputLocationMap);
}


