#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <map>
#include "Action_Declarations.h"
#include "Travel_Declarations.h"
#include "Locations_Declarations.h"

using namespace std;

void CreateMapOfActions(ActionMap* InputActionMapP)
{
	InputActionMapP->LoadActionToMap(1, "TRAVEL");
	InputActionMapP->LoadActionToMap(2, "HELP");
	InputActionMapP->LoadActionToMap(3, "LOOKAROUND");


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
	cout << "List of actions you can do, actions are not case sensitive" << endl

		 << "-Travel- to move to another area" << endl << endl;
}

void DisplayLocationDescription(Navigator* InputNavigator)
{

	cout << "current location:" << endl;
	cout << InputNavigator->CurrentLocation.LocationDescription << endl << endl;
}

void Testing(LocationMap* InputLocationMap)
{

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
		EnterAction(InputActionMapP, InputNavigator, InputLocationMap);
		break;

	case 2:
		DisplayHelp();
		EnterAction(InputActionMapP, InputNavigator, InputLocationMap);
		break;

	case 3:
		DisplayLocationDescription(InputNavigator);
		EnterAction(InputActionMapP, InputNavigator, InputLocationMap);
		break;

	default:
		cout << "Not a valid action, enter again" << endl << endl;
		//EnterAction(InputActionMapP);

	}

	EnterAction(InputActionMapP, InputNavigator, InputLocationMap);
}


