#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include "Travel_Declarations.h"
#include "Action_Declarations.h" 
#include "Locations_Declarations.h"

using namespace std;

void PickDirection(Navigator* InputNavigator, LocationMap* InputLocationMap)
{
	char Direction;
	cout << "enter a direction (N,E,S,W), B to cancel" << endl;
	cin >> Direction;

	InputNavigator->CurrentLocation = InputLocationMap->LocationMap["cave"];

	switch (toupper(Direction))
	{
	case 'N':
		cout << "north";
		break;

	case 'E':
		cout << "east";
		break;

	case 'S':
		cout << "south";
		break;

	case 'W':
		cout << "west";
		break;

	case 'B':
		cout << "west";
		break;

	default:
		cout << "Not a valid direction, enter again";
		PickDirection(InputNavigator, InputLocationMap); 

	}
}