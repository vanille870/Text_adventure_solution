#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <map>
#include "Action_Declarations.h"
#include "Travel_Declarations.h"
#include "Locations_Declarations.h"
#include "WorldObjects_Declarations.h"
#include "Inventory_Deca.h"

using namespace std;

template <typename T>
void PrintList (T ObjectType)
{
	auto tempObject = ObjectType; 
	auto tempMap = ObjectType->Map;
	auto it = tempMap.begin(); 

	for (const auto& it : tempMap)
	{
		std::cout << it.second->Name << endl; 
	}
};


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
	InputActionMapP->LoadActionToMap(6, "OBJECTLIST");
	InputActionMapP->LoadActionToMap(6, "OL");

	InputActionMapP->LoadActionToMap(7, "INVENTORY");
	InputActionMapP->LoadActionToMap(7, "INV");

	InputActionMapP->LoadActionToMap(8, "DROP");
	InputActionMapP->LoadActionToMap(8, "DROPITEM");
	InputActionMapP->LoadActionToMap(8, "DI");

	InputActionMapP->LoadActionToMap(9, "CHECKITEM");
	InputActionMapP->LoadActionToMap(9, "CI");
	InputActionMapP->LoadActionToMap(9, "CHECKINVENTORY");
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

void DisplayLocationDescription(Navigator* InputNavigator)
{

	cout << "current location:" << endl;
	cout << InputNavigator->CurrentLocation.LocationDescription << endl << endl;
}

void LookAtObject(Navigator* InputNavigator)
{
	std::string tempString;

	cout << "what are you looking at?" << endl << endl;
	cin >> tempString;

	transform(tempString.begin(), tempString.end(), tempString.begin(), toupper); 

	cout << InputNavigator->CurrentLocation.FindObjectInLocation(tempString)->LookMessage << endl;
}

void UseObject(Navigator* InputNavigator, Inventory* InputInventory)
{
	std::string tempString; 
	WorldObject* tempObjectP;

	cout << "what are you trying to use?" << endl << endl;
	cin >> tempString;

	transform(tempString.begin(), tempString.end(), tempString.begin(), toupper); 

	tempObjectP = InputNavigator->CurrentLocation.FindObjectInLocation(tempString);

	if (tempObjectP->ObjectType != "Default")
	{
		if (tempObjectP->ObjectType == "Exit")
		{ 
			Exit* tempExitP;  
			tempExitP = InputNavigator->CurrentLocation.ExitMap[tempObjectP->AffectedExitDirection];  
			tempObjectP->ExitChangeFunction(tempExitP);  
		}

		if (tempObjectP->ObjectType == "Item")
		{
			tempObjectP->PickUpObject(InputInventory);
		}
	}


	//cout << InputNavigator->CurrentLocation.ExitMap[tempObject->AffectedExitDirection]->BlockedMessage;

	//tempObject->ExitChangeFunction(tempExit);

	//tempExit = InputNavigator->CurrentLocation.ExitMap[tempObject->AffectedExitDirection];

	//tempObject->UseFunction(InputNavigator->CurrentLocation.ExitMap[tempObject->AffectedExitDirection], tempObject->OpenExit);
}

void DropObject(Inventory* inputInvntory, Navigator* inputNavigator)
{
	std::string tempString;
	InventoryItem* tempItem;

	cout << "what are you dropping?" << endl << endl;
	cin >> tempString; 
	 
	transform(tempString.begin(), tempString.end(), tempString.begin(), toupper); 

	tempItem = inputInvntory->FindItemInInventory(tempString);

	if (tempItem->Name == "DEFAULT")
	{
		//Do nothing
	}

	else
	{
		inputInvntory->Map.erase(tempString);
		inputNavigator->CurrentLocation.AddInventoryObject(tempItem->Name, tempItem->CheckMessage);
		std::cout << "You drop the " << tempString << " on the ground" << std::endl << endl;  
	}
}

void CheckInvntoryItem(Inventory* inputInventory)
{
	std::string tempString;
	InventoryItem* tempItem;

	cout << "what are you checking?" << endl << endl;
	cin >> tempString; 

	transform(tempString.begin(), tempString.end(), tempString.begin(), toupper); 

	tempItem = inputInventory->FindItemInInventory(tempString);  

	cout << tempItem->CheckMessage << endl << endl; 
}



void EnterAction(ActionMap* InputActionMapP, Navigator* InputNavigator, LocationMap* InputLocationMap, Inventory* InputPlayerInventory)
{
	bool GameRunning = true;
	string Action;

	while (GameRunning == true)
	{
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
			UseObject(InputNavigator, InputPlayerInventory);
			break;

		case 6:
			PrintList(&InputNavigator->CurrentLocation);  
			break;

		case 7:
			PrintList(InputPlayerInventory);
			break;

		case 8:
			DropObject(InputPlayerInventory, InputNavigator);
				break;

		case 9:
			CheckInvntoryItem(InputPlayerInventory); 
			break;

		default:
			cout << "Not a valid action, enter again" << endl << endl;
			//EnterAction(InputActionMapP);

		}
	}
}


